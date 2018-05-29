/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 120 - Stacks of Flapjacks
*/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
void reverse(int start,int end,int all[100])
{
	int record[100];
	for(int g=0;g<=end-start;g++)
		record[g]=all[g+start];
	for(int g=0;g<=end-start;g++)
		all[end-g]=record[g];
}
void sort(int all[100],int total)
{
	int counts=0;
	int max=0,position=-1;
	for(int g=total;g>=0;g--)
	{
		max=0;
		for(int f=g;f>=0;f--)
		{
			if(all[f]>max)
			{
				max=all[f];
				position=f;
			}
		}
		if(position!=g)
		{
			if(position!=0) 
			{
				reverse(0,position,all);
				cout<<total-position+1<<" ";
			}
			reverse(0,g,all);
			cout<<total-g+1<<" ";
		}
	}
	cout<<0<<endl;
}
void output(string a,int all[100],int *total)
{
	int record=0;
	for(int g=0;g<a.length();g++)
	{
		if(a[g]==' ')
		{
			all[*total]=record;
			record=0;
			*total+=1;
		}	
		else
		{
			record*=10;
			record+=a[g]-48;
		}
	}
	all[*total]=record;
	if(total==0)
		cout<<all[0]<<endl;
	else
	{
		for(int g=0;g<*total;g++)
			cout<<all[g]<<" ";
		cout<<all[*total]<<endl;
	}
}
int main()
{
	string a;
	int total,all[100];
	while( getline(cin,a))
	{
		total=0;
		output(a,all,&total);
		sort(all,total);
	}
	return 0;
} 