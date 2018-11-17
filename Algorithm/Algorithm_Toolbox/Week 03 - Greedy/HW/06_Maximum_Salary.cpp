/*
	Be care of the case 4 45 459 451 9
*/
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
bool IsGreaterOrEqual(int a, int b){
	std::string a_s = std::to_string(a);
	std::string b_s = std::to_string(b);
	int digit_num = min(a_s.length(), b_s.length());
	for(int i=0;i<digit_num;i++){
		if(a_s[i] > b_s[i])
			return true;
		else if (a_s[i] < b_s[i])
			return false;
		else;
	}

	if(a_s.length() > b_s.length()){
		while(digit_num<a_s.length()){
			if(a_s[digit_num]>a_s[0]){
				return true;
			}
			else if(a_s[digit_num]<a_s[0]){
				return false;
			}
			else
				digit_num++;
		}
		return true;
	}
	else if(a_s.length() < b_s.length()){
		while(digit_num<b_s.length()){
			if(b_s[digit_num]>b_s[0]){
				return false;
			}
			else if(b_s[digit_num]<b_s[0]){
				return true;
			}
			else
				digit_num++;
		}
		return true;
	}
	else
		return true;
}
void reverse(std::vector<int>& num, int index_1, int index_2){
	int tmp = num[index_2];
	num[index_2] = num[index_1];
	num[index_1] = tmp;
}
void quicksort(std::vector<int>& num, int left, int right){
	if(left>=right || left <0 || right >= num.size())
		return;
	int pivot = num[left];
	int index = left+1;

	for(int i = left+1;i<=right; i++){
		if(!IsGreaterOrEqual(pivot, num[i])){
			reverse(num, index, i);
			index++;
		}
	}
	index --;
	reverse(num, left, index);
	quicksort(num, left, index-1);
	quicksort(num, index+1, right);

}
void maxNumberSquence(std::vector<int> num){
	//Sort the vector
	quicksort(num, 0, num.size()-1);

	for(int i=0;i<num.size();i++)
		cout << num[i];
	cout <<endl;
}
int main()
{
	int n, tmp;
	std::vector<int> num;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>tmp;
		num.push_back(tmp);
	}

	maxNumberSquence(num);

	return 0;
}