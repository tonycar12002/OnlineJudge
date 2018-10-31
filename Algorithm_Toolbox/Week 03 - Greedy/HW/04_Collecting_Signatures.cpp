#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <array>
using namespace std;
bool increase(const pair<int, int> &i, const pair<int, int> &j){
	return (i.second < j.second);
}
void minVisitPoint(std::vector< std::pair<int, int> > people_home){
	int visit_num = 0;
	std::vector<int> visit_time;
	std::vector< std::pair<int, int> >::iterator it = people_home.begin();
	while(it!=people_home.end()){
		visit_num += 1;
		int end_point = it->second;
		it++;
		while(it->first <= end_point && it!=people_home.end()){
			it++;	
		}
		visit_time.push_back(end_point);
	}
	
	cout << visit_num << endl;
	for(int i=0;i<visit_time.size()-1;i++){
		cout << visit_time[i] << " " ;
	}
	cout<< visit_time[visit_time.size()-1] << endl;
}
int main()
{
	int n;
	cin >> n;

	int st, ed;
	std::vector< std::pair<int, int> > people_home;
	for(int i=0;i<n;i++){
		cin>>st>>ed;
		people_home.push_back(std::make_pair(st, ed));
	}
	std::sort(people_home.begin(), people_home.end(), increase);

	minVisitPoint(people_home);

	return 0;
}