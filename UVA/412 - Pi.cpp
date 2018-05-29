/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 412 - Pi
*/
#include<iostream>
#include<math.h>
using namespace std;
bool relatively_prime(int a, int b)
{
	int c;
	while (b!=0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	if (a == 1)
		return true;
	else
		return false;
}
int main()
{
	int N,num[51],denominator,numerator;
	double pi;
	while (cin >> N)
	{
		denominator = 0;
		numerator = 0;
		if (N == 0)
			break;	
		for (int g = 0; g <N; g++)
		{
			cin >> num[g];
			denominator += g;
		}
		for (int g = 0; g < N; g++)
		{
			for (int f = g + 1; f < N; f++)
			{
				if (relatively_prime(num[g], num[f]))
					numerator++;
				else;
			}
		}
		pi = (double)6 * denominator / numerator ;
		pi = sqrt(pi);
		if (numerator == 0)
			cout << "No estimate for this data set." << endl;
		else
		{
			pi += 0.0000005;
			int integer = pi;
			pi -= integer;
			cout << integer<<".";
			for (int g = 0; g <=5; g++)
			{
				pi *= 10;
				integer = pi;
				pi -= integer;
				cout << integer;
			}
			cout << endl;
		}
	}
	return 0;
}