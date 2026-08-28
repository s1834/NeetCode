class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        int size = nums.size(), count = 1;
        vector <int> number;
        
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[i -1]) {
                if (count > size / 3) {
                    number.push_back(nums[i - 1]);
                }
                count = 1;
            } else {
                count++;
            }
        }

        if (count > size / 3) {
            number.push_back(nums[size - 1]);
        }

        return number;
    }
};