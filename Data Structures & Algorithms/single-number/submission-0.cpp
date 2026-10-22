class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int number, count = 0, temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            count++;
            temp = nums[i];
            if (nums[i] != nums[i - 1]) {
                if (count == 1) {
                    number = nums[i - 1];
                    break;
                }
                count = 0;
            }
        }

        if (count == 0) {
            number = temp;
        }

        return number;
    }
};