/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class MyHashMap {
private:
    vector<list<pair<int, int>>> cache;
    static const int base = 1 << 13;
    static const int mask =  base - 1;
    static int hash(int key) {
        key ^= (key >> 16);
        return key & mask;
    }
public:
    MyHashMap(): cache(base) {
        
    }
    
    void put(int key, int value) {
        int h = hash(key);
        for(auto it = cache[h].begin(); it != cache[h].end(); it++){
            if(it->first == key){
                it->second = value;
                return;
            }
        }
        cache[h].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int h = hash(key);
        for(auto it = cache[h].begin(); it != cache[h].end(); it++){
            if(it->first == key){
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        for(auto it = cache[h].begin(); it != cache[h].end(); it++){
            if(it->first == key){
                cache[h].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

