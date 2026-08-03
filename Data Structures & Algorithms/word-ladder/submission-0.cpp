class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end()); // wordList

        queue<pair<string, int>> q; // queue<pair<word, BFS level>> q
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            if(word == endWord) return level; // endWord found

            int n = word.size();
            // replace each char of the word with each char from 'a' to 'z'
            for(int i = 0; i < n; i++) {
                char curr = word[i];
                for(char j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, level + 1});
                    }
                }
                word[i] = curr; // backtrack
            }
        }
        
        return 0;
    }
};