class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> freq;
        int windowStart(0),maxsize(0),kcount(k);
        for(int windowEnd = 0; windowEnd < s.length(); windowEnd++){
            freq[s[windowEnd]]++;
            if(freq.size() > 1){
                int maxcount(0), index(-1);
                for(auto c: freq){
                    if(maxcount < c.second){
                        index =  c.first;
                        maxcount = c.second;
                    }
                }
                int sum = 0;
                for(auto c: freq){
                    if(c.first == index){
                        continue;
                    }
                    sum = sum + c.second;
                }
                if(sum <= k){
                    maxsize = max(maxsize, windowEnd - windowStart + 1);
                }
                else{
                    freq[s[windowStart]]--;
                    if(freq[s[windowStart]] == 0){
                        freq.erase(s[windowStart]);
                    }
                    windowStart++;
                }
            }
            else{
                maxsize = max(windowEnd - windowStart + 1, maxsize);
            }

        }
        return maxsize;
    }
    
};
