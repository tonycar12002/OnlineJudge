#include <iostream>
#include <stdint.h>
#include <vector>
#include <stdio.h>
#include <time.h>
using namespace std;
int binarySearch(int* num_vec, int target, int start, int end){
	int mid = (start+end)/2;
	if(num_vec[mid] == target)
		return mid;
	else if(start >= end)
		return -1;
	else if(num_vec[mid] > target)
		return binarySearch(num_vec, target, start, mid-1);
	else
		return binarySearch(num_vec, target, mid+1, end);
}
int main()
{
	int k, n;
	int num_vec[100001], ans[100001];
	int tmp;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>tmp;
		num_vec[i] = tmp;
	}

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		ans[i] = binarySearch (num_vec, tmp, 0, k-1);
	}

	//Random 
	/*
	srand( (unsigned)time(NULL));
    for(int i=0; i<10000; ++i){
        num_vec.push_back(rand() % 10000000);
    }
    for(int i=0; i<10000; ++i){
        search_vec.push_back(rand() % 10000000);
    }
    */

	for(int i=0;i<n-1;i++){
		cout << ans[i] << " ";
	}	
	cout << ans[n-1] << endl;

	return 0;
}