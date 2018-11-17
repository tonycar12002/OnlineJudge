#include <iostream>
#include <stdint.h>
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
int64_t LCM(int64_t num1, int64_t num2){
	int gcd = GCD(num1, num2);
	return num1/gcd*num2;
}
int main()
{
	int a, b;
	cin>>a>>b;
	cout << LCM(a, b);

}
