// 23. Merge k Sorted Lists

class compare {
public:
  bool operator () (const ListNode* down, const ListNode* top) {
    if (top->val <= down->val) return true;
    return false;
  }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
  ListNode dummy;
  ListNode* tmp = &dummy;
  priority_queue<ListNode*, vector<ListNode*>, compare> pq;
  for (auto list : lists)
    if (list)
      pq.push(list);
  while (pq.size() > 1) {
    ListNode* next = pq.top();
    pq.pop();
    tmp->next = next;
    next = next->next;
    if (next)
      pq.push(next);
    tmp = tmp->next;
  }
  if (!pq.empty())
    tmp->next = pq.top();
  return dummy.next;
}
