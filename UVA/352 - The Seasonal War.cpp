/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 352 - The Seasonal War
*/
#include<iostream>
using namespace std;
void DFS(int all[26][26],int x,int y,int N)
{
	if(x<0||y<0||x>=N||y>=N);
	else if(all[x][y]==1)
	{
		all[x][y]=0;
		DFS(all,x+1,y,N);
		DFS(all,x+1,y+1,N);
		DFS(all,x+1,y-1,N);
		DFS(all,x,y+1,N);
		DFS(all,x,y-1,N);
		DFS(all,x-1,y+1,N);
		DFS(all,x-1,y,N);
		DFS(all,x-1,y-1,N);	
	}
	else;
}
int main()
{
	int N,all[26][26],num=1;
	while(cin>>N)
	{
		int ans=0;
		string tmp;
		for(int y=0;y<N;y++)
		{
			cin>>tmp;
			for(int g=0;g<tmp.size();g++)
			{
				all[g][y]=tmp[g]-48;	
			}
		}
		for(int y=0;y<N;y++)
		{
			for(int x=0;x<N;x++)	
			{
				if(all[x][y]==1)
				{
					ans++;
					DFS(all,x,y,N);		
				}	
			}
		}
		
		cout<<"Image number "<<num<<" contains "<<ans<<" war eagles."<<endl;
		num++;		
	}
	return 0;	
}