class Solution {
public:
    int maxVowels(string s, int k) {
        string vow = "aeiou";
        int windowStart(0);
        int count(0), numberVowels(0);
        for(int end = 0; end<s.length(); end++){
            if(vow.find(s[end])<vow.length()){
                count++;
            }
            if(end - windowStart + 1 == k){
                numberVowels = max(numberVowels, count);
                if(vow.find(s[windowStart])<vow.length()){
                    count--;
                }
                windowStart++;
            }
        }
        return numberVowels;
    }
};