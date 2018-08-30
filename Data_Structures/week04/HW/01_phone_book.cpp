#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Query {
private:
    string name;
    int number;
    Query* next_phone;
public:
  Query():next_phone(NULL){}
};

class PhoneBook{
private:
  int a = 34;
  int b = 2;
  int prime = 1000003;
  int hash_size = 1000 ;
  Query *queries;

public:
  PhoneBook(){queries = new Query[hash_size];}
  ~PhoneBook(){delete queries;}

  int hashFunction(int num){
    long long int tmp = (num * a + b) % prime;
    tmp = num % hash_size;
    return tmp;
  }

  void insertBook(string name, int number){
    int hash_value = hashFunction(number);
    Query que = queries[hash_value];
    while(que){
      
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

      }
      else if(type == "find"){

      }

    }
  }

};

int main() {
  PhoneBook phone_book;
  phone_book.readData();

  return 0;
}
