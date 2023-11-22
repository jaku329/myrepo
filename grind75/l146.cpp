// https://leetcode.com/problems/lru-cache/

#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
  int val;
  ListNode* prev = NULL;
  ListNode* next = NULL;
};

class LRUCache {
public:
  LRUCache(int capacity) {
    _capacity = capacity;
  }

  ~LRUCache() {
    for (auto it = umap.begin(); it != umap.end(); ++it)
      delete(it->second);
  }

  int get(int key) {
    if (umap.find(key) != umap.end()) {
      deleteNode(umap[key]);
      newNode(umap[key]);
      return umap[key]->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (umap.find(key) != umap.end()) {
      deleteNode(umap[key]);
      umap[key]->val = value;
      newNode(umap[key]);
    }
    else {
      ListNode* node = new ListNode();
      node->val = value;
      if (umap.size() == _capacity) {
        umap.erase(tail->val);
        ListNode* tmp = tail;
        deleteNode(tail);
        delete(tmp);
      }
      newNode(node);
      umap[key] = node;
    }
  }

  void newNode(ListNode* node) {
    if (tail == NULL)
      tail = node;

    if (head == NULL)
      head = node;
    else {
      node->next = head;
      head->prev = node;
      head = node;
    }
  }

  void deleteNode(ListNode* node) {
    if (node == tail) {
      tail = tail->prev;
      tail->next = NULL;
      node->prev = NULL;
    }
    else if (node == head) {
      head = head->next;
      head->prev = NULL;
      node->next = NULL;
    }
    else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
      node->next = NULL;
      node->prev = NULL;
    }
  }

private:
  int _capacity = 0;
  ListNode* head = NULL;
  ListNode* tail = NULL;
  unordered_map<int, ListNode*> umap;
};

int main() {
  LRUCache lru(2);

  lru.put(1,1);
  lru.put(2,2);
  cout << lru.get(1) << endl;
  lru.put(3,3);
  cout << lru.get(2) << endl;
  lru.put(4,4);
  cout << lru.get(1) << endl;
  cout << lru.get(3) << endl;
  cout << lru.get(4) << endl;
  return 0;
}
