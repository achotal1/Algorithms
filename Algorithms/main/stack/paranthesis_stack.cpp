class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i<s.length(); i++){
            if(st.empty())
            {
                st.push(s[i]);
            }
            else{
                if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                }else if(st.top() == '[' && s[i] == ']'){
                    st.pop();
                }else if(st.top() == '{' && s[i] == '}'){
                    st.pop();
                }else if(s[i] != '}' && s[i] != ']' && s[i] != ')'){
                    st.push(s[i]);
                }
            }
            
        }
        return st.empty();
    }
};