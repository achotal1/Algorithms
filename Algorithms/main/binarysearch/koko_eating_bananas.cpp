class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int right = 0;
      int left = 1;
      for(auto i: piles){
        right = max(right, i);
      }
      int hours = 0;
      int mn = std::numeric_limits<int>::max();
      while(left <= right){
        int mid = (left + right)/2;
        if(possibleHours(piles, h, mid)){
          right = mid - 1;
          mn = min(mn, mid);
        }else{
          left = mid + 1;
        }
      }

      return mn;
    }
    bool possibleHours(vector<int> piles, int h, int rate){
      int hours = 0;
      for(int i = 0; i<piles.size(); i++){
        hours += ceil((double)piles[i]/rate);
        if(hours > h)return false;
        if(i == piles.size() - 1)return true;
      }
      return false;
    }
};