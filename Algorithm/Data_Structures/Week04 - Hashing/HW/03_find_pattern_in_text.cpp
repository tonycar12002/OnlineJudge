//Rabin–Karp’s algorithm
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std ;

class FindPatternPos{
private:
    string pattern;
    string text;
    long long int x = 34;
    long long int mod = 10000003;
    long long int pow_pattern = 1;
    vector<int>location;

public:
    FindPatternPos(string p, string t):pattern(p), text(t){}
    ~FindPatternPos(){}

    long long int  calHashValue(string word){
        long long int tmp = 0;
        long long int pow_num = 1;
        for(int i=0;i<word.size();i++){
            long long int ascii = word[i];
            tmp = tmp + ascii * pow_num  ;
            tmp %= mod;
            pow_num *= x;
            pow_num %=mod;
        }
        return tmp;
    }
    
    void calPatternPow(){
        // calculate x^(pattern len)
        for(int i=0;i<pattern.size();i++){
            pow_pattern *= x;
            pow_pattern %= mod;
        }
    }
    long long int precalHashValue(long long int pre_hash, int i){
        // precomputer hash value from previous hash value
        long long int value = ( text[i] - text[pattern.size() + i] * pow_pattern ) % mod;
        if(value < 0)
            value += mod;
        value = (value +  x*pre_hash ) % mod;     
        if (value < 0 )
            value += mod;   

        return value;
    }

    bool isEqual(int index){
        for(int i = 0 ; i<pattern.size(); i++){
            if(pattern[i] != text[index + i ])
                return false;
        }
        return true;
    }
    void Rabin_Karp(){
        long long int pattern_hash = calHashValue(pattern);
        long long int text_pre_hash = calHashValue( text.substr(text.size() - pattern.size() , pattern.size() ) );
        long long int text_now_hash;
        calPatternPow();
        if (pattern_hash == text_pre_hash){
            location.push_back( text.size() - pattern.size() );
        }
        for (int i = text.size() - pattern.size() - 1 ; i>=0 ; i--){
            text_now_hash = precalHashValue(text_pre_hash, i);
            //cout << i <<"th = " << pattern_hash << " " << text_now_hash <<endl;
            if(text_now_hash == pattern_hash){
                if(isEqual(i)){
                    location.push_back(i);
                }
            }
                
            text_pre_hash = text_now_hash;
        }
    }

    void solve(){
        Rabin_Karp();
        printAns();
    }

    void printAns(){
        for(int i= location.size() - 1 ; i>=0 ;i--){
            if (i == location.size()-1)
                cout << location[i];
            else    
                cout << " " << location[i];
        }
        cout << endl;
    }
};
int main(){

    string P, T;
    cin >> P >> T;

    FindPatternPos findpattern(P, T);
    findpattern.solve();
    return 0;
}