class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                int left = j + 1, right = n - 1;
                long long sum = nums[i] + nums[j];
                while(left < right) {
                    if(sum + nums[left] + nums[right] > target) right--;
                    else if(sum + nums[left] + nums[right] < target) left++;
                    else {
                        st.insert({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                }
            }
        }

        vector<vector<int>> ans;
        for(auto x : st) ans.push_back(x);

        return ans;
    }
};