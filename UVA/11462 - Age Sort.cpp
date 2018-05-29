/*
Author: Tony Hsiao
Date: 2018/05/28
Topic: 11462 - Age Sort
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int a[2000000],b;
int c[2000000],d[2000000],save[2000000];
void mergesort(int left,int right)
{
    if(left>=right)return;
    int mid=(left+right)/2;
    mergesort(left,mid);
    mergesort(mid+1,right);
    int counts1=left,counts2=mid+1,record=0;
    for(int g=left;g<=mid;g++)
       c[g]=a[g];
    for(int g=mid+1;g<=right;g++)
        d[g]=a[g];
    while(counts1<=mid&&counts2<=right)
    {
        if(c[counts1]<d[counts2])
            save[record++]=c[counts1++];  
        else  
            save[record++]=d[counts2++];
    }
    while(counts1<=mid)
        save[record++]=c[counts1++];
    while(counts2<=right)
        save[record++]=d[counts2++];
    for(int g=left,f=0  ;  g<=right;   f++,g++)
        a[g]=save[f];
}
long long int input()   
{   
  char cha;   
  unsigned long long int x=0;   
  while(cha=getchar())   
     if(cha!=' '&&cha!='\n') break;   
  x=cha-48;   
  while(cha=getchar())    
    {   
     if(cha==' '||cha=='\n') break;   
      x=x*10+cha-48;   
    }   
    return x;   
}
int main()
{
    while(cin>>b)
    {
        
        if(b==0)
            break;
        else if(b==1)
        {
            cin>>a[0];
            cout<<a[0]<<endl;;
        }    
        else
        {
             for(int g=0;g<b;g++)
                a[g]=input();
             mergesort(0,b-1);    
             for(int g=0;g<b-1;g++)
                cout<<a[g]<<" ";
            cout<<a[b-1]<<endl;
        }
    }
    return 0;
}