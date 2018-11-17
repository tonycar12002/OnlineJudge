#include <iostream>
using namespace std;
int GCD(int num1, int num2){
	int remain = 1;
	while(num1%num2!=0){
		remain = num1 % num2;
		num1 = num2;
		num2 = remain;
	}
	return num2;

}
int main()
{
	int a, b;
	cin>>a>>b;
	cout << GCD(a, b);

	return 0;
}
