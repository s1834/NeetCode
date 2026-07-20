class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0, left = 0, right = people.size() - 1;
        while(left <= right) {
            if(left == right){
                boats++;
                break;
            } else if(people[left] + people[right] <= limit) {
                boats++;
                left++;
                right--;
            } else {
                boats++;
                right--;
            }
        }
        
        return boats;
    }
};