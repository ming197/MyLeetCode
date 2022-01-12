/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
 */

// @lc code=start
class Solution {
public:
    const int up_bound = 1e6;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<string> set;   
        set.insert(posToStr(0, 0));
        queue<pair<int, int>> q;
        q.push(make_pair(source[0], source[1]));
        while (!q.empty())
        {
            /* code */
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int next_x = x + dx[i];
                int next_y = y + dy[i];
                if(0 <= next_x && next_x < up_bound && 0 <= next_y && next_y < up_bound && set.find(posToStr(next_x, next_y)) == set.end()){
                    if(next_x == target[0] && next_y == target[1]) return true;
                    q.push(make_pair(next_x, next_y));
                    set.insert(posToStr(next_x, next_y));
                }
            }
        }
        return false;
    }

    string posToStr(int x, int y){
        return to_string(x) + "-" + to_string(y);
    }
};
// @lc code=end

