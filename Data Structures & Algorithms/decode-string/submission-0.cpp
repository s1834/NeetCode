class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                string num = "";
                while (i < n && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                st.push(num);
                i--;
            } else if(s[i] == ']') {
                string temp = "";
                while(st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                int x = stoi(st.top());
                st.pop();
                string t = "";
                while(x--) t += temp;
                st.push(t);
            } else st.push(string(1, s[i]));
        }

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};