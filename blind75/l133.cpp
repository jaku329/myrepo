// https://leetcode.com/problems/clone-graph/

using namespace std;

class Solution {
  Node* cloneGraph(Node* node) {
    if (node == NULL) return NULL;

    unordered_set<int> visited;
    unordered_map<int, Node*> map;
    queue<Node*> q;
    q.push(node);
    visited.insert(node->val);

    Node* newNode = new Node();
    newNode->val = node->val;
    map[newNode->val] = newNode;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        Node* n = q.front();
        q.pop();
        Node* nn = map[n->val];
        for (int j = 0; j < n->neighbors.size(); ++j) {
          if (visited.count((n->neighbors[j])->val) == 0) {
            visited.insert((n->neighbors[j])->val);
            q.push(n->neighbors[j]);
          }

          if (map.count((n->neighbors[j])->val))
            nn->neighbors.push_back(map[(n->neighbors[j])->val]);
          else {
            Node* tmp = new Node();
            tmp->val = (n->neighbors[j])->val;
            nn->neighbors.push_back(tmp);
            map[tmp->val] = tmp;
          }
        }
      }
    }

    return newNode;
  }
};
