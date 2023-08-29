// https://leetcode.com/problems/reorder-list

class Solution {
public:
  void reorderList(ListNode* head) {
    ListNode* cur = head;
    ListNode* tmp;
    ListNode* tmp2;
    while (cur->next != NULL) {
      tmp2 = cur->next;
      tmp = cur->next;
      while (tmp->next != NULL && tmp->next->next != NULL) tmp = tmp->next;
      if (tmp->next) {
        cur->next = tmp->next;
        tmp->next->next = tmp2;
        tmp->next = NULL;
      }
      cur = tmp2;
    }
  }
};

// Recursive?
class Solution2 {
public:
  ListNode* findNext(ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return NULL;
    if (head->next->next == NULL) {
      head->next = NULL;
      return head;
    }
    
    ListNode* tail = findNext(head->next);
    next = head->next;
    head->next = next;
  }

  void reorderList(ListNode* head) {
  }
};

// 1. separate into two lists. 1->2->3, 4->5->6
// 2. reverse the 2nd list, 1->2->3, 6->5->4
// 3. merge two lists nodes one by one. 1->6->2->5->3->4
class Solution3 {
public:
  ListNode* reverse(ListNode* head) {
    if (head->next == NULL) return head;

    ListNode* tmp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return tmp;
  }

  void reorderList(ListNode* head) {
    ListNode* l1 = head;
    ListNode* l2 = head;
    ListNode* tmp;
    while (l1 != NULL && l1->next != NULL) {
      l1 = l1->next->next;
      l2 = l2->next;
    }
    if (l1 == head) return;

    l1 = l2;
    l2 = l2->next;
    if (l2 == NULL) return;
    l1->next = NULL;

    l2 = reverse(l2);

    l1 = head;
    while (l1 != NULL && l2 != NULL) {
      tmp = l1->next;
      l1->next = l2;
      l1 = tmp;
      tmp = l2->next;
      l2->next = l1;
      l2 = tmp;
    }
    
  }
};
