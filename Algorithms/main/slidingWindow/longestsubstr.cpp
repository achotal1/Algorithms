class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int start = 0;
        int maxsize = 0;
        for(int end = 0; end<s.length(); end++){
            m[s[end]]++;
            while(m[s[end]] > 1){
                m[s[start]]--;
                start++;
            }
            int size = end - start + 1;
            maxsize = max(maxsize, size);

        }
        return maxsize;
    }
};