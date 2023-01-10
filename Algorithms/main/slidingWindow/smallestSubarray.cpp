using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int mini = numeric_limits<int> :: max();
    int sum(0);
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
      sum += arr[windowEnd];
      while(sum >= S){
        sum -= arr[windowStart];
        mini = min(mini, windowEnd - windowStart + 1);
        windowStart++;
      }
    }
    return mini == numeric_limits<int>::max() ? 0 : mini;
  }
};

