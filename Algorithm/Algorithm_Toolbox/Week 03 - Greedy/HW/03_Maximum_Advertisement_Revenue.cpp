#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdint.h>
using namespace std;
bool decrease(int i, int j){
	return (i>j);
}
int64_t maxProductSum(std::vector<int> profit, std::vector<int> click){
	int64_t ans = 0;
	for(int i=0; i<profit.size();i++){
		ans += 	(int64_t)profit[i] * click[i];
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;

	int tmp;
	std::vector<int> profit, click;
	for(int i=0;i<n;i++){
		cin>>tmp;
		profit.push_back(tmp);
	}
	for(int i=0;i<n;i++){
		cin>>tmp;
		click.push_back(tmp);
	}
	std::sort(profit.begin(), profit.end(), decrease);
	std::sort(click.begin(), click.end(), decrease);

	cout <<  fixed <<  setprecision(0) << maxProductSum(profit, click) << endl;

	return 0;
}