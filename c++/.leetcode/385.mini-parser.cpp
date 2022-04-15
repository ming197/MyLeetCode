/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#include <bits/stdc++.h>
using namespace std;
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();
 
    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
 
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
class Solution {
    NestedInteger deserialize(string& s, int& i) {
       NestedInteger res;
       if(s[i] == '[') {
           while(s[i] != ']') {
               ++i;
               if(s[i] == ']') break;
               res.add(deserialize(s,i));
           }
           ++i;
       } else {
           int j = i;
           while(j < s.size() && s[j] != ',' && s[j] != ']') ++j;
           res.setInteger(stoi(s.substr(i, j-i)));
           i = j;
       }
       return res;
    }
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return deserialize(s, i);
    }
};
// @lc code=end

