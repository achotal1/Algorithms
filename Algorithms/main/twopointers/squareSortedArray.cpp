// square a sorted array having negative numbers and without the sort()


using namespace std;

#include <iostream>
#include <vector>
#include<algorithm>
class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    int right = 0, left = 0;
    for(int i = 0; i<n; i++){
      if(arr[i] >= 0){
        right = i;
        left = i - 1;
        break;
      }
    }
    int i = 0;
    while(left != -1 && right != n){
      int leftcalc = arr[left]*arr[left];
      int rightcalc = arr[right]*arr[right];
      //cout<<"leftcalc: "<<leftcalc<<"rightcalc: "<<rightcalc<<endl;
      //cout<<"left : "<<left<<"right: "<<right<<endl;
      if(leftcalc < rightcalc){
        squares[i] = leftcalc;
        cout<<squares[i]<<endl;
        i++;
        left--;
      }
      else{
        squares[i] = rightcalc;
        i++;
        right++;
      }
  
    }
    //cout<<right<<n-1<<endl;
    while(left != -1){
      squares[i] = arr[left]*arr[left];
      i++;
      left--;
    }
    if(right != n){
      //cout<<"i: "<<i<<endl;
      for(int j = i; j<n; j++){
        squares[i] = arr[right] * arr[right];
      }
    }
    
    return squares;
  }
};
