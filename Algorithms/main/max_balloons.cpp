class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(int i = 0; i<text.length(); i++){
            m[text[i]]++;
        }
        m['l'] = m['l']/2;
        m['o'] = m['o']/2;
        int mn = std::numeric_limits<int>::max();
        string bal = "balloon";
        for(int i = 0; i<bal.length(); i++){
            mn = min(m[bal[i]], mn);
        }
        return mn;
    }
};