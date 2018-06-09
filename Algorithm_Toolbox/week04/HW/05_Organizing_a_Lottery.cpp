#include <iostream>
#include <stdint.h>
#include <vector>
#include <utility>  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
struct Pair{
    int start;
    int end;
};
Pair* copyArray(Pair *element, int start, int end){
	Pair *result = new Pair [ (end-start+1) ];
	for(int i = start ; i <=end ; i++)
		result[i-start] = element[i];
	return result;
}
Pair* combineVector(Pair *num_1, Pair *num_2, int size_1, int size_2){
	int n=0, num_1_index=0, num_2_index=0;
    int total = size_1 + size_2;
    Pair *result = new Pair [total];
	while(n < total ){
		if(num_1_index < size_1 && num_2_index < size_2){
			if(num_1[num_1_index].start >= num_2[num_2_index].start){
				result[n] = num_2[num_2_index];
				num_2_index++;
			}
			else{
				result[n] = num_1[num_1_index];
				num_1_index++;			
			}
		}
		else if(num_1_index < size_1){
			result[n] = num_1[num_1_index];
			num_1_index++;
		}
		else{
			result[n] = num_2[num_2_index];
			num_2_index++;
		}
		n++;
	}

	// print merge result
	
    /*
	cout << "merge = ";
	for(int i = 0 ; i < total ; i++)
		cout << result[i].start <<" "<<result[i].end<<", ";
	cout << endl;
	*/

	return result;
}
Pair* mergesort(Pair *seg, int size){
	if(size == 1){
		return seg;
	}
	int mid = size/2;

	Pair* A = mergesort( copyArray(seg, 0, mid-1), mid);
	Pair* B = mergesort( copyArray(seg, mid, size-1), size-mid);
	Pair* C = combineVector(A, B, mid, size-mid);

    delete A;
    delete B;
	return C;
}
int containSegNum(Pair *seg, int seg_size, int target){
    int counts = 0;
    for(int i=0;i<seg_size;i++){
        if(seg[i].start > target)
            break;
        else if(seg[i].end >= target){
            counts++;
        }
    }
    return counts;
}
int nativeSegNum(Pair *seg, int seg_size, int target){
    int counts = 0;
    for(int i=0;i<seg_size;i++){
        if(seg[i].start <= target && seg[i].end >= target)
           counts ++;
    }
    return counts;    
}
int main()
{
	int n, pt, st, ed, tmp;
    Pair *seg, *sort;
	cin>>n>>pt;
    seg = new Pair [n];
    sort = new Pair [n];
    srand (time(NULL));
	for(int i=0;i<n;i++){
		cin>>st>>ed;
        seg[i].start = st;
        seg[i].end = ed;
        //Random
        /*
		seg[i].start = rand()%2000 -1200;
        tmp = rand()%2000 -1200;
        while(tmp<=seg[i].start)
            tmp = rand()%2000 -1200;
        seg[i].end = tmp;
        */
	}
    sort = mergesort(seg, n);
    /*
	cout << "sort = ";
	for(int i = 0 ; i < n ; i++)
		printf("(%d, %d)\n", sort[i].start, sort[i].end);
	*/
	for(int i=0;i<pt-1;i++){
		cin>>tmp;
        cout << containSegNum(sort, n, tmp) << " ";
	}    
    cin>>tmp;
    cout << containSegNum(sort, n, tmp) << endl;

    delete seg;
    return 0;
}