class MedianFinder {
private:
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxPQ.empty() || num <= maxPQ.top()) maxPQ.push(num);
        else minPQ.push(num);

        if(maxPQ.size() > minPQ.size() + 1) {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
        } else if(minPQ.size() > maxPQ.size() + 1) {
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }
    }
    
    double findMedian() {
        // even
        if(minPQ.size() == maxPQ.size()) return ((minPQ.top() + maxPQ.top()) / 2.0);

        // odd
        if(maxPQ.size() > minPQ.size()) return maxPQ.top();
        else return minPQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */