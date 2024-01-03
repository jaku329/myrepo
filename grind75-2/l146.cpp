// 146. LRU Cache

#include <iostream>
#include <unordered_map>
using namespace std;

// TLE ?
class LRUCache {
private:
  struct ListNode {
    int key = -1;
    int val = -1;
    ListNode* prev = NULL;
    ListNode* next = NULL;
  };

  int _capacity;
  ListNode* _head = NULL;
  ListNode* _tail = NULL;
  unordered_map<int, ListNode*> _umap;

  void deleteTail() {
    _umap.erase(_tail->key);
    if (_head == _tail) {
      _head = NULL;
      _tail = NULL;
    }
    else {
      _tail = _tail->prev;
      _tail->next = NULL;
    }
  }

  void moveNode(int key) {
    ListNode* node = _umap[key];
    if (node == _head)
      return;
    if (node == _tail) {
      _tail = node->prev;
      _tail->next = NULL;
    }
    else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      node->next = NULL;
      node->prev = NULL;
    }
    insertNode(key);
  }

  void insertNode(int key) {
    ListNode* node = _umap[key];
    node->next = _head;
    if (_head == NULL)
      _tail = node;
    else
      _head->prev = node;
    _head = node;
  }
  
public:
  LRUCache(int capacity) {
    _capacity = capacity;
  }
  
  void put(int key, int value) {
    if (_umap.find(key) != _umap.end()) {
      ListNode* node = _umap[key];
      node->val = value;
      moveNode(key);
    }
    else { 
      ListNode* node = new ListNode();
      node->key = key;
      node->val = value;
      _umap[key] = node;
      if (_umap.size() <= _capacity) {
        insertNode(key);
      }
      else {
        deleteTail();
        insertNode(key);
      }
    }
  }

  int get(int key) {
    if (_umap.count(key) == 0) {
      return -1;
    }
    ListNode* node = _umap[key];
    if (node != _head) {
      moveNode(key);
    }
    return node->val;
  }

  void debug() {
cout << "DEBUG: ";
   cout << _head->key << ", ";
cout << _tail->key << endl << endl; 
  }
};

int main() {
/*
["LRUCache","get","get","put","get","put","put","put","put","get","put"]
[[1],[6],[8],[12,1],[2],[15,11],[5,2],[1,15],[4,2],[5],[15,15]]
*/
  LRUCache lru(1);
  cout << lru.get(6);
  cout << lru.get(8);
  lru.put(12,1);
  cout << lru.get(2);
  lru.put(15,11);
  lru.put(5,2);
  lru.put(1,15);
  lru.put(4,2);
  cout << lru.get(5);
  lru.put(15,15);

  return 0;
}
