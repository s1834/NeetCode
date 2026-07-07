class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, leftMax = height[0], rightMax = height[r], water = 0;
        while(l < r) {
            if(leftMax <= rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                water += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                water += rightMax - height[r];
            }
        }
        return water;
    }
};