/* 
Hashing with liked list
large number mod will cause nagative number
-2 % 3 == -2 != 1%3 ==1
*/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
class Query {
public:
  string word;
  Query* next_string;
  Query():word(""), next_string(NULL){}
  Query(string n):word(n), next_string(NULL){}
  ~Query(){delete next_string;}
};

class HashingChains{
private:  
  int x = 263;
  long long int prime = 1000000007;
  int hash_size;
  Query *queries;
  vector<string> ans;

public:
  HashingChains(){}
  ~HashingChains(){delete[] queries;}

  int hashFunction(string word){
    long long int tmp = 0;
    for(int i=0;i<word.size();i++){
      long long int ascii = word[i];
      long long int pow_num = 1;
      for(int h = 0 ; h<i; h++)
        pow_num = pow_num * x % prime; 
      tmp = tmp + ascii * ( pow_num % prime )  ;
      tmp %= prime;
      
      //cout << ascii << " " << pow(x, i) << " " << prime  << " , tmp = " << tmp  << ", pow_num % prime = " <<( pow_num % prime ) << endl;
    }
    tmp = tmp % hash_size;
    //cout << tmp << endl;
    
    return tmp;
  }

  void insertChains(string word){
    int hash_value = hashFunction(word);
    //cout << hash_value << endl;
    bool find = false;    

    Query *que = &queries[hash_value];
    Query *next = que->next_string;

    while(next){
      if(next -> word == word){
        return;
      }
      else{
        que = next;
        next = que -> next_string;
      }
     
    }
    if(!find){
      que = queries[hash_value].next_string ;
      queries[hash_value].next_string = new Query(word);
      queries[hash_value].next_string -> next_string = que;
    }
  }

  string findChains(string word){
    int hash_value = hashFunction(word);
    bool find = false;
    Query *que = queries[hash_value].next_string;
    while(que){
      if(que -> word == word){
        return "yes";
      }
      else{
        que = que -> next_string;
      }
    }    
    return "no";
  }

  void deleteChains(string word){
    int hash_value = hashFunction(word);
  
    Query *que = &queries[hash_value];
    Query *next = queries[hash_value].next_string;

    while(next){
      if (next -> word == word){
        que -> next_string = next -> next_string;
        return;
      }
      else{
        que = next;
        next = que -> next_string;
      }
    }
  }

  string checkChains(string word){
    int hash_value = stoi(word);
    bool find = false;
    string all_words = "";
    Query *que = queries[hash_value].next_string;

    while(que){
        if(que == queries[hash_value].next_string ){
          all_words += que ->word ;
        }
        else{
          all_words += " " + que ->word ;
        }
        find = true;
        que = que -> next_string;
    }  
    if(!find){
      return "";
    }  
    else 
      return all_words;
  }

  void readData(){
    int n;
    cin >> hash_size >> n;
    queries = new Query [hash_size];
    string type, word;
    for (int i = 0 ; i < n ;  i++){
      cin >> type >> word;
      if (type == "add"){
        insertChains(word);
      }
      else if(type == "del"){
        deleteChains(word);
      }
      else if(type == "find"){
        ans.push_back(findChains(word));
      }
      else if(type == "check"){
        ans.push_back(checkChains(word));
      }
    }
  
    for (int i=0;i<ans.size();i++)
      cout << ans[i] << endl;
  }
  

};

int main() {
  HashingChains chains;
  chains.readData();

  return 0;
}
