#include <iostream>
#include <map>
#include <iomanip>
using namespace std;
double knapsackMaxValue(double capacity, std::map<double, double, std::greater<double>> item){
	map<double, double>::iterator it = item.begin();
	double ans = 0;
	while(capacity>0 && it!=item.end()){
		double cp = it->first, weight = it->second;
		if(capacity >= weight){
			ans += cp*weight;
			capacity -= weight;
		}
		else{
			ans += cp*capacity;
			capacity = 0;
		}
		it++;
	}
	return ans;
}
int main()
{
	int n, capacity;
	cin >> n >> capacity;

	double v, w;
	std::map<double, double, std::greater<double>> item;
	for(int i=0;i<n;i++){
		cin>>v>>w;
		item[v/w] = w ; // Record CP and total weight
	}

	cout <<  fixed <<  setprecision(4) << knapsackMaxValue(capacity, item) << endl;

	return 0;
}