/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 495 - Fibonacci Freeze
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int ans[5001][1101],digit=1,n,alldigit[5001];
void fibonacci(int x)
{
	while(x<=5000)
	{
			for(int g=0;g<digit;g++)
			{
				ans[x][g]+=ans[x-1][g]+ans[x-2][g];
				if(ans[x][g]>=10)
				{
					ans[x][g+1]+=ans[x][g]/10;
					ans[x][g]%=10;	
				}
			}
			if(ans[x][digit]!=0)
			{
				digit++;	
				alldigit[x]=digit;
			}
			else
				alldigit[x]=digit;
			x++;
			
	}
}
int main()
{
	memset(ans,0,sizeof(ans));
	memset(alldigit,0,sizeof(alldigit));
	alldigit[0]=1;
	alldigit[1]=1;
	ans[0][0]=0;
	ans[1][0]=1;
	fibonacci(2);
	while(scanf("%d",&n)==1)
	{
		printf("The Fibonacci number for %d is ",n);
		for(int g=alldigit[n]-1;g>=0;g--)
			printf("%d",ans[n][g]);
		puts(""); 
	}
return 0;	
}