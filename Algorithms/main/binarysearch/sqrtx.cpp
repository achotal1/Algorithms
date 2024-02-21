class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
        return x;
        long long int left = 0, right = x+1;
        while(left < right){
            long long int mid = left + (right - left)/2;
            if(mid*mid > x){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return (int)left - 1;
    }
};