using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    int sum = 0;
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
      sum += arr[windowEnd];
      if((windowEnd - windowStart + 1) == k){
        maxSum = max(maxSum, sum);
        sum = sum - arr[windowStart];
        windowStart++;
      }
    }
    return maxSum;
  }
};
