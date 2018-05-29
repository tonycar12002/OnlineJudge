/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 10038 - Jolly Jumpers
*/
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	long long n;
	long long all[3000],difference[3000];
	while(cin>>n)
	{
		for(int g=0;g<n;g++)	
			cin>>all[g];
		for(int g=1;g<n;g++)
			difference[g-1]=abs(all[g]-all[g-1]);
		sort(difference,difference+n-1);	
		bool check=false;
		for(int g=0;g<n-1;g++)
			if(difference[g]!=g+1)
				check=true;
		if(check)
			cout<<"Not jolly"<<endl;
		else
			cout<<"Jolly"<<endl;
	}
	return 0;	
}