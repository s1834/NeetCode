class Solution {
private:
    int n;
    vector<int> nextIdx;
    vector<int> dp;

    int findNext(vector<vector<int>>& intervals, int endPoint) {
        int left = 0, right = n - 1;
        int result = n;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(intervals[mid][0] >= endPoint) {
                result = mid;
                right = mid - 1;
            } else left = mid + 1;
        }

        return result;
    }

    int solve(vector<vector<int>>& intervals, int i) {
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = 1 + solve(intervals, nextIdx[i]);
        int skip = solve(intervals, i + 1);

        return dp[i] = max(take, skip);
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        n = intervals.size();
        sort(intervals.begin(), intervals.end());

        dp.assign(n, -1);

        nextIdx.resize(n);
        for(int i = 0; i < n; i++) nextIdx[i] = findNext(intervals, intervals[i][1]);

        return n - solve(intervals, 0);
    }
};