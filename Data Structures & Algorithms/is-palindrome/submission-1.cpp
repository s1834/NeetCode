class Solution {
public:
    bool isPalindrome(string s) {
        string converted = "";
        for(auto &ch : s) {
            if(isalnum(ch)) converted += tolower(ch);
        }

        string reversed = converted;
        reverse(reversed.begin(), reversed.end());

        return converted == reversed;
    }
};