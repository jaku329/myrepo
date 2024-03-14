#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

typedef void (*Callback) (void);

void setTimer(long durationMillis, Callback cb) {
}
long getCurrentTimeMillis() {
}

// priority queue
priority_queue<long> pq;
unordered_map<long, Callback> umap;
void myCallback() {
  Callback cb = umap[pq.top()];
  umap.erase(pq.top());
  pq.pop();
  if (!pq.empty()) 
    setTimer(pq.top() - getCurrentTimeMillis(), myCallback);
  cb();
}
void addTimer(long durationMillis, Callback cb) {
  long curTime = getCurrentTimeMillis();
  long timeout = curTime + durationMillis;
  if (pq.empty() || timeout < pq.top()) 
    setTimer(durationMillis, myCallback);
  umap[timeout] = cb;
  pq.push(timeout);
}

int main() {
  return 0;
}
