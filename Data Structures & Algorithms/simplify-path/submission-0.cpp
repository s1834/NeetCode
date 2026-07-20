class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();

        for (int i = 0; i < n; ) {
            // ignore // and ///
            while (i < n && path[i] == '/') i++;

            // store directory name in s
            string s = "";
            while (i < n && path[i] != '/') {
                s += path[i];
                i++;
            }

            // if current folder(.) or s empty contiue
            if (s == "" || s == ".") continue;
            // if "..", go one folder back
            else if (s == "..") {
                if (!st.empty()) st.pop();
            }
            else st.push(s);
        }

        // return root
        if (st.empty()) return "/";

        vector<string> v;
        while (!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(), v.end());

        // add slach before and return ans
        string ans = "";
        for (string x : v) ans += "/" + x;

        return ans;
    }
};