/*
Given an array of unsorted numbers, find all unique triplets in it that add up to zero.

Example 1:

Input: [-3, 0, 1, 2, -1, 1, -2]
Output: [-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]
Explanation: There are four unique triplets whose sum is equal to zero.


*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<arr.size() - 2; i++){
      if(i > 0 && arr[i] == arr[i-1]){
        continue;
      }
      findTriplet(arr, -arr[i], i+1, triplets);
    }
    return triplets;
  }
  static void findTriplet(vector<int> &arr, int target, int left, vector<vector<int>> &triplets){
    int right = arr.size() - 1;
    while(left < right){
      //vector<int> v;
      int calc = arr[left] + arr[right];
      if(calc == target){
        //v.push_back(arr[target]);
        //v.push_back(arr[left]);
        //v.push_back(arr[target]);
        triplets.push_back({-target, arr[left], arr[right]});
        left++;
        right--;
        while(left < right && arr[left] == arr[left - 1]){
          left++;
        }
        while(left < right && arr[right] == arr[right + 1]){
          right--;
        }
      }
      else if(calc > target){
        right--;
      }
      else{
        left++;
      }
    }
    return;

  }
};
  