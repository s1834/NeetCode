class Solution {
private:
    vector<string> ans;
    stack<char> st;

    void backtrack(int n, int open, int close) {
        if(open == n && close == n) {
            stack<char> temp = st;
            string s = "";
            while(!temp.empty()) {
                s += temp.top();
                temp.pop();
            }
            reverse(s.begin(), s.end());
            ans.push_back(s);
        }

        if(open < n) {
            st.push('(');
            backtrack(n, open + 1, close);
            st.pop();
        }

        if(close < open) {
            st.push(')');
            backtrack(n, open, close + 1);
            st.pop();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0);
        return ans;
    }
};