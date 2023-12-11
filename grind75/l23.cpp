//

ListNode* findMinNode(vector<ListNode*>& lists) {
  int minIdx = -1;
  
  for (int i = 0; i < lists.size(); ++i) {
    if (lists[i]) {
	  if (minIdx < 0) min = i;
	  else {
	    if (list[i]->val < list[minIdx]->val)
		  minIdx = i;
	  }
	}
  }

  if (minIdx < 0) return NULL;
  ListNode* minNode = lists[minIdx];
  lists[minIdx] = lists[minIdx]->next;
  return minNode;
}

// straght forward 
ListNode* mergeKLists(vector<ListNode*>& lists) {
  ListNode* tmp = findMinNode(lists);
  ListNode* head = tmp;
  
  for (int i = 0; i < lists.size(); ++i)
    minQ.push({lists[i]->val, i});
  while (tmp) {
    tmp->next = findMinNode(lists);
	  tmp = tmp->next;
  }
  return head;
}

// optimzing by heap
ListNode* mergeKLists(vector<ListNode*>& lists) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minQ;
  ListNode* tmp = NULL;
  ListNode* head = NULL;
  
  for (int i = 0; i < lists.size(); ++i)
    if (lists[i])
      minQ.push({lists[i]->val, i});
  if (minQ.empty()) return NULL;
  int i = minQ.top().second;
  minQ.pop();
  head = lists[i];
  tmp = head;
  lists[i] = lists[i]->next;
  if (lists[i]) minQ.push({lists[i]->val, i});
  while (!minQ.empty()) {
    int i = minQ.top().second;
	minQ.pop();
    tmp->next = lists[i];
	lists[i] = lists[i]->next;
	if (lists[i]) minQ.push({lists[i]->val, i});
	
	tmp = tmp->next;
  }
  return head;
}
