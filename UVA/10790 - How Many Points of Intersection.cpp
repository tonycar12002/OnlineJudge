/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 10790 - How Many Points of Intersection 
*/
#include<iostream>
using namespace std;

int main()
{
	long long n=0,a,b;	
	while(cin>>a>>b)
	{
		n++;
		if(a==b&&a==0)
			break;
		cout<<"Case "<<n<<": "<<a*(a-1)/2*b*(b-1)/2<<endl;
	}
	return 0;
}