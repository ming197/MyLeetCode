#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<string, int> str2int;
        for(auto& word : words){
            int x = 0;
            for(char& c : word){
                x |= (1 << (c - 'a'));
            }
            str2int[word] = x;
        }
        int res = 0;
        for(int i = 0; i < words.size(); i++){
            for(int j = i + 1; j < words.size(); j++){
                if((str2int[words[i]] & str2int[words[j]]) == 0){
                    res = max((int)(words[i].size() * words[j].size()), res);
                }
            }
        }
        return res;
    }
};