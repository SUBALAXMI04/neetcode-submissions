class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    MedianFinder(){ }
    
    void balance(){
        if(small.size() < large.size()){
            small.push(large.top());
            large.pop();
        }
        if(small.size() > large.size() + 1){
            large.push(small.top());
            small.pop();
        }
    }

    void addNum(int num){
        if(small.empty() || small.top() > num) small.push(num);
        else large.push(num);
        balance();
    }
    
    double findMedian(){
        if(small.size() > large.size()) return small.top();
        return ((double)small.top() + large.top())/2.0;
    }
};
