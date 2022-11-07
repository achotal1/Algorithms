using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int windowStart(0);
    int mini = numeric_limits<int>::max();
    int sum(0);
    for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
      sum += arr[windowEnd];
      while(sum >= S){
        mini = min(mini, windowEnd - windowStart + 1);
        sum -= arr[windowStart];
        windowStart++;
      }
    }
    return mini;
  }
  static int MinSubArrayLen(int target, vector<int>& nums){
    int sum = 0; int windowStart(0);
    int mini = numeric_limits<int>::max();
    int c = 0;
    for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
        sum += nums[windowEnd];  
        while(sum >= target && windowStart <= windowEnd){
            if(sum == target){
                mini = min(mini, windowEnd - windowStart + 1);
                c = 1;
            }
            sum -= nums[windowStart];
            windowStart++;
        }
    }
    if(c==0){
       return 0;
    }
    return mini;
    }
};
