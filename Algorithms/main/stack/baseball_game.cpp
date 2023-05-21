class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i = 0; i< operations.size(); i++){
            if(operations[i] == "C"){
                st.pop();
            }else if(operations[i] == "D"){
                st.push(st.top()*2);
            }else if(operations[i] == "+"){
                int ans = st.top();
                st.pop();
                int s = ans + st.top();
                st.push(ans);
                st.push(s);
            }else{
                st.push(stoi(operations[i]));
            } 
        }
        return sum(st);
    }
    int sum(stack<int> st){
        int size = st.size();
        int sum = 0;
        for(int i = 0; i<size; i++){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};