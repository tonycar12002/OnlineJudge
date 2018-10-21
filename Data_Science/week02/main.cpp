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
#include <map>
#include <list>
using namespace std;
class Node{
public:
    short int item;
    int counts;
    Node* next_item = NULL; 
    vector<Node*> children;
    Node* parent = NULL;

    Node():counts(0), item(-1){}
    Node(short int itm):item(itm), counts(0){}
    Node(short int itm, int cnts):item(itm), counts(cnts){}
    Node(short int itm, int cnts, Node* next):item(itm), counts(cnts), next_item(next){}
    friend ostream &operator<<(ostream&, const Node&);
    ~Node(){}

};
ostream &operator<<(ostream &os, const Node& node){
    return os << "item = " << node.item << " counts = " << node.counts ;
}   
struct compBySet{
    bool operator()(const set<short int> &s1, const set<short int> &s2){
        set<short int>::iterator it_1 = s1.begin();
        set<short int>::iterator it_2 = s2.begin();
        if(s1.size() < s2.size())
            return true;
        else if (s1.size() > s2.size()){
            return false;
        }
        else{
            while(it_1 != s1.end()){
                if(*it_1 > *it_2)
                    return false;
                else if(*it_1 < *it_2)
                    return true;
                it_1++;
                it_2++;
            }
        }
    }
};
map<set<short int>, int, compBySet>all_combination;
map<set<short int>, int>::iterator iter;
int nme = 0;
class FPTree{
public:
    vector < vector<short int> > transaction_list;
    static int number_counts[1000];
    int transaction_list_length;
    double min_support_line;
    int thread_num; 

    vector<Node>header_table;
    Node* record_header_link[1000];
    Node* root;

    set<short int>base_combination;

public:
    FPTree(){}
    FPTree(double min_sp_line):min_support_line(min_sp_line){}
    FPTree(double min_sp_line, set<short int>base):min_support_line(min_sp_line),base_combination(base){}
    ~FPTree(){}

    void fpGrowth(Node* node, set<short int> combination_set, int num){
        if (!node)
            return;
        combination_set.insert(node->item);
        all_combination[combination_set] += num;
        
        while(node->parent->item != -1){
            fpGrowth(node->parent, combination_set, num);
            node = node->parent;
        }
    }


    void conditionPattern(Node* condition_node){
        // Create pattern conditional tree
        FPTree subtree(min_support_line, base_combination);
        bool tree_done = false;
        
        // Add Header Table Line
        vector<short int> first_line;
        for(short int i=0;i<=999;i++){
            number_counts[i] = 0;
            first_line.push_back(i);
        }
        subtree.transaction_list.push_back(first_line);

        
        subtree.base_combination.insert(condition_node->item);

        while(condition_node){
            all_combination[subtree.base_combination] += condition_node -> counts;
            Node* tmp = condition_node->parent;
            int c = condition_node->counts;

            while(c--){
                vector<short int> transaction;
                tmp = condition_node->parent;
                while(tmp->parent){
                    transaction.push_back(tmp->item);
                    subtree.number_counts[tmp->item] += 1;
                    tmp = tmp ->parent;
                }
                subtree.transaction_list.push_back(transaction);
            }
            condition_node = condition_node->next_item;
        }
        
        subtree.transaction_list_length = subtree.transaction_list.size() - 1;

        subtree.preprocessTransactionList();
        subtree.buildTree();

        //string name = to_string(  nme++ );
        //subtree.plotTree(name);

        if(subtree.checkTreeBranch(subtree.root) == 1){
            clock_t t_start = clock();
            
            set<short int>combination_set = subtree.base_combination;

            for(short int i=subtree.header_table.size()-1 ; i>=0 ;i--){
                if(subtree.header_table[i].next_item){
                    fpGrowth(subtree.header_table[i].next_item, combination_set, subtree.header_table[i].next_item->counts);
                }
            }

            //cout << "mining time taken = "<< (double)(clock()-t_start)/(double)CLOCKS_PER_SEC << endl;
        }
        else{
            subtree.mineTree();
        }
        deleteNode(subtree.root);
    }

    int checkTreeBranch(Node* node){
        while(node->children.size() > 0){
            if(node->children.size() > 1){
                return 0;
            }
            node = node->children[0];
        }
        return 1;
    }
    void mineTree(){
        // run all header table link to create subtree
        for(short int i=header_table.size()-1 ; i>=0 ;i-= 1){
            if (header_table[i].next_item){
                conditionPattern(header_table[i].next_item);
            }
        }
    }
    void saveFIle(char* output_file){ 
        ofstream  outfile(output_file);
        for(auto  it = all_combination.begin(); it != all_combination.end(); ++it)
        {
            for (short int const& i : it->first){
                if(i == *(it->first.begin()) )
                    outfile << i ;
                else
                    outfile <<","<< i ;
            }
            int c = (double)it->second/transaction_list_length*1000;
            outfile << ":" << (double)c/1000<< endl;
        }
    }
    
    void deleteNode(Node* node){
        if (!node)
            return;
        for(short int i=0;i<node->children.size();i++){
            deleteNode(node->children[i]);
        }
        free(node);
    }

