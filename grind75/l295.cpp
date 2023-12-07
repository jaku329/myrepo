// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
  priority_queue<int> pq1;
  priority_queue<int, vector<int>, greater<int>> pq2; // smallest on the top

  MedianFinder() {
  }

  void addNum(int num) {
    if (pq1.empty()) {
      pq1.push(num);
    }
    else {
      if (num < pq1.top()) {
        if (pq1.size() <= pq2.size())
          pq1.push(num);
        else {
          pq2.push(pq1.top()); 
          pq1.pop();
          pq1.push(num);
        }
      }
      else if (pq2.empty()) {
        pq2.push(num);
      }
      else if (num > pq2.top()) {
        if (pq2.size() <= pq1.size())
          pq2.push(num);
        else {
          pq1.push(pq2.top());
          pq2.pop();
          pq2.push(num);
        }
      }
      else {
        if (pq1.size() <= pq2.size())
          pq1.push(num);
        else
          pq2.push(num);
      }
    }
  }

  double findMidian() {
    if (pq1.size() == pq2.size()) {
      return ((double)(pq1.top() + pq2.top())) / 2;
    }
    else if (pq1.size() > pq2.size())
      return (double)pq1.top();
    return (double)pq2.top();
  }
};
