class PrefixTree {
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

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    // insert word
    void insert(string word) {
        TrieNode* node = root;
        for(auto x : word) {
            if(!node->containsKey(x)) node->put(x, new TrieNode());
            node = node->get(x);
        }
        node->setEnd();
    }
    
    // search complete word
    bool search(string word) {
        TrieNode* node = root;
        for(auto x : word) {
            if(!node->containsKey(x)) return false;
            node = node->get(x);
        }
        return node->isEnd();
    }
    
    // search only if a prefix exists
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(auto x : prefix) {
            if(!node->containsKey(x)) return false;
            node = node->get(x);
        }
        return true;
    }
};