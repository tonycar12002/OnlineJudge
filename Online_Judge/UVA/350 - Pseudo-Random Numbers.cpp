/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 350 - Pseudo-Random Numbers
*/
#include <stdio.h>
#include <string.h>
#include<iostream>
using namespace std;
int all[100002];
int main ()
{

	int z,i,m,l,counts=1;
	bool check=false;
	while(cin>>z>>i>>m>>l)
	{
		int start=1,end=3;
		if(z==i&&z==0&&i==m&&l==m)	
			break;
		cout<<"Case "<<counts<<": ";
		all[0]=(z*l+i)%m;
		for(int g=1;g<=100000;g++)
		{
			all[g]=(z*l+i)%m;
			l=all[g];	
			if(all[g]!=all[g-1])
				check=true;
		}
		while(check)
		{
			int range=end-start-1;
			int record=0;
			int x=start,y=end;
			while(all[x++]==all[y++] && record!=range)	
				record++;	
			if(record==range)
				check=false;
			else
			{
				start+=1;
				end+=2;
			}
		}
		if(!check)
			cout<<end-start<<endl;
		counts++;
	}
	return 0;
}