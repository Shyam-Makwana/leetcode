class MedianFinder {
private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
    
public:
    MedianFinder() {    
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if(size(small) < size(large)){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return size(small)==size(large) ? ((small.top() + large.top()) / 2.0) : small.top(); 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */