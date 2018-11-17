#include <iostream>
#include <vector>
using namespace std;
std::vector<int> findSumArray(const int& n){
	int num = n;
	int now_int = 1;
	std::vector<int> sun_array;
	while(num>0){
		if(num - now_int > now_int || num - now_int == 0){
			sun_array.push_back(now_int);
			num -= now_int;
		}
		now_int ++ ;
	}
	return sun_array;
}
int main()
{
	int n;
	std::vector<int> ans;
	cin>>n;
	ans = findSumArray(n);
	cout << ans.size() << endl;
	for(int i=0;i<ans.size()-1;i++){
		cout << ans[i] << " ";
	}
	cout << ans[ans.size()-1] <<endl;

	return 0;
}