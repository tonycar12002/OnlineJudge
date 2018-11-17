#include<iostream>
#include<stdint.h>
#include<vector>
using namespace std;
int main(){
	int num;
	cin>>num;
	vector<int>numbers(num);
	for(int i = 0; i<num;i++)
		cin>>numbers[i];
	int max = -999999, second_max = -9999999;
	for(int i = 0; i<num;i++){
		if(numbers[i]>max){
			second_max = max;
			max = numbers[i];
		}
		else if(numbers[i]>second_max){
			second_max = numbers[i];
		}
		else;
	}
	//cout << max << " " << second_max<<endl;
	int64_t ans = (long long int)max*second_max;
	cout<<ans<<endl;
	//system("pause");
	return 0;
}  
