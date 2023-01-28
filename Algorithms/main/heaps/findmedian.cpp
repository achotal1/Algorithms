using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 public:
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  void insertNum(int num) {
    // add to max heap, then to min. If max heap has more then add to min and vice versa
    if(max_heap.empty() || max_heap.top() >= num ){
      max_heap.push(num);
    }
    else{
      min_heap.push(num);
    }

    if(max_heap.size() > min_heap.size() + 1){
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
    else if(min_heap.size() > max_heap.size()){
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double findMedian() {
    if((max_heap.size() + min_heap.size())%2 == 0){
      return (max_heap.top() + min_heap.top())/2.0;
    }
    else{
      return max_heap.top();
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
