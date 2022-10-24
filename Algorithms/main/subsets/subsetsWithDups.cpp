using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());
    for(auto currentNumber: nums){
      int n = subsets.size();
      for(int i = 0; i< n; i++){
        vector<int> v(subsets[i]);
        v.push_back(currentNumber);
        auto it = find(subsets.begin(), subsets.end(), v);
        if(it == subsets.end()){
          subsets.push_back(v);
        }
      }
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
