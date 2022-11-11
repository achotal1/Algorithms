/*
Given an array of unsorted numbers and a target number, 
find all unique quadruplets in it, whose sum is equal to the target number.

Example 1:

Input: [4, 1, 2, -1, 1, -3], target=1
Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
Explanation: Both the quadruplets add up to the target.

*/


using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class QuadrupleSumToTarget {
 public:
  static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    vector<vector<int>> quadruplets;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<arr.size() - 3; i++){
      if(i>0 && arr[i] == arr[i-1]){
        continue;
      }
      cout<<"Target - arr[i] = "<<target - arr[i]<<endl;
      findQuad(arr, target - arr[i], i, quadruplets);
    }
    return quadruplets;
  }
  static void findQuad(const vector<int> &arr, int target, int idx, vector<vector<int>> &quadruplets){
    int targetPrev = arr[idx];
    int left(0),right(0);
    for(int i = idx + 1; i< arr.size()-2; i++){
      if(i > (idx + 1) && arr[i] == arr[i-1]){
        continue;
      }
      left = i+1;
      right = arr.size() - 1;
      int temptarget = target - arr[i];
      while(left<right){    
      if(arr[left] + arr[right] == temptarget){
        cout<<"second element: "<<arr[i]<<endl;
        quadruplets.push_back({targetPrev, arr[i], arr[left], arr[right]});
        left++;
        right--;
        while (left < right && arr[left] == arr[left - 1]) {
          left++; 
        }
        while (left < right && arr[right] == arr[right + 1]) {
          right--;  
        }
      }
      else if(arr[left] + arr[right] > temptarget){
        right--;
      }
      else{
        left++;
      }

      }
      
    }

  }
};
/*
4, 1, 2, -1, 1, -3
-3 -1 1 1 2 4
X + Y + Z + P = T
Y + Z + P = T - X
*/