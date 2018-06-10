#include <iostream>
#include <vector>
using namespace std;
void DP(int num){
	int operate[3]={1, 2, 3};
	int *num_DP = new int [num+1];
	
	//Init
	num_DP[0] = 0, num_DP[1] = 0;
	//DP
	for(int i = 2 ; i<=num; i++){	
		num_DP[i] = 10000;
		for(int o=0;o<=2;o++){
			if(i%operate[o]==0){
				//+1
				if(operate[o]==1){
					num_DP[i] = min(num_DP[i-1]+1, num_DP[i]);
				}
				//%2, %3
				else{
					num_DP[i] = min(num_DP[i/operate[o]]+1, num_DP[i]);
				}
			}
		}
	}
	cout << num_DP[num] << endl;
	std::vector<int> seq_num;
	for(int i = num ; i>=2; i++){	
		
	}
	delete num_DP;
}
int main()
{
	int target;
	cin >>target;
	DP(target);

	return 0;
}