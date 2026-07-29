class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i = 0; i < order.size(); i++) mp[order[i]] = i;

        int n = words.size();
        for(int i = 0; i < n - 1; i++) {
            string word1 = words[i], word2 = words[i + 1];
            int m = word1.size(); 
            for(int j = 0; j < m; j++) {
                if(j == word2.size()) return false;
                if (word1[j] != word2[j]) {
                    if (mp[word1[j]] > mp[word2[j]]) return false;
                    break;
                }
            }
        }
        return true;
    }
};