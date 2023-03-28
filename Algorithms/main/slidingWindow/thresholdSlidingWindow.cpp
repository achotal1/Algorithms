class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int windowStart(0), c(0), sum(0),avg(0);
        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
            sum += arr[windowEnd];
            int windowlen = windowEnd - windowStart + 1;
            avg = sum/windowlen;
            
            if(windowlen == k){
                sum -= arr[windowStart];
                windowStart++;
                if(avg >= threshold){
                   c++;
                }
            }
            
        }
        return c;
    }
};