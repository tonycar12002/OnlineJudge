#include <iostream>
#include <cstdio>
#include <sstream>
#include <string.h>
#include <boost/iostreams/device/mapped_file.hpp> 
#include <algorithm>
#include <time.h>
#include<fstream>

using namespace std;
class Node{
public:
    int item;
    int counts;
    Node* next_item = NULL;
    vector<Node*> children;

    Node():counts(0){}
    Node(int itm):item(itm), counts(0){}
    Node(int itm, int cnts):item(itm), counts(cnts){}
    friend ostream &operator<<(ostream &os, const Node& node){
        return os << "item = " << node.item << " counts = " << node.counts ;
    }
    ~Node(){}

};

class FPTree{
private:
    vector < vector<int> > transaction_list;
    int number_counts[1000]={0};
    int transaction_list_length;
    double min_support;

    vector<Node>header_table;
    Node* root;

public:
    FPTree(){}
    FPTree(double min_sp):min_support(min_sp){}
    ~FPTree(){}

    void build_tree(){
       // Build header table
       for(int i=0;i<transaction_list[0].size();i++){
           header_table.push_back( Node(transaction_list[0][i], number_counts[transaction_list[0][i]]) );
       }
       /*
       for(int i=0;i<header_table.size();i++){
           cout << header_table[i] << endl;
       }*/

        root = new Node(-1, 0);

        // Build fp tree
        for(int i=1;i<=transaction_list_length;i++){
            
        }

    }

    void read_file(char* input_file){
        
        ifstream fin(input_file);
        string input_string;
        string number_string;
        int num;

        // Add Header Table Line
        vector<int> first_line;
        for(int i=0;i<=999;i++){
            first_line.push_back(i);
        }
        transaction_list.push_back(first_line);

        // Read input file
        while(getline(fin, input_string)){

            istringstream ssline(input_string);
            vector<int> transaction;
            while(getline(ssline, number_string, ',')){
                num = atoi(number_string.c_str());
                number_counts[num] ++;
                transaction.push_back(num);
            }
            transaction_list.push_back(transaction);
        }
        transaction_list_length = transaction_list.size() - 1;
    }

    void preprocess_transaction_list(){
        // Sort the value and remove min_suppport
        // First line is for header table, not real data
        for (int i = 0 ; i<= transaction_list_length ; i++){
            transaction_list[i] = merge_sort(transaction_list[i]);

            int end = transaction_list[i].size()-1;
            while( end >=0 && (double)number_counts[ transaction_list[i][end] ]/transaction_list_length < min_support){
                end --;
                transaction_list[i].pop_back();
            }
            
            /*
            cout << "index = " << i << " = ";
            for(int g=0;g<transaction_list[i].size();g++){
                cout << transaction_list[i][g] << " " ;
            }
            cout <<endl;*/
            
        }
        /*
        for(int i=0;i<=50;i++){
            cout << (double)number_counts[i]/transaction_list_length << " ";
        }     
        cout << endl;   */

    }

    vector<int>copy_vector(vector<int> element, int start, int end){
        vector<int> result;
        for(int i = start ; i <=end ; i++)
            result.push_back(element[i]);
        return result;
    }

    vector<int> combine_vector(vector<int> num_1, vector<int> num_2){
        vector<int>result;
        int n=0, num_1_index=0, num_2_index=0;
        while(n<num_1.size()+num_2.size()){
            if(num_1_index < num_1.size() && num_2_index < num_2.size()){
                if( number_counts[ num_1[num_1_index] ] <= number_counts[ num_2[num_2_index] ]){
                    result.push_back(num_2[num_2_index]);
                    num_2_index++;
                }
                else{
                    result.push_back(num_1[num_1_index]);
                    num_1_index++;			
                }
            }
            else if(num_1_index < num_1.size()){
                result.push_back(num_1[num_1_index]);
                num_1_index++;
            }
            else{
                result.push_back(num_2[num_2_index]);
                num_2_index++;
            }
            n++;
        }

        return result;
    }

    vector<int> merge_sort(vector<int> transaction){
        int size = transaction.size();
        if (size == 1){
            return transaction;
        }
        int mid = size / 2;

        vector<int>left = merge_sort(copy_vector(transaction, 0, mid-1));
        vector<int>right = merge_sort(copy_vector(transaction, mid, size-1));
        vector<int>combine = combine_vector(left, right);

        return combine;
    }


};

int main(int argc, char* argv[]){
    clock_t t_start = clock();

    double min_support = atof(argv[1]);
    char* input_file = argv[2];
    char* output_file = argv[3];

    FPTree fptree(min_support);
    fptree.read_file(input_file);
    fptree.preprocess_transaction_list();
    fptree.build_tree();
    
    
    cout << "time taken = "<< (clock()-t_start)/CLOCKS_PER_SEC << endl;
    return 0;
}