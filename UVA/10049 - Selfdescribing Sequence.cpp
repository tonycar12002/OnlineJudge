/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 10049 - Selfdescribing Sequence
*/
#include<iostream>
using namespace std;
int num[800005];
int search(int low,int high,int x)
{
	int mid=(low+high)/2;
	if(num[mid]==x)
		return mid;
	else if(num[mid]>x && x>num[mid-1])
		return mid;
	else if(num[mid]>x)
		search(low,mid-1,x);
	else
		search(mid+1,high,x);
}
void make()
{
	num[0]=0;
	num[1]=1;
	num[2]=1+2;
	for(int g=3;g<=800000;g++)
		num[g]=num[g-1]+search(1,g,g);
}
int main()
{
	make();
	int  n;
	while(cin>>n)
	{
		if(n==0)
			break;
		int g=1;
		for(g;;g++)
			if(num[g]>=n)break;
		cout<<g<<endl;
	}
	return 0;
}