/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
struct Trie {
    unordered_map<char, Trie *> children;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie();
        for (auto &word : dictionary) {
            Trie *cur = trie;
            for (char &c: word) {
                if (!cur->children.count(c)) {
                    cur->children[c] = new Trie();
                }
                cur = cur->children[c];
            }
            cur->children['#'] = new Trie();
        }
        vector<string> words = split(sentence, ' ');
        for (auto &word : words) {
            word = findRoot(word, trie);
        }
        string ans;
        for (int i = 0; i < words.size() - 1; i++) {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back());
        return ans;
    }

    vector<string> split(string &str, char ch) {
        int pos = 0;
        int start = 0;
        vector<string> ret;
        while (pos < str.size()) {
            while (pos < str.size() && str[pos] == ch) {
                pos++;
            }
            start = pos;
            while (pos < str.size() && str[pos] != ch) {
                pos++;
            }
            if (start < str.size()) {
                ret.emplace_back(str.substr(start, pos - start));
            }
        }
        return ret;
    }

    string findRoot(string &word, Trie *trie) {
        string root;
        Trie *cur = trie;
        for (char &c : word) {
            if (cur->children.count('#')) {
                return root;
            }
            if (!cur->children.count(c)) {
                return word;
            }
            root.push_back(c);
            cur = cur->children[c];
        }
        return root;
    }
};
// @lc code=end

