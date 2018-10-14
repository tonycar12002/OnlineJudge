#include <iostream>
#include <cstdio>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <set>
#include <thread>
#include <mutex>

using namespace std;



class Node{
public:
    short int item;
    int counts;
    Node* next_item = NULL; 
    vector<Node*> children;
    Node* parent = NULL;
    short int height;

    Node():counts(0), item(-1){}
    Node(short int itm):item(itm), counts(0), height(0){}
    Node(short int itm, int cnts):item(itm), counts(cnts), height(0){}
    Node(short int itm, int cnts, short int height):item(itm), counts(cnts), height(height){}
    Node(short int itm, int cnts, Node* next):item(itm), counts(cnts), next_item(next){}
    friend ostream &operator<<(ostream&, const Node&);
    ~Node(){}

};
ostream &operator<<(ostream &os, const Node& node){
    return os << "item = " << node.item << " counts = " << node.counts << " height = " << node.height ;
}   
class FPTree{
private:
    vector < vector<short int> > transaction_list;
    int number_counts[1000];
    int transaction_list_length;
    double min_support;
    int thread_num;

    vector<Node>header_table;
    Node* record_header_link[1000];

    Node* root;

public:
    FPTree(){}
    FPTree(double min_sp):min_support(min_sp){}
    ~FPTree(){}

    void fp_growth(){

    }
    void save_file(char* output_file){
       
    }
    void build_tree(){
        /* 
        ==========================================================
            Build FP Tree and Heade table
        ==========================================================
        */

       // Build header table
        for(short int i=0;i<1000;i++){
            record_header_link[i] = new Node(-1, -1);
        }

       for(short int i=0;i<transaction_list[0].size();i++){
           header_table.push_back( Node(transaction_list[0][i], number_counts[transaction_list[0][i]], record_header_link[transaction_list[0][i]]) );
       }

       // Plot header table
       /*
       for(int i=0;i<header_table.size();i++){
           cout << header_table[i] << endl;
       }*/

        root = new Node(-1, 0);

        // Build fp tree
        
        for(int i=1;i<=200000;i++){
            insert(transaction_list[i]);
            transaction_list[i].clear();
            transaction_list[i].shrink_to_fit();
        }

        /*
       for(int i=0;i<header_table.size();i++){
           cout << header_table[i] << endl;
       }*/

        // link header Table to fp tree
        for(short int i=0;i<header_table.size();i++){
            header_table[i].next_item = header_table[i].next_item->next_item;
        }

        //Plot Tree by header table
        plot_tree();

    }
    void plot_tree(){
        ofstream  outfile("plot_tree.txt");
        double x = 0.0;
        for(short int i=0;i<header_table.size();i++){
            Node* node = header_table[i].next_item;
            Node* trace = header_table[i].next_item;
            while(node){
                if(node->children.size() == 0){
                    trace = node;
                    while(trace->parent){
                        //outfile << *trace << " | ";
                        x+= (double)sizeof(Node) * (double)trace->children.size()/1024/1024;
                        trace = trace->parent;
                    }
                    //outfile << endl;
                }    
                outfile << x <<" MB|| ";            
                node = node->next_item;
            }
            
        }
    }

    void insert(std::vector<short int> transaction){
        Node* now_node = root;
        short int index;
        short int i = 0, item;
        bool already_not_found = false;

        while( i<transaction.size() ){
            item = transaction[i];
            if(already_not_found){
                now_node -> children.push_back(new Node(item, 1, now_node->height+1));

                record_header_link[item]->next_item = now_node -> children.back();

                now_node->children.back()->parent = now_node;
                now_node = now_node -> children.back();
                record_header_link[item] = now_node;
            }
            else{  
                index = find_item(now_node->children, item);
                // Not found
                if(index == -1){
                    already_not_found = true;
                    now_node -> children.push_back(new Node(item, 1, now_node->height+1));

                    record_header_link[item]->next_item = now_node -> children.back();

                    now_node->children.back()->parent = now_node;
                    now_node = now_node -> children.back();
                    record_header_link[item] = now_node;
                }
                else{
                    now_node = now_node->children[index];
                    now_node->counts += 1;
                   
                }
            }
             i++;
        }
    }

    short int find_item(vector<Node*> children, short int target_item){
        /* 
        ==========================================================
            Find the position of target number in vector
        ==========================================================
        */ 
        for(short int i=0;i<children.size();i++){
            if(children[i]->item == target_item){
                return i;
            }
        }
        return -1;
    }

