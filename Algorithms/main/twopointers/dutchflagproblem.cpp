/*
Given an array containing 0s, 1s and 2s, sort the array in-place.
 You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s 
to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; 
and since our input array also consists of three different numbers 
that is why it is called Dutch National Flag problem.

Example 1:

Input: [1, 0, 2, 1, 0]
Output: [0, 0, 1, 1, 2]
*/


using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
 public:
  static void sort(vector<int> &arr) {
    int low = 0, high = arr.size()-1; 
    for(int i = 0; i<=high;){
      if(arr[i] == 0){
        swap(arr, low, i);
        low++;
        i++;
      }
      else if(arr[i] == 1){
        i++;
      }
      else{
        swap(arr, high, i);
        high--;
      }
    }
  }
  static void swap(vector<int> &arr, int low, int i){
    int temp = 0;
    temp = arr[i];
    arr[i] = arr[low];
    arr[low] = temp;
  }
};

/*
2, 2, 0, 1, 2, 0
0, 2, 0, 1, 2, 2
0, 2, 0, 1, 2, 2
0, 2, 0, 1, 2, 2
0, 1, 0, 2, 2, 2
0, 1, 0, 2, 2, 2
0, 0, 1, 2, 2, 2
*/