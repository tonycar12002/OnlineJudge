#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::pair;

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector< long long int> start_times_;
  vector< pair<int, long long int> > workers_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  int GetParent(int i){
    return i/2;
  }
  int GetLeftChild(int i){
    return i*2 + 1;
  }
  int GetRightChild(int i){
    return i*2 + 2;
  }

  void MinHeap(int i){
    int left = GetLeftChild(i);
    int right = GetRightChild(i);
    
    long long int min = workers_[i].second;
    int index = i;

    if(left < num_workers_ && min > workers_[left].second ){
      index = left;
      min = workers_[left].second;
    }
    if(left < num_workers_ && min == workers_[left].second && workers_[left].first < workers_[index].first ){
      index = left;
      min = workers_[left].second;
    }
    if(right < num_workers_ && min > workers_[right].second ){
      index = right;
      min = workers_[right].second;        
    }
    if(right < num_workers_ && min == workers_[right].second && workers_[right].first < workers_[index].first){
      index = right;
      min = workers_[right].second;        
    }    

    //root of subtree is not the min
    if(i != index){
      std::iter_swap(workers_.begin() + i, workers_.begin() + index);
      MinHeap(index);

      //printf("worker = %d, time = %d \n", workers_[i].first, workers_[i].second);
      //printf("worker = %d, time = %d \n\n", workers_[index].first, workers_[index].second);      
    } 

  } 
  


  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    for (int i = 0 ; i< num_workers_ ; i++){
      pair<int, long long int> work(i, 0);
      workers_.push_back(work);
    }

    for (int i = 0 ; i< jobs_.size() ; i++){
      int next_worker = workers_[0].first;
      long long int time_start = workers_[0].second;
      
      assigned_workers_.push_back( next_worker );
     
      start_times_.push_back( time_start ) ;

      workers_[0].second += jobs_[i];
    
      MinHeap(0);
    }


  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
