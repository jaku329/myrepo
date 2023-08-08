#include <iostream>
using namespace std;


class ListNode {
public:
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int v) : val(v), next(nullptr) {}
  ListNode(int v, ListNode* n) : val(v), next(n) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* f = head;
    ListNode dummy;
    dummy.next = head;
    ListNode* s = &dummy;
    while (n-- > 0) f = f->next;
    while (f != NULL) {
      f = f->next;
      s = s->next;
    }

    //ListNode* tmp = s->next;
    s->next = s->next->next;
  
    return dummy.next;
  }
};

int main() {
  ListNode a(5);
  ListNode b(4, &a);
  ListNode c(3, &b);
  ListNode d(2, &c);
  ListNode e(1, &d);

  Solution s;
  ListNode* h = s.removeNthFromEnd(&e, 2);

  while(h) {
    cout << h->val << " ";
    h = h->next;
  }
  cout << endl;
  return 0;
}
