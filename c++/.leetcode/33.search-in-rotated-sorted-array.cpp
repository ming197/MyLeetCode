/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l < r)
        {
            /* code */
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == target) return mid;
            // sorted
            if(nums[l] < nums[r]){
                if(nums[mid] < target) l = mid + 1;
                else r = mid;
            }else{
                // rotated
                if(nums[mid] >= nums[l]){
                    if(nums[mid] < target){
                        l = mid + 1;
                    }else{
                        if(target >= nums[l]){
                            r = mid;
                        }else{
                            l = mid + 1;
                        }
                    }
                }else{
                    if(nums[mid] < target){
                        if(target >= nums[l]){
                            r = mid;
                        }else{
                            l = mid + 1;
                        }
                    }else{
                        r = mid;
                    }
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};
// @lc code=end

