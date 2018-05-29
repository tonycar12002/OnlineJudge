/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 402 - M*A*S*H
*/
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	int N, X, poke[20],now_poke;
	int counts = 0;
	while (cin >> N >> X)
	{
		now_poke = 0;
		for (int g = 0; g < 20; g++)
			cin >> poke[g];
		counts++;
		vector<int> member;
		for (int g = 1; g <= N; g++)
			member.push_back(g);
		int now = 0;
		while (member.size() > X&&now_poke<20)
		{
			now += poke[now_poke];
			if (now>member.size())
				now = 0;
			else
			{	
				member.erase(member.begin() + now-1);
				now--;
				now_poke--;
			}
			now_poke++;
		}
		cout << "Selection #" << counts << endl;
		for (vector<int>::iterator it = member.begin(); it != member.end(); it++)
		{
			if (it == member.begin())
				cout << *it;
			else
				cout  <<" "<< *it ;
		}
			cout << endl;
			cout << endl;
	}
}