// @before-stub-for-debug-begin


#include <bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=913 lang=cpp
 *
 * [913] Cat and Mouse
 */

// @lc code=start
class Solution {
public:
    vector<vector<vector<int>>> status;
    int MOUSE = 1, CAT = 2, DRAW = 0;
    int hole = 0;
    int catMouseGame(vector<vector<int>>& graph) {
        int mouse_pos = 1, cat_pos = 2, k = 0;
        int n = graph.size();
        status = vector<vector<vector<int>>>(2*n + 2, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(graph, mouse_pos, cat_pos, k);
    }

    int dfs(vector<vector<int>>& graph, int mouse_pos, int cat_pos, int k){
        if(status[k][mouse_pos][cat_pos] != -1) return status[k][mouse_pos][cat_pos];
        if(k > 2 * graph.size()) return DRAW;
        if(mouse_pos == hole) return MOUSE;
        if(mouse_pos == cat_pos) return CAT;
        
        if((k&1) == 0){ // mouse's turn
            // to check if mouse can draw the game, better than a lose
            bool canDraw = false;
            for(int adj : graph[mouse_pos]){
                int stat = dfs(graph, adj, cat_pos, k + 1);
                if(stat == MOUSE){
                    status[k][mouse_pos][cat_pos] = MOUSE;
                    return MOUSE;
                }
                if(stat == DRAW) canDraw = true;
            }
            if(canDraw){
                status[k][mouse_pos][cat_pos] = DRAW;
                return DRAW;
            }
            status[k][mouse_pos][cat_pos] = CAT;
            return CAT;
        }

        // cat's turn
        bool canDraw = false;
        // to check if cat can draw the game
        for(int adj : graph[cat_pos]){
            if(adj == hole) continue;
            int stat = dfs(graph, mouse_pos, adj, k + 1);
            if(stat == CAT){
                status[k][mouse_pos][cat_pos] = CAT;
                return CAT;
            }
            if(stat == DRAW) canDraw = true;
        }
        if(canDraw){
            status[k][mouse_pos][cat_pos] = DRAW;
            return DRAW;
        }
        status[k][mouse_pos][cat_pos] = MOUSE;
        return MOUSE;
    } 
};
// class Solution {
// public:
//     vector<vector<vector<int>>> status;
//     int MOUSE = 1, CAT = 2, DRAW = 0;
//     int hole = 0;
//     int catMouseGame(vector<vector<int>>& graph) {
//         int mouse_pos = 1, cat_pos = 2, k = 0;
//         int n = graph.size();
//         status = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(n, -1)));
//         return dfs(graph, mouse_pos, cat_pos, k);
//     }

//     int dfs(vector<vector<int>>& graph, int mouse_pos, int cat_pos, int k){
//         int turn = k&1;
//         if(status[turn][mouse_pos][cat_pos] != -1) return status[turn][mouse_pos][cat_pos];
//         if(k > 2 * graph.size()) return DRAW;
//         if(mouse_pos == hole) return MOUSE;
//         if(mouse_pos == cat_pos) return CAT;
        
//         if(turn == 0){ // mouse's turn
//             // to check if mouse can draw the game, better than a lose
//             bool canDraw = false;
//             for(int adj : graph[mouse_pos]){
//                 int stat = dfs(graph, adj, cat_pos, k + 1);
//                 if(stat == MOUSE){
//                     status[turn][mouse_pos][cat_pos] = MOUSE;
//                     return MOUSE;
//                 }
//                 if(stat == DRAW) canDraw = true;
//             }
//             if(canDraw){
//                 status[turn][mouse_pos][cat_pos] = DRAW;
//                 return DRAW;
//             }
//             status[turn][mouse_pos][cat_pos] = CAT;
//             return CAT;
//         }

//         // cat's turn
//         bool canDraw = false;
//         // to check if cat can draw the game
//         for(int adj : graph[cat_pos]){
//             if(adj == hole) continue;
//             int stat = dfs(graph, mouse_pos, adj, k + 1);
//             if(stat == CAT){
//                 status[turn][mouse_pos][cat_pos] = CAT;
//                 return CAT;
//             }
//             if(stat == DRAW) canDraw = true;
//         }
//         if(canDraw){
//             status[turn][mouse_pos][cat_pos] = DRAW;
//             return DRAW;
//         }
//         status[turn][mouse_pos][cat_pos] = MOUSE;
//         return MOUSE;
//     } 
// };
// @lc code=end

