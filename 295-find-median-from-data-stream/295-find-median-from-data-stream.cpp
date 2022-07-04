class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if(maxHeap.size() && minHeap.size() && (maxHeap.top() > minHeap.top())){
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }
        
        if(size(maxHeap) > (size(minHeap) + 1)){
            int val = maxHeap.top();
            maxHeap.pop();
            minHeap.push(val);
        }
        
        if(size(minHeap) > (size(maxHeap) + 1)){
            int val = minHeap.top();
            minHeap.pop();
            maxHeap.push(val);
        }
    }
    
    double findMedian() {
        if(size(maxHeap) == size(minHeap)){
            return (1.0 * maxHeap.top() + minHeap.top()) / 2;
        }
        else if(size(maxHeap) > size(minHeap)) {
            return maxHeap.top();
        }
        else    return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */