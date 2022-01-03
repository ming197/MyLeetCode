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
    unordered_map<string, int> status_table;
    int WIN = 1, LOSE = 2, DRAW = 0;
    int catMouseGame(vector<vector<int>>& graph) {
        int mouse_pos = 1, cat_pos = 2, hole = 0, totalMoves = 0;
        return playRecurse(graph, mouse_pos, cat_pos, hole, totalMoves);
    }

    int playRecurse(vector<vector<int>>& graph, int mouse_pos, int cat_pos, int hole, int totalMoves){
        if(totalMoves > 2 * graph.size()){
            // all nodes are visited, now if cat or mouse visit a node it would mean that they are repeating again and again to WIN.
            return DRAW;
        }
        if(mouse_pos == cat_pos) return LOSE;
        if(mouse_pos == hole) return WIN;
        
        string status = to_string(mouse_pos) + " " + to_string(cat_pos) + " " + to_string(totalMoves);

        if(status_table.find(status) != status_table.end()) return status_table[status];

        if(totalMoves % 2 == 0){ // mouse's turn
            // to check if we can draw the game, better than a lose
			bool canDraw = false;

            for(int adj_node : graph[mouse_pos]){
                int playResult = playRecurse(graph, adj_node, cat_pos, hole, totalMoves + 1);
                if(playResult == WIN){
                    status_table[status] = WIN;
                    return WIN;
                }
                if(playResult == DRAW) canDraw = true;
            }

            if(canDraw){
                status_table[status] = DRAW;
                return DRAW;
            }

            status_table[status] = LOSE;
            return LOSE;
        }else { // cat's turn
            bool canDraw = false;

            for(int adj_node : graph[cat_pos]){
                if (adj_node == hole) {
                    continue; // cat cannot travel to the Hole
                }
                int playResult = playRecurse(graph, mouse_pos, adj_node, hole, totalMoves + 1);
                if(playResult == LOSE){
                    status_table[status] = LOSE;
                    return LOSE;
                }
                if(playResult == DRAW) canDraw = true;
            }

            if(canDraw){
                status_table[status] = DRAW;
                return DRAW;
            }

            status_table[status] = WIN;
            return WIN;
        }
    }
};
// @lc code=end

