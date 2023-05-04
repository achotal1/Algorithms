class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0){
            if(n&1 == 1){
                count++;
            }
            n >>= 1;
        }
        return count;
    }
    int hammingWeightAnd(uint32_t m){
        int count = 0;
        while(m > 0){
            m &= (m-1);
            count++;
        }
        return count;
    }
    
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        int c(0);
        while(n>=0){
            int m = n;
            c = 0;
            while(m){
                m &= (m-1);
                c++;
            }
            res.push_back(c);
            n -= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};