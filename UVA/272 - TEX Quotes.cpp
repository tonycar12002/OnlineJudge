/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 272 - TEX Quotes
*/
#include<iostream>
#include<time.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	char input;
	bool isQuote =false;
	while (input = getchar())
	{
		if (input == EOF)
			break;
		if (input == '"')
		{
			if (isQuote)
			{
				putchar('\'');
				putchar('\'');
			}
			else
			{
				putchar('\`');
				putchar('\`');
			}
			isQuote = !isQuote;
		}
		else
			putchar(input);
	}
	return 0;
}