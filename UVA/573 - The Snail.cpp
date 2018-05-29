/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 573 - The Snail 
*/
#include<iostream>
#include<math.h>
using namespace std;
double ans,height;
void  climb(double h,double u,double d,double next)
{
	ans++;
	height+=u;
	while(height<=h && height>0)
	{
		height-=d;
		//cout<<ans<<"day = "<<height<<"  "<<u<<endl;
		if(height<0)
			break;
		u-=next	;
		if(u<0)
			u=0;
		ans++;
		height+=u;
	}
	if(height>h)
		cout<<"success on day "<<ans<<endl;
	else
		cout<<"failure on day "<<ans<<endl;
}
int main()
{
	double h,u,d,f;
	double con;
	while(cin>>h>>u>>d>>f)
	{
		ans=0;
		height=0;
		if(h==0)
			break;
		con=f/100;
		climb(h,u,d,u*con);	
	}
	return 0;
}