class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        // for(int i = 0; i<32; i++){
        //     uint32_t bit = 1 & (n>>i);
        //     res = res | (bit<<(31-i));
        // }
        int i = 0;
        while(n>0){
            uint32_t bit = 1 & (n);
            res = res | (bit<<(31-i));
            n >>= 1;
            i++;
        }
        return res;
    }
};