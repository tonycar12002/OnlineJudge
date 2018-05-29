/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 681 - Convex Hull Finding 
*/
#include<iostream>
#include<stdio.h>
using namespace std;
struct thepoint{int x;int y;};
thepoint all[513],ans[513];
int check;
void swap1(thepoint& a,thepoint& b)
{
	int q=b.x,w=b.y;
	b.x=a.x;
	a.x=q;
	b.y=a.y;
	a.y=w;
}
void quicksort(int left,int right)
{
	if(left<right)
	{
		int middle=left,comparenum=all[left].y;
		for(int g=left+1;g<=right;g++)
			if(all[g].y<comparenum)
				swap1(all[g],all[++middle]);
		swap1(all[middle],all[left]);
		quicksort(middle+1,right);
		quicksort(left,middle-1);
	}
}
int clockwise(thepoint& o,thepoint& a,thepoint& b)
{
	check=0;
	check=( (a.x-o.x)*(b.y-a.y) ) - ( (a.y-o.y)*(b.x-a.x) );
	return check;
}
int main()
{
	int b,a,total,counts;
	while(scanf("%d",&a)==1){
		for(int g=0;g<a;g++){
			counts=0;
			scanf("%d",&total);
			for(int f=0;f<total;f++)
				scanf("%d%d",&all[f].x,&all[f].y);
			scanf("%d",&b);
			quicksort(0,total-1);
			for(int f=0;f<total;f++){
				while(counts>=2&&clockwise(ans[counts-2],ans[counts-1],all[f])>=0)
				counts--;
				ans[counts].x=all[f].x;
				ans[counts++].y=all[f].y;
			}
			int t;
			for(int f=total-2,t=counts;f>=0;f--){
				while(counts>=t+1&&clockwise(ans[counts-2],ans[counts-1],all[f])>=0)
					counts--;
				ans[counts].x=all[f].x;
				ans[counts++].y=all[f].y;
			}
			int minnum=2147483647,record=0;
			for(int f=0;f<counts;f++)
			{
			     if(minnum>ans[f].y)
   				{
					record=f;
					minnum=ans[f].y;
				}
		   		else if(minnum==ans[f].y)
   				{    
					if(ans[record].x>ans[f].x)		
					{
						record=f;
						minnum=ans[f].y;
					}
				}      
				else;
           	}	
           	counts--;
			for(int g=record;g>=0;g--)
				printf("%d %d\n",ans[g].x,ans[g].y);
			for(int g=counts-1;g>record;g--)
				printf("%d %d\n",ans[g].x,ans[g].y);
			printf("%d %d\n",ans[record].x,ans[record].y);
		}
		
	}
return 0;
}