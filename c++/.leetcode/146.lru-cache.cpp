/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
struct DLinkedNode{
    /* data */
    int key;
    int val;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(int key, int val){
        this->key = key;
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
public:

    int capacity;
    // DLinkedNode *head, *tail;
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head = new DLinkedNode(-1, -1);
    DLinkedNode* tail = new DLinkedNode(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1;
        auto node = it->second;
        deleteNode(node);
        addToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it != cache.end()){
            it->second->val = value;
            deleteNode(it->second);
            addToHead(it->second);
        }else{
            auto node = new DLinkedNode(key, value);
            addToHead(node);
            cache[key] = node;
            if(cache.size() > capacity){
                node = tail->prev;
                deleteNode(node);
                cache.erase(node->key);
            }
        }
    }


    // remove the node from the DlinekedList
    void deleteNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // add the node to the head of the DlinekedList
    void addToHead(DLinkedNode* node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

