/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 10025 - The 1 2 3 n = k problem
*/
#include<iostream>
#include<math.h>
using namespace std;
void check(int k,int n)
{
	while( (k+1)*k/2 < n || ( (k+1)*k/2 -n )% 2 !=0)
				k++;
	if(n==0)
		cout<<3<<endl;
	else
		cout<<k<<endl;
}
int main()
{
	int a,n;
	while(cin>>a)
	{
		for(int g=0;g<a;g++)
		{
			cin>>n;
			if(n<0)
				n=-n; 
			int k=1;
			check(k,n);
			if(g!=(a-1))
				cout<<endl;
		}
	}
	return 0;
} 