class Solution {
private:
    struct TrieNode {
        TrieNode* links[26];
        bool flag = false;
        string word = "";

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
    vector<string> ans;

    // insert word
    void insert(string word) {
        TrieNode* node = root;
        for(auto x : word) {
            if(!node->containsKey(x)) node->put(x, new TrieNode());
            node = node->get(x);
        }
        node->setEnd();
        node->word = word;
    }
    
    // search words
    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* node) {
        // invalid index of row or col
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;

        // visited
        if(board[row][col] == '#') return;

        // char doesn't match
        if (!node->containsKey(board[row][col])) return;

        // move to child node
        node = node->get(board[row][col]);

        // word found
        if (node->isEnd()){ 
            ans.push_back(node->word);
            node->flag = false; // avoid duplicate words
        }

        // visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all 4 directions
        dfs(board, row + 1, col, node); // down
        dfs(board, row - 1, col, node); // up
        dfs(board, row, col + 1, node); // right
        dfs(board, row, col - 1, node); // left

        // Backtrack
        board[row][col] = temp;

        return;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto x : words) insert(x);
        
        // use each char as starting point
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) dfs(board, i, j, root);
        }

        return ans;
    }
};