/* Given an array of sorted numbers and a target sum, find a pair in the array whose sum is equal to the given target.
Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.
*/

#include<iostream>
#include<vector>
using namespace std;

class twoPointer {
public:
	// 1 4 7 8
	static pair<int, int> search(const vector<int>& v, int targetSum) {
		int ptr1(0), ptr2(v.size() - 1);
		int sum(0);
		while (sum != targetSum) {
			if (v[ptr1] + v[ptr2] == targetSum) {
				sum = targetSum;
			}
			else if (v[ptr1] + v[ptr2] > targetSum) {
				ptr2--;
			}
			else if (v[ptr1] + v[ptr2] < targetSum) {
				ptr1++;
			}
		}
		return make_pair(ptr1, ptr2);
	}

};
int main() {
	vector<int, int> v = [1, 2, 3, 4, 6];
	int targetSum = 6;
	pair<int, int> result;
	result = twoPointer search(v, targetSum);
	cout << result;
	return 0;
}