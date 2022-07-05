class MedianFinder {
private:
    //small or maxheap
    priority_queue<int> small;
    //large or minheap
    priority_queue<int, vector<int>, greater<int>> large;
    
public:
    MedianFinder() {    
    }
    
    void addNum(int num) {
        if(small.empty() || small.top()>num)   small.push(num);
        else large.push(num);
        
        if(size(small) > (size(large) + 1)){
            large.push(small.top());
            small.pop();
        }
        else if((size(small) + 1) < size(large)){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(size(small)==size(large))    return (small.top() + large.top()) / 2.0;
        else if(size(small) > size(large))  return small.top();
        else return large.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */