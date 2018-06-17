#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Request
{
	Request(int arrive_time, int process_time):
		arrive_time(arrive_time), process_time(process_time)
	{}
	int arrive_time;
	int process_time;
};

struct Response
{
	bool dropout;
	int finish_time;
};

void processRequests(vector<Request> requests){
	queue<Response> buffer;
	int now_time = 0;
	for(int i=0;i<requests.size();i++){

	}
}

int main(int argc, char **argv){
	int s, n, arrive_time, process_time;
	cin >> s >> n;

	vector<Request> requests;
	vector<Response> responses;
	
	for(int i = 0 ; i<n ; i++){
		cin >> arrive_time >> process_time;
		requests.push_back(Request(arrive_time, process_time));
	}
	processRequests(requests);
	if(n==0);
	else{

	}
	return 0;
}