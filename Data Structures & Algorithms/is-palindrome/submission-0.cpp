class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size(), first = 0, last = n - 1;
        while(first < last) {
            if(!isalnum(s[first])) first++;
            else if(!isalnum(s[last])) last--;
            else {
                if(tolower(s[first]) != tolower(s[last])) return false;
                first++;
                last--;
            }
        }
        return true;
    }
};