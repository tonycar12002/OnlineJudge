#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Query {
public:
  string name;
  int number;
  Query* next_phone;
  Query():number(-1), name(""), next_phone(NULL){}
  Query(string n, int num):name(n), number(num), next_phone(NULL){}
  ~Query(){delete next_phone;}
};

class PhoneBook{
private:
  int a = 1;
  int b = 0;
  int prime = 1000003;
  int hash_size = 1000 ;
  Query *queries;
  vector<string> ans;

public:
  PhoneBook(){queries = new Query[hash_size];}
  ~PhoneBook(){delete[] queries;}

  int hashFunction(int num){
    long long int tmp = (num * a + b) % prime;
    tmp = num % hash_size;
    return tmp;
  }

  void insertBook(string name, int number){
    int hash_value = hashFunction(number);
    bool find = false;    
    Query *que = &queries[hash_value];
    Query *next = que->next_phone;

    while(next){
      if(next -> number == number){
        find = true;
        next -> name = name;
        return;
      }
      else{
        que = next;
        next = que -> next_phone;
      }
     
    }
    if(!find){
      que -> next_phone = new Query(name, number);
    }
  }

  string findBook(int number){
    int hash_value = hashFunction(number);
    bool find = false;
    Query *que = queries[hash_value].next_phone;
    while(que){
      
      if(que -> number == number){
        return que->name;
      }
      else{
        que = que -> next_phone;
      }
    }    
    return "not found";
  }

  void deleteBook(int number){
    int hash_value = hashFunction(number);
    Query *que = &queries[hash_value];
    Query *next = queries[hash_value].next_phone;

    while(next){
      if (next -> number == number){
        que -> next_phone = next -> next_phone;
        return;
      }
      else{
        que = next;
        next = que -> next_phone;
      }
    }
    
  }
  void readData(){
    int n;
    cin >> n ;
    string type, name;
    int number;
    for (int i = 0 ; i < n ;  i++){
      cin >> type >> number;
      if (type == "add"){
        cin >>  name;
        insertBook(name, number);
      }
      else if(type == "del"){
        deleteBook(number);
      }
      else if(type == "find"){
        ans.push_back(findBook(number));
        //cout << findBook(number) << endl;
      }
    }
  
    for (int i=0;i<ans.size();i++)
      cout << ans[i] << endl;
  }
  

};

int main() {
  PhoneBook phone_book;
  phone_book.readData();

  return 0;
}
