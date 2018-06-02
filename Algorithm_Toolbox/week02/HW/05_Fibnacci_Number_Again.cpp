#include <iostream>
#include <vector>
using namespace std;
std::vector<int> findRemainderSeq(int mod){
	int start_point = 2, end_point = 0;
	int fibNum;
	int fibNum_last1 = 0, fibNum_last2 = 1;
	bool find = false;
	std::vector<int> period_seq;
	std::vector<int> remainder_record;
	remainder_record.push_back(0);
	remainder_record.push_back(1);
	while(1){
		//Calculate remain
		fibNum = fibNum_last1 + fibNum_last2;
		fibNum_last1 = fibNum_last2 % mod;
		fibNum_last2 = fibNum % mod;
		remainder_record.push_back(fibNum_last2);
		
		//Check period sequence
		end_point = start_point - 1;
		for(int i = 0 ; i<=end_point;i++){
			if(start_point+i+1 > remainder_record.size()){
				break;
			}
			//cout <<remainder_record[i] << " " << remainder_record[i+start_point] << endl;	
			
			if(remainder_record[i] != remainder_record[start_point+i]){	
				start_point ++ ;
				break;
			}
			else if(i == end_point && remainder_record[i] == remainder_record[start_point+i])
				find = true;
			else;
		}
		//cout << "------------------" <<endl;
		if(find){
			//cout << "seq size = " << end_point+1 << endl; 
			for(int i = 0 ; i<=end_point ;i++){
				period_seq.push_back(remainder_record[i]);
				//cout << period_seq[i] << " ";
			}
			//cout << endl;
			return period_seq;
		}

	}
}
int remainder(long long int n, int m){
	std::vector<int> period_seq = findRemainderSeq(m);
	int size = period_seq.size();
	int mod_num = n%size;
	return period_seq[mod_num];
}
int main()
{
	long long int n;
	int m;
	cin>>n>>m;
	cout<<remainder(n, m)<<endl;

}
