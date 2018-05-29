/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 11959 - dice
*/
#include <stdio.h>
#define Rx(d) ( ((d) & 0x0000F0) << 16 | ((d) & 0x00F000) << 4 | ((d) & 0xF00000) >> 8 | ((d) & 0x000F0F) | ((d) & 0x0F0000) >> 12 )
#define Ry(d) ( ((d) & 0x000F00) << 4*3 | ((d) & 0x00000F) << 4*4 | ((d) & 0x00F0F0) | ((d) & 0x0F0000) >> 4*2 | ((d) & 0xF00000) >> 4*5 )
#define Rz(d) ( ((d) & 0x000F00) >> 4 | ((d) & 0x00000F) << 4*3 | ((d) & 0xFF0000) | ((d) & 0x0000F0) >> 4 | ((d) & 0x00F000) >> 4 )
int main ()
{
    int dic1,dic2 ;
    bool check=false;
    int l,n;
    scanf ("%d",&n);
    for (int l = 1;l <= n;l++)
	{	
		check = false;
		scanf ("%x %x",&dic1,&dic2);
		
	    for (int i = 1;i<=4 ;i++)
	    {
	    
			if (dic1 == dic2 )
			{
				
				check = true;
				break;
			}	
			else 
			{
				
				for (int j = 1;j<=4 ;j++)
				{
				
					if (dic1 == dic2 )
					{
						
						check = true;
						break;
					}	
					else 
					{
						for (int k = 1;k<=4 ;k++)
							if (dic1 == dic2 )
							{
								check = true;
								break;
							}	
							else 
								dic2 = Ry(dic2);
						dic2 = Rz(dic2);
					}
				}	
				dic2 = Rx(dic2);
			}
		}
		if (dic1 == dic2 )
				check = true;
		if (check)
			printf ("Equal\n");
		else 
			printf ("Not Equal\n");
		
	}	
		

    return 0;
}