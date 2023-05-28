using namespace std;

#include <iostream>
#include <vector>
#include <cmath>
class Subsets {
 public:
  static vector<vector<int>> findSubsetsBitwise(const vector<int>& nums) {
    vector<vector<int>> subsets;
    for(int i = 0; i<pow(2, nums.size()); i++){
      vector<int> vec;
      for(int j = 0; j < nums.size(); j++){
        if((i&(1<<j)) != 0){
          vec.push_back(nums[j]);
        }
      }
      subsets.push_back(vec);
    }
    return subsets;
  }
  static vector<vector<int>> findSubsetsBFS(const vector<int>& nums){
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());
    for(auto a: nums){
      // memory limit exceeded if I don't make a n and put size directly in for loop. Probably because it
      // calculates size every time size() is called
      int n = subsets.size();
      for(int i = 0; i<n;i++){
        vector<int> vec(subsets[i]);
        vec.push_back(a);
        subsets.push_back(vec);
      }
    }
    return subsets;
  }
  vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        subsetsRecurse(res, 0, nums, sub);
        return res;
    }
    void subsetsRecurse(vector<vector<int>> &res,int i, vector<int> nums, vector<int>& sub){
        if(i >= nums.size()){
            res.push_back(sub);
            return;
        }
        
        sub.push_back(nums[i]);
        subsetsRecurse(res, i+1 , nums, sub);
        sub.pop_back();
        subsetsRecurse(res, i+1, nums, sub);
        
    }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsetsBFS(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsetsBFS(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
