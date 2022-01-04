/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int& item : asteroids){
            
            while (!res.empty() && res.back() > 0 && res.back() < -item)
            {
                /* code */
                res.pop_back();
            }

            if(!res.empty() && res.back() > 0 && res.back() == -item){
                res.pop_back();
            }else if(res.empty() || item > 0 || res.back() < 0){
                res.push_back(item);
            }
           
        }
        return res;
    }
};
// @lc code=end

