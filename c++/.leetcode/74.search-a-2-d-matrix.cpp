/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m;
        while (l < r)
        {
            /* code */
            int mid = l + ((r - l) >> 1);
            int low_bound = matrix[mid][0], up_bound = matrix[mid][n-1];
            if(target < low_bound){
                r = mid;
            }else if(target > up_bound){
                l = mid + 1;
            }else{
                int low = 0, high = n;
                while (low < high)
                {
                    /* code */
                    int mid_ = low + ((high - low )>> 1);
                    int value = matrix[mid][mid_];
                    if(value == target) return true;
                    if(value < target){
                        low = mid_ + 1;
                    }else{
                        high = mid_;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

