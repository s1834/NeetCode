class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        int ans = 0, sum = 0;
        prefix[sum]++;
        for(auto x : nums) {
            sum += x;
            if(prefix.find(sum - k) != prefix.end()) ans += prefix[sum - k];
            prefix[sum]++;
        }

        return ans;
    }
};