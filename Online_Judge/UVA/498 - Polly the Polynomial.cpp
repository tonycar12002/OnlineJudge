/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 498 - Polly the Polynomial
*/
#include<sstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	string a,b,c;
	double num[10000],coeff[10000];
	int num_count,coeff_count;
	while(getline(cin,a))
	{
		num_count=0,coeff_count=0;
		getline(cin,b);
		istringstream ssa(a),ssb(b);
		while(ssa>>c)	
		{
			int val=atoi(c.c_str());
			coeff[coeff_count++]=val;
		}
		while(ssb>>c)
		{
			int val=atoi(c.c_str());
			num[num_count++]=val;
		}

		for(int g=0;g<num_count;g++)
		{
			int ans=0,coeff_cal=1;
			for(int f=coeff_count-1;f>=0;f--)
			{
				ans+=coeff_cal*coeff[f];
				coeff_cal*=num[g];
			}
			if(g!=0)
				cout<<" "<<ans;
			else
				cout<<ans;
				
		}
		cout<<endl;
	}
	return 0; 
}