#include <iostream>
using namespace std;
int minNumofCoins(int m){
	int coin[3] = {1, 3, 4};
	int money_dp[1001];
	money_dp[0] = 0;
	for(int i = 1 ; i<=m; i++){
		money_dp[i] = 10000;
		for (int c = 0 ; c<=2 ; c++){
			if(i - coin[c] >= 0 )
				money_dp[i] = min ( money_dp[i-coin[c]]+1 , money_dp[i]);
		}
	}

	return money_dp[m];
}
int main(){
	int money;
	cin>>money;
	cout << minNumofCoins(money) << endl;
}