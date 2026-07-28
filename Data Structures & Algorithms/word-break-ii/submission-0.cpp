class Solution {
private:
    vector<string> ans;
    unordered_set<string> st;

    void solve(string &s, string &currSentence, int i) {
        if(i >= s.size()) {
            ans.push_back(currSentence);
            return;
        }

        for(int j = i; j < s.size(); j++) {
            string tempWord = s.substr(i, j - i + 1);
            if(st.count(tempWord)) { // valid word
                string tempSentence = currSentence; // store current sentence to backtrack to this later

                if(currSentence != "") currSentence += " "; // add space

                currSentence += tempWord; // add tempWord

                solve(s, currSentence, j + 1); // Explore

                currSentence = tempSentence; // remove tempWord
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto x : wordDict) st.insert(x);
        string currSentence = "";
        solve(s, currSentence, 0);
        return ans;
    }
};