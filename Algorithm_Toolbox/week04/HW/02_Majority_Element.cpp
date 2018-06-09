#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;
void combineArray(int* array_1, int* array_2){

}
int* mergesort(int* sort_array){
		
}
int findMajorElement(int* element_list, int length){
	int ans; //1 for yes, 0 for no major element
	int record_element = 0, record_counts = 0;
	for(int i=0;i<length;i++){
		if(i!=0 && record_ele == element_list[i]){
			record_counts += 0;
		}
		else{
			record_counts = 0;
			record_element = element_list[i];
		}
		if(record_counts*2 >= length){
			return 1;
		}
	}
	return 0;

}
int main()
{
	int n;
	int *element_list;
	cin>>n;
	element_list = new int [n+1];
	for(int i=0;i<n;i++){
		cin>>tmp;
		element_list[i] = tmp;
	}
	element_list = mergesort(element_list, n)
	cout << findMajorElement(element_list) << endl;
	delete element_list;
	return 0;
}