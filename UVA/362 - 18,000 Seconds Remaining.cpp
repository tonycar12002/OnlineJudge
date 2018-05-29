/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 362 - 18,000 Seconds Remaining
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long total_bytes,speed,num=1;
	while(cin>>total_bytes)
	{
		if(total_bytes==0)break;
		cout<<"Output for data set "<<num<<", "<<total_bytes<<" bytes:"<<endl;
		double five_average=0;
		long long total_time=0,counts=1;
		while(counts++)
		{
			cin>>speed;
			total_bytes-=speed;
			total_time++;
			five_average+=speed;
			if((counts-1)%5==0)
			{
				
				if(five_average!=0)
				{
					//five_average/=5;
					double b=total_bytes*5/five_average;
					int a=ceil(b);
					cout<<"   Time remaining: "<<a<<" seconds"<<endl;
				}
				else
					cout<<"   Time remaining: stalled"<<endl;
				five_average=0;	
			}
			if(total_bytes<=0)
				break;
		}	
		cout<<"Total time: "<<total_time<<" seconds"<<endl;
		cout<<endl;
		num++;
	}
	return 0;	
}