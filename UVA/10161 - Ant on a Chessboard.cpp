/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 10161 - Ant on a Chessboard
*/
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int all[45000];
void run()
{
	all[0]=0;
	for(int g=1;g<=45000;g++)
		all[g]=g*g;
}
int main()
{
	run();
	int N;
	while(cin>>N)
	{
		if(N==0)
			break;
		int check=0;
		for(int g=1;;g++)
		{
			if(N<=all[g])
			{
				check=g;
				break;
			}
		}
		if(check%2==1)
		{
			N-=all[check-1];
			if(N==check)
				cout<<check<<" "<<check<<endl;
			else if(N>check)
			{
				N=N-check;
				cout<<check-N<<" "<<check<<endl;
			}
			else
			{
				cout<<check<<" "<<N<<endl;
			}
		}
		else
		{
			N-=all[check-1];
			if(N==check)
				cout<<check<<" "<<check<<endl;
			else if(N>check)
			{
				N=N-check;
				cout<<check<<" "<<check-N<<endl;
			}
			else
			{
				cout<<N<<" "<<check<<endl;
			}
		}
	} 
	return 0;
} 