/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 107 - The Cat in the Hat
*/
#include<iostream>
#include<math.h>
#include<stdio.h> 
using namespace std;
int main()
{
	int H,down,N;
	int counts=0;
	while(scanf("%d%d",&H,&down)==2 )
	{
		int height,work;
		if(H==0&&down==0)
			break;
		if(down==1)
		{
			counts=0;
			while(H%(2)==0)
			{
				counts++;
				H/=2;
			}
			N=1;
			cout<<counts<<" "<<pow(2,counts+1)-1<<endl;
		}
		else
		{
			for(int g=2;;g++)
			{
				counts=0;
				height=H;
				work=down;
				while(height%(g+1)==0 && work%g==0)
				{
					counts++;
					height/=g+1;
					work/=g;
				}
				if(height==1&&work==1)
				{
					N=g; 
					break;
				}	
			}
			int notwork=1,totalH,record=N,N2;
			N2=pow(N+1,counts);
			///cout<<N2<<endl;
			totalH=N2;
			N2/=N+1;
			for(int g=0;g<counts;g++)
			{
				totalH+=record*N2;
				notwork+=record;
				N2/=N+1;
				record*=N;
			}
			cout<<notwork-down<<" "<<totalH<<endl;
		}
	}
	return 0;
}
