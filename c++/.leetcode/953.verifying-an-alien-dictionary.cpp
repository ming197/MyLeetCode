#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.size();
        unordered_map<char, int> ch2Int;
        for(int i = 0; i < n; i++){
            ch2Int[order[i]] = i;
        }

        for(int i = 0; i + 1 < words.size(); i++){
            string s1 = words[i], s2 = words[i + 1];
            int p1 = 0, p2 = 0;
            while(p1 < s1.size() && p2 < s2.size()){
                if(ch2Int[s1[p1]] > ch2Int[s2[p2]]) return false;
                else if(ch2Int[s1[p1]] < ch2Int[s2[p2]]) break;
                p1++;p2++;
            }
            if(p2 == s2.size() && s1.size() > s2.size()) return false;
        }
        return true;
    }
};