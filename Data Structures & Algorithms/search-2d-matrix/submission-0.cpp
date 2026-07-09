class Solution {
    bool searchRow(vector<vector<int>>& matrix, int target, int left, int right) {
        if(left > right) return false;

        int mid = left + (right - left) / 2;
        if(matrix[mid][0] <= target && target <= matrix[mid][matrix[mid].size() - 1]) return searchColumn(matrix[mid], target, 0, matrix[mid].size() - 1);
        else if(matrix[mid][0] < target) return searchRow(matrix, target, mid + 1, right);
        else return searchRow(matrix, target, left, mid - 1);

    }

    bool searchColumn(vector<int>& column, int target, int left, int right) {
        if(left > right) return false;

        int mid = left + (right - left) / 2;
        if(column[mid] == target) return true;
        else if(column[mid] < target) return searchColumn(column, target, mid + 1, right);
        else return searchColumn(column, target, left, mid - 1);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchRow(matrix, target, 0, matrix.size() - 1);
    }
};