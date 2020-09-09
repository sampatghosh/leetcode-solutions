class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {}
    void addNum(int num) {
        if(left.size()==0)
            left.push(num);
        else if((left.size()+right.size())%2) {
            if (num < left.top()) {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else if (num == left.top())
                right.push(num);
            else
                right.push(num);
        } else {
            if(num <= left.top()) {
                left.push(num);
            } else if (num < right.top())
                left.push(num);
            else {
                left.push( right.top());
                right.pop();
                right.push(num);
            }
        }
    }
    double findMedian() {
        if((left.size()+right.size())%2)
            return left.top();
        else
            return (left.top()+right.top()) / 2.0;
    }
};