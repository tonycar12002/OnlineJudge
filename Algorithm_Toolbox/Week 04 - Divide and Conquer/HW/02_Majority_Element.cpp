#include <iostream>
#include <stdint.h>
#include <vector>
#include <stdio.h>
using namespace std;
vector<int>copyVector(vector<int> element, int start, int end){
	//printf("%d %d %d\n", element.size(), start, end);

	vector<int> result;
	for(int i = start ; i <=end ; i++)
		result.push_back(element[i]);
	return result;
}
vector<int> combineVector(vector<int> num_1, vector<int> num_2){
	vector<int>result;
	int n=0, num_1_index=0, num_2_index=0;
	while(n<num_1.size()+num_2.size()){
		if(num_1_index < num_1.size() && num_2_index < num_2.size()){
			if(num_1[num_1_index] >= num_2[num_2_index]){
				result.push_back(num_2[num_2_index]);
				num_2_index++;
			}
			else{
				result.push_back(num_1[num_1_index]);
				num_1_index++;			
			}
		}
		else if(num_1_index < num_1.size()){
			result.push_back(num_1[num_1_index]);
			num_1_index++;
		}
		else{
			result.push_back(num_2[num_2_index]);
			num_2_index++;
		}
		n++;
	}

	// print merge result
	/*
	cout << "merge = ";
	for(int i = 0 ; i < result.size() ; i++)
		cout << result[i] <<" ";
	cout << endl;
	*/

	return result;
}
vector<int> mergesort(vector<int> element){
	int size = element.size();
	if(size == 1){
		return element;
	}
	int mid = size/2;
	vector<int> A = mergesort( copyVector(element, 0, mid-1) );
	vector<int> B = mergesort( copyVector(element, mid, size-1) );
	vector<int> C = combineVector(A, B);

	return C;
}
int findMajorElement(vector<int> element_list){
	int ans; //1 for yes, 0 for no major element
	int record_element = 0, record_counts = 0;
	for(int i=0;i<element_list.size();i++){
		if(i!=0 && record_element == element_list[i]){
			record_counts += 1;
		}
		else{
			record_counts = 1;
			record_element = element_list[i];
		}
		if(record_counts*2 > element_list.size()){
			return 1;
		}
	}
	return 0;

}
int main()
{
	int n, tmp;
	vector<int>element_list;
	vector<int>sort;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		element_list.push_back(tmp);
	}
	sort = mergesort(element_list);
	cout << findMajorElement(sort) << endl;
	return 0;
}