    void read_file(char* input_file){
        /* 
        ==========================================================
            Read file from input file
        ==========================================================
        */        
        ifstream fin(input_file);
        string input_string;
        string number_string;
        short int num;

        // Add Header Table Line
        vector<short int> first_line;
        for(short int i=0;i<=999;i++){
            number_counts[i] = 0;
            first_line.push_back(i);
        }
        transaction_list.push_back(first_line);
        int counts = 0;
        // Read input file
        while(getline(fin, input_string)){
            //cout << counts++ << endl;
            
            vector<short int> transaction;
            
            num = 0;
            for(int i=0;i<input_string.size();i++){
                if( input_string[i]>='0' && input_string[i]<='9'){
                    num = num*10 + (int)input_string[i]-48;
                }
                else{
                    transaction.push_back(num);
                     number_counts[num] ++;
                    num = 0;
                }
            }
            transaction.push_back(num);
            number_counts[num] ++;
            /* much slower
            istringstream ssline(input_string);
            while(getline(ssline, number_string, ',')){
                num = atoi(number_string.c_str());
                number_counts[num] ++;
                transaction.push_back(num);
            }*/

            transaction_list.push_back(transaction);
        }
        transaction_list_length = transaction_list.size() - 1;
    }

    void sort_multi_thread(int now_thread){
        
        for (int i = now_thread ; i<= transaction_list_length ; i+=thread_num){
            //cout << i << endl;
            transaction_list[i] = merge_sort(transaction_list[i]);
            short int end = transaction_list[i].size()-1;
            while( end >=0 && (double)number_counts[ transaction_list[i][end] ]/transaction_list_length < min_support){
                end --;
                transaction_list[i].pop_back();
            }
        }   
        return;
    }
    void preprocess_transaction_list(){
        /* 
        ==========================================================
            Sort the value and remove min_suppport
            First line is for header table, not real data
        ==========================================================
        */

        
        thread_num = std::thread::hardware_concurrency()-1;
        thread *t = new thread [thread_num];

        for(int i=0;i<thread_num;i++){
            t[i] = thread(&FPTree::sort_multi_thread, this, i);
        }
        for(int i=0;i<thread_num;i++){
            t[i].join();
        }  
        delete t;

        // One thread sort
        /*
        for (int i = 0 ; i<= transaction_list_length ; i+=1){
            //cout << i << endl;
            transaction_list[i] = merge_sort(transaction_list[i]);

            short int end = transaction_list[i].size()-1;
            while( end >=0 && (double)number_counts[ transaction_list[i][end] ]/transaction_list_length < min_support){
                end --;
                transaction_list[i].pop_back();
            }
        } */  

        // print all lines to txt
        /*
        ofstream outfile("sort_multi.txt");
        for (int i = 0 ; i<= transaction_list_length ; i++){
            outfile << "index = " << i << " = ";
            for(int g=0;g<transaction_list[i].size();g++){
                outfile << transaction_list[i][g] << " " ;
            }
            outfile <<endl;
        }*/
        

        /*
        for(int i=0;i<=50;i++){
            cout << (double)number_counts[i]/transaction_list_length << " ";
        }     
        cout << endl;   */

    }

    vector<short int>copy_vector(vector<short int> element, short int start, short int end){
        vector<short int> result;
        for(short int i = start ; i <=end ; i++)
            result.push_back(element[i]);
        return result;
    }

    vector<short int> combine_vector(vector<short int> num_1, vector<short int> num_2){
        vector<short int>result;
        short int n=0, num_1_index=0, num_2_index=0;
        while(n<num_1.size()+num_2.size()){
            if(num_1_index < num_1.size() && num_2_index < num_2.size()){
                if( number_counts[ num_1[num_1_index] ] == number_counts[ num_2[num_2_index] ]){
                    if(num_1[num_1_index] < num_2[num_2_index]){
                        result.push_back(num_2[num_2_index]);
                        num_2_index++;                        
                    }
                    else{
                        result.push_back(num_1[num_1_index]);
                        num_1_index++;  
                    }
                }
                else if( number_counts[ num_1[num_1_index] ] < number_counts[ num_2[num_2_index] ]){
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

    vector<short int> merge_sort(vector<short int> transaction){
        /* 
        ==========================================================
            Sort the value
        ==========================================================
        */
        short int size = transaction.size();
        if (size == 1){
            return transaction;
        }
        short int mid = size / 2;

        vector<short int>left = merge_sort(copy_vector(transaction, 0, mid-1));
        vector<short int>right = merge_sort(copy_vector(transaction, mid, size-1));
        vector<short int>combine = combine_vector(left, right);

        return combine;
    }


};

int main(int argc, char* argv[]){
    clock_t t_start = clock();

    double min_support = atof(argv[1]);
    char* input_file = argv[2];
    char* output_file = argv[3];

    // Build FP Tree
    FPTree fptree(min_support);
    fptree.read_file(input_file);
    cout << "Read file done" << endl;
    fptree.preprocess_transaction_list();
    cout << "Sort done" << endl;
    fptree.build_tree();
    cout << "Build fp tree done" << endl;
    
    // Find all combination and save file
    //fptree.save_file(output_file);
    
    cout << "time taken = "<< (double)(clock()-t_start)/CLOCKS_PER_SEC << endl;
    return 0;
}