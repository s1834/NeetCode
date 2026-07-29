class Solution {
private:
    struct TrieNode {
        TrieNode* links[26];
        bool flag = false;

        // check if 'c' already exists
        bool containsKey(char c) {
            return links[c - 'a'] != NULL;
        };

        // from 'c' create a new empty node
        void put(char c, TrieNode* node) {
            links[c - 'a'] = node;
        }

        // move current pointer to newly created node
        TrieNode* get(char c) {
            return links[c - 'a'];
        }

        // if word complete, set flag = true;
        void setEnd() {
            flag = true;
        }
        
        // check if a word ends here
        bool isEnd() {
            return flag;
        }
    };

    // initialize Trie node
    TrieNode* root = new TrieNode();
    vector<int> dp;

    // insert word
    void insert(string word) {
        TrieNode* node = root;
        for(auto x : word) {
            if(!node->containsKey(x)) node->put(x, new TrieNode());
            node = node->get(x);
        }
        node->setEnd();
    }
    

    int search(string &s, int i) {
        // if i is greater than equal to the word itself return 0
        if(i >= s.size()) return 0; 

        // If we've already computed the answer for this index, return the stored result.
        if(dp[i] != -1) return dp[i];

        // assign node to root to use
        TrieNode* node = root;

        // Search without current char, add 1 to count
        int ans = 1 + search(s, i + 1);

        for(int j = i; j < s.size(); j++) {
            if(!node->containsKey(s[j])) break; // if not word, break

            node = node->get(s[j]); // move to next word

            if (node->isEnd()) ans = min(ans, search(s, j + 1)); // if word ends, get the smaller value from current and next recursion
        }

        // Store the answer for this index, so we don't recompute it later.
        return dp[i] = ans;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // insert each word in Trie
        for(auto x : dictionary) insert(x);

        dp.assign(s.size(), -1);

        // Search Trie
        return search(s, 0);;
    }
};