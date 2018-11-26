/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 458 - The Decoder 
*/
#include <iostream>
#include<string.h>
using namespace std;
int main()
{
	int b,c;
	char a[1000000],d[100000];
	while(cin>>a)
	{
		b=strlen(a);
		for(c=0;c<b;c++)
		{
			a[c]=(int)a[c]-7;	
		}
		cout<<a<<endl;
		
		
		
	}
 
return 0;    
}
