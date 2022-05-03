#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int min_num = INT_MAX, max_num = INT_MIN, 
            left_end = 0 , right_end = -1; 
        
        // Find the left end of the smallest unsorted continuous subarray
        for(int i=nums.size()-1; i>=0; i--){
            
            // If current num is NOT less than or equal to all elements on right,
            // Current num is left most element of the unsorted subarray.
            if(nums[i]>min_num)
                left_end = i;
            
            min_num = min(min_num, nums[i]);
        }
        
        // Find the right end of the smallest unsorted continuous subarray
        for(int i=0; i<nums.size(); i++){
            
            // If current num is NOT greater than or equal to all elements on left,
            // Current num is right most element of the unsorted subarray.
            if(nums[i]<max_num)
                right_end = i;
            
            max_num = max(max_num, nums[i]);
        }
        
        // Return the length of unsorted continuous subarray
        return right_end - left_end + 1;
    }
};