    void buildTree(){
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

        root = new Node(-1, -1);

        /*        
        ofstream  outfile("plotTree.txt");
        for(int i=1;i<=transaction_list_length;i++){
            for(int g=0;g<transaction_list[i].size();g++){
                outfile << transaction_list[i][g] << " ";
            }
            outfile << endl;
        }
        */

        // Build fp tree
        for(int i=1;i<=transaction_list_length;i++){
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
        //plotTree();

    }

    void plotTree(string name){
        ofstream  outfile(name + ".txt");
        double x = 0.0;
        for(short int i=0;i<header_table.size();i++){
            Node* node = header_table[i].next_item;
            Node* trace = header_table[i].next_item;
            while(node){
                if(node->children.size() == 0){
                    trace = node;
                    while(trace->parent){
                        outfile << *trace << " | ";
                        //x+= (double)sizeof(Node) * (double)trace->children.size()/1024/1024;
                        trace = trace->parent;
                    }
                    outfile << endl;
                }    
                //outfile << x <<" MB|| ";            
                node = node->next_item;
            }
            
        }
    }

    short int max(short int a, short int b){
        if (a>=b)
            return a;
        else 
            return b;
    }
    void insert(std::vector<short int> transaction){
        Node* now_node = root;
        short int index;
        short int i = 0, item = -1;
        bool already_not_found = false;

        while( i<transaction.size() ){
            item = transaction[i];
            //cout << item  << " "; 
            if(already_not_found){
                now_node -> children.push_back(new Node(item, 1));

                record_header_link[item]->next_item = now_node -> children.back();

                now_node->children.back()->parent = now_node;
                now_node = now_node -> children.back();
                record_header_link[item] = now_node;
            }
            else{  
                
                //index = findItem(now_node->children, item);
                index = -1;
                if (now_node->children.size()!=0 && now_node->children.back()->item == item){
                    index = now_node->children.size()-1;
                }   
        
                // Not found
                if(index == -1){
                    already_not_found = true;
                    now_node -> children.push_back(new Node(item, 1));

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
        //cout << endl;
    }

    short int findItem(vector<Node*> children, short int target_item){
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

    void readFile(char* input_file, double min_sup){
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
                    //cout << num << endl;
                    num = 0;
                }
            }
            //cout << num << "==="<< endl;
            if(num!=0){
                transaction.push_back(num);
                number_counts[num] ++;
            }
            
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
        min_support_line = (double)transaction_list_length * min_sup;
    }

    void sortMultiThread(int now_thread){
        
        for (int i = now_thread ; i<= transaction_list_length ; i+=thread_num){
            if (transaction_list[i].size()>1)
                transaction_list[i] = mergeSort(transaction_list[i]);
            short int end = transaction_list[i].size()-1;
            while( end >=0 && (double)number_counts[ transaction_list[i][end] ] < min_support_line){
                end --;
                transaction_list[i].pop_back();
            }
        }  
        return;
    }

    static bool transactionCompare(const vector<short int>& a, const vector<short int>& b){
        int i = 0;
        while(i < a.size() && i < b.size() ){
            if(number_counts[a[i]] > number_counts[b[i]])
                return true;
            else if ( number_counts[a[i]] < number_counts[b[i]] )
                return false;
            else if ( number_counts[a[i]] == number_counts[b[i]] ){
                if( a[i] > b[i]){
                    return true;
                }
                else if (a[i] < b[i])
                    return false;
                else
                    i++;
            }
        }
        if(a.size() >= b.size())
            return false;
        else
            return true;
    }

    void preprocessTransactionList(){
        /* 
        ==========================================================
            Sort the value and remove min_suppport
            First line is for header table, not real data
        ==========================================================
        */

        thread_num = std::thread::hardware_concurrency()-1;
        thread *t = new thread [thread_num];
        
        for(int i=0;i<thread_num;i++){
            t[i] = thread(&FPTree::sortMultiThread, this, i);
        }
        
        for(int i=0;i<thread_num;i++){
            t[i].join();
        } 

        // One thread sort
        /*
        for (int i = 0 ; i<= transaction_list_length ; i+=1){
            if(transaction_list[i].size()>1)
                transaction_list[i] = mergeSort(transaction_list[i]);
            short int end = transaction_list[i].size()-1;
            while( end >=0 && (double)number_counts[ transaction_list[i][end] ]/transaction_list_length < min_support){
                end --;
                transaction_list[i].pop_back();
            }
        } */
        
        std::sort(transaction_list.begin()+1, transaction_list.end(), transactionCompare);

        // print all lines to txt
        /*
        ofstream outfile("sort_multi.txt");
        for (int i = 1 ; i<= transaction_list_length ; i++){
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

    vector<short int>copyVector(vector<short int> element, short int start, short int end){
        vector<short int> result;
        for(short int i = start ; i <=end ; i++)
            result.push_back(element[i]);
        return result;
    }

    vector<short int> combineVector(vector<short int> num_1, vector<short int> num_2){
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

    vector<short int> mergeSort(vector<short int> transaction){
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

        vector<short int>left = mergeSort(copyVector(transaction, 0, mid-1));
        vector<short int>right = mergeSort(copyVector(transaction, mid, size-1));
        vector<short int>combine = combineVector(left, right);

        return combine;
    }


};
int FPTree::number_counts[1000]={0};
int main(int argc, char* argv[]){
    clock_t t_start = clock();

    double min_support = atof(argv[1]);
    char* input_file = argv[2];
    char* output_file = argv[3];

    // Build FP Tree
    FPTree fptree;
    fptree.readFile(input_file, min_support);
    cout << "Read file done" << endl;
    fptree.preprocessTransactionList();
    cout << "Sort done" << endl;
    fptree.buildTree();
    cout << "Build fp tree done" << endl;
    fptree.mineTree();
    cout << "Mine tree done" << endl;
    fptree.saveFIle(output_file);
    cout << "Save file done" << endl;

    // Find all combination and save file
    //fptree.saveFIle(output_file);
    
    cout << "time taken = "<< (double)(clock()-t_start)/CLOCKS_PER_SEC << endl;
    return 0;
}