#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;
struct Point{
    double x;
    double y;
};
double dist(Point p1, Point p2){
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y));
}
void quickSort(Point* point, int left, int right, bool sortByX){
    if(right<=left)
        return;

    int pivot, index = left+1, num;
    pivot = (sortByX) ? point[left].x : point[left].y;
    for(int i = left+1 ; i <=right ; i++){
        num = (sortByX) ? point[i].x : point[i].y;
        if(num < pivot){
            swap(point[index], point[i]);
            index += 1;
        }
        else if(num == pivot){
            if(sortByX){
                if(point[i].y <= point[left].y){
                    swap(point[index], point[i]);
                    index += 1;                    
                }
                else;
            }
            else{
                if(point[i].x <= point[left].x){
                    swap(point[index], point[i]);
                    index += 1;                    
                }
                else;
            }
        }
        else;
    }
    index -=1;
    swap(point[left], point[index]);

    quickSort(point, left, index-1, sortByX);
    quickSort(point, index+1, right, sortByX);

}
double findClosestDist(Point *point, int left, int right){
    if(left>=right)
        return 1e9;
    int middle = (left+right)/2;
    double d = min( findClosestDist(point, left, middle), findClosestDist(point, middle+1, right) );

    //Get all the points which the x locate at [middle-d, middle+d]
    Point tmp[right-left+1];
    int N=0;
    for(int i=middle; i>=left && point[middle].x - point[i].x < d;i--){
        tmp[N] = point[i];
        N++;
    }
    for(int i=middle+1; i<=right && point[i].x - point[middle].x < d;i++){
        tmp[N] = point[i];
        N++;
    }
    //Sort with y
    quickSort(tmp, 0, N-1, false);
    


    for(int i=0;i<N-1;i++){
        for(int j = 1 ; j<=3 && i+j < N; j++){
            d = min( d, dist(tmp[i], tmp[i+j]));
           // printf( "(%f, %f) and (%f, %f) dis = %f \n", tmp[i].x, tmp[i].y, tmp[i+j].x, tmp[i+j].y, dist(tmp[i], tmp[i+j]) );
        }
    }

    return d;
}
bool mySort(Point p1, Point p2){
    if(p1.x>=p2.x)
        return false;
    return true;
}
int main()
{
    int n, x, y;
    cin >> n;
    Point point[100001];
    for(int i=0;i<n;i++){
        cin>>x>>y;
        point[i].x=x, point[i].y=y;
    }
    sort(point, point+n, mySort);
    /*
    for(int i=0;i<n;i++){
        printf("(%f, %f)\n", point[i].x, point[i].y);
    }*/
    if(n>2)
        cout << fixed << setprecision(4) << findClosestDist(point, 0, n-1) << endl;
    else
        cout << fixed << setprecision(4) << dist(point[0], point[1]) << endl;
    return 0;
}