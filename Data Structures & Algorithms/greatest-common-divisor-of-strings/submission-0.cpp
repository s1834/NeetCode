class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if both of them match
        if (str1 + str2 != str2 + str1) return "";

        // substring of gcd of both the lengths divides both of them
        return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};