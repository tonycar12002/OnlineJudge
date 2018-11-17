#include <iostream>
#include <stdint.h>
#include <vector>
#include <stdio.h>
using namespace std;
void improveQuickSort(std::vector<int>& number, int left, int right){
    if(right<=left)
        return;

    int pivot = number[left], index_small = left+1, index = left+1;
    for(int i = left+1 ; i <=right ; i++){
        if(number[i] == pivot){
            swap(number[index], number[i]);
            index += 1;
        }
        else if(number[i] <= pivot){
            swap(number[index], number[i]);
            swap(number[index], number[index_small]);
            index += 1;
            index_small += 1;
        }
        else;
    }
    index -=1;
    index_small -=1;
    swap(number[left], number[index_small]);

    improveQuickSort(number, left, index_small-1);
    improveQuickSort(number, index+1, right);

}
int main()
{
    int n ,tmp;
    vector<int>number, result;
    cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		number.push_back(tmp);
	}
    improveQuickSort(number, 0, n-1);
	for(int i=0;i<n-1;i++){
		cout << number[i] << " ";
	}    
    cout << number[n-1] << endl;
    return 0;
}