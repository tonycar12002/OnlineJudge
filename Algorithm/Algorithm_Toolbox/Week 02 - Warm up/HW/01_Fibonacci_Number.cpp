#include <iostream>
using namespace std;
int fibonacci(int n){
	int f_before_1 = 0, f_before_2 = 1;
	int ans= 0;
	if(n<=1)
		return n;
	else{
		while(n>=2){
			n--;
			ans = f_before_1 + f_before_2;
			//Update n-1. n-2 numer
			f_before_1 = f_before_2;
			f_before_2 = ans;
		}
		return ans;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<fibonacci(n)<<endl;

}
