#include <iostream>

using namespace std;

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *h;
    ListNode *cur;
    if (list1 == NULL && list2 ==NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if (list1->val <= list2->val) {
      h = list1;
      list1 = list1->next;
    }
    else {
      h = list2;
      list2 = list2->next;
    }
    cur = h;
    while (list1 != NULL && list2 != NULL) {
      if (list1->val <= list2->val) {
        cur->next = list1;
        list1 = list1->next;
      }
      else {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }
    if (list1) cur->next = list1;
    if (list2) cur->next = list2;
    return h;
  }
};
