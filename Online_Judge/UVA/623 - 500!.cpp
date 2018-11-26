/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 623 - 500!  
*/
#include<iostream>
#include<string.h>
using namespace std;
int counts=0,ans[1001][3001];
int main()
{
	memset(ans,0,sizeof(ans));
	ans[0][1]=ans[1][1]=1;
	for(int g=1;g<=1000;g++)
	{
		for(int f=1;f<=3000;f++)	
		{
			ans[g][f]=counts+g*ans[g-1][f];
			counts=ans[g][f]/10;
			ans[g][f]=ans[g][f]%10;
		}
	}	
	int a,total;
	while(cin>>a)
	{
		total=3000;
		while(ans[a][total]==0)
				total--;
		cout<<a<<"!"<<endl;
		for(int f=total;f>=1;f--)
			cout<<ans[a][f];
		cout<<endl;
		
	}
return 0;
}