/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 10499 - The Land of Justice
*/
#include<iostream>
using namespace std;
int main()
{
	long long   n;
	while(cin>>n)
	{
		if(n<0)break;
		else if(n==1)
			cout<<"0%"<<endl;
		else
		{
			n*=25;
			cout<<n<<"%"<<endl;
		}
	}
	return 0;	
}