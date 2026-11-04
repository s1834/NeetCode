class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        vector<int> result;

        vector<int> lastOccurance(26, -1); // last occurance of each character;
        for(int i = 0; i < n; i++) lastOccurance[s[i] - 'a'] = i;

        int i = 0;
        int start = 0, end = 0;
        while(i < n) {
            end = max(end, lastOccurance[s[i] - 'a']);
            if(i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }

        return result;
    }
};