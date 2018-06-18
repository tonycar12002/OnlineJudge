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
	Response(bool dropout, int finish_time, int start_time):
		dropout(dropout), finish_time(finish_time), start_time(start_time)
	{}
	bool dropout;
	int finish_time;
	int start_time;
};

void processRequests(vector<Request> requests, int buffer_size){
	queue<Response> buffer;
	vector<Response> responses;
	int now_time = 0;
	for(int i=0;i<requests.size();i++){
		if(buffer.size()<buffer_size){		
			if(now_time<=requests[i].arrive_time)
				now_time = requests[i].arrive_time + requests[i].process_time;
			else
				now_time += requests[i].process_time;	

			responses.push_back(Response(false, now_time, now_time-requests[i].process_time));
			buffer.push(Response(false, now_time, now_time-requests[i].process_time));
		}
		else if(buffer.front().finish_time <= requests[i].arrive_time){
			if(now_time<=requests[i].arrive_time)
				now_time = requests[i].arrive_time + requests[i].process_time;
			else
				now_time += requests[i].process_time;

			responses.push_back(Response(false, now_time, now_time-requests[i].process_time));
			buffer.pop();
			buffer.push(Response(false, now_time, now_time-requests[i].process_time));
		}
		else if(buffer.front().finish_time > requests[i].arrive_time){
			responses.push_back(Response(true, -1, -1));
		}
		else;
	}

	for(int i=0;i<responses.size();i++){
		if(responses[i].dropout)
			cout << -1 << endl;
		else
			cout << responses[i].start_time << endl;
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
	if(n==0);
	else{
		processRequests(requests, s);
	}
	return 0;
}