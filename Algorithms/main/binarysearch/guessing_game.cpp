class Solution {
public:
    int guessNumber(int n) {
        return helper(1, n);
    }
    int helper(unsigned int start, unsigned int end){
        unsigned int mid = (start + end)/2;
        if(guess(mid) == 1){
            return helper(mid + 1, end);
        }
        else if(guess(mid) == -1){
            return helper(start, mid - 1);
        }
        else{
            return mid;
        }

    }
};