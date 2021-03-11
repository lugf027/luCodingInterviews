/*************************************************************
 * Name     : 16_25_LRUCache
 * Title    : 
 * Author   : lugf027 14:20 2021/3/10.
 * Describe : 
 *************************************************************/

#include <unordered_map>

using namespace std;

struct DLinkNode {
    int key, value;
    DLinkNode *prev;
    DLinkNode *next;

    DLinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    DLinkNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, DLinkNode *> cache;
    DLinkNode *head;
    DLinkNode *tail;
    int size;
    int capacity;

    void removeNode(DLinkNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(DLinkNode *node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkNode *removeTail() {
        DLinkNode *node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        DLinkNode *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkNode *node = new DLinkNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                DLinkNode *removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        } else {
            DLinkNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
};
