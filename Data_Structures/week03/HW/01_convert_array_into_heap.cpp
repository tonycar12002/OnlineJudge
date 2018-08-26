#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;
using std::endl;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
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
    
    int min = data_[i], index = i;

    if(left < data_.size() && min > data_[left]){
      index = left;
      min = data_[left];
    }
    if(right < data_.size() && min > data_[right]){
      index = right;
      min = data_[right];        
    }
    
    //root of subtree is not the min
    if(i != index){
      std::iter_swap(data_.begin() + i, data_.begin() + index);
      swaps_.push_back(make_pair(i, index));
      MinHeap(index);
    } 

  } 
  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    for (int i = data_.size()/2 ; i >=0 ; --i){
      MinHeap(i);
    }

      
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
