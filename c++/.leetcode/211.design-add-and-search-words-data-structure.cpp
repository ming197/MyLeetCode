/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    /* data */
    bool endOfWord = false;
    Node* next[26];
};

class WordDictionary {
public:
    Node* root = nullptr;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* p = root;
        for(char& c : word){
            if(!p->next[c - 'a']){
                p->next[c - 'a'] = new Node();
            }
            p = p->next[c - 'a'];
        }
        p->endOfWord = true;
    }
    
    bool search(string word) {
        queue<Node*> q;
        q.push(root);
        for(int k = 0; k < word.size(); k++){
            char c = word[k];
            int n = q.size();
            for(int j = 0; j < n; j++){
                Node* p = q.front();q.pop();
                if(c == '.'){
                    for(int i = 0; i < 26; i++){
                        if(p->next[i] != nullptr){
                            q.emplace(p->next[i]);
                        }
                    }
                }else{
                    for(int i = 0; i < 26; i++){
                        if(p->next[i] != nullptr && (i == c - 'a')){
                            q.emplace(p->next[i]); break;
                        }
                    }
                }
            } 
            if(q.empty()) return false;
        }
        int n = q.size();
        for(int i = 0; i < n; i++){
            Node* p = q.front();q.pop();
            if(p->endOfWord) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

