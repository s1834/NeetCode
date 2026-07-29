class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto x : bills) {
            if(x == 5) five++;
            else if(x == 10) {
                if(!five) return false;
                five--;
                ten++;
            } else {
                int need = 20;
                if(ten) {
                    ten--;
                    if(five) five--;
                    else return false;
                } else {
                    if(five >= 3) five -= 3;
                    else return false;
                }
            }
        }
        return true;
    }
};