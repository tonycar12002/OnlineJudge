#include <iostream>
#include <vector>
using namespace std;
int NumerofCoins(int money){
	int dollar_ten, dollar_five, dollar_one;

	dollar_ten = money / 10;
	money%=10;
	dollar_five = money / 5;
	money%=5;
	dollar_one = money;

	return dollar_one+dollar_five+dollar_ten;
}
int main()
{
	int m;
	cin>>m;
	cout << NumerofCoins(m) << endl;

	return 0;
}