// 133. Clone Graph

#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
  int val;
  vector<Node*> neighbors;
public:
  Node () {}
  Node (int _val) {
    val = _val;
  }
};

Node* cloneGraph(Node* node) {
  if (node == NULL) return node;
  unordered_map<int, Node*> umap;
  unordered_set<int> visited;
  queue<Node*> q;
  q.push(node);
  visited.insert(node->val);
  while (!q.empty()) {
    Node* n = q.front();
    q.pop();
    if (umap.count(n->val) == 0)
      umap[n->val] = new Node(n->val);
    Node* newRoot = umap[n->val];
    for (auto nbr : n->neighbors) {
      if (umap.count(nbr->val) == 0)
        umap[nbr->val] = new Node(nbr->val);
      newRoot->neighbors.push_back(umap[nbr->val]);
      if (visited.count(nbr->val) == 0) {
        q.push(nbr);
        visited.insert(nbr->val);
      }
    }
  }
  return umap[node->val];
}

int main() {
//  [[2,4],[1,3],[2,4],[1,3]]
  Node n1(1);
  Node n2(2);
  Node n3(3);
  Node n4(4);
  n1.neighbors.push_back(n2);
  n1.neighbors.push_back(n4);
  n2.neighbors.push_back(n1);
  n2.neighbors.push_back(n1);

  return 0;
}
