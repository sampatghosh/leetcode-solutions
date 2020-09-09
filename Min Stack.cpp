class MinStack {
private:
    vector<pair<int,int>> stack;;
    int tos;
public:
    MinStack() {
        tos = -1;
    }
    void push(int x) {
        if(tos>-1) {
            pair<int,int> temp = stack.back();
            int min = temp.second>x?x:temp.second;
            stack.push_back(make_pair(x,min));
        }
        else
            stack.push_back(make_pair(x,x));
        ++tos;
    }
    void pop() {
        if(tos>-1) {
            stack.pop_back();
            --tos;
        }
    }
    int top() {
        return stack.back().first;
    }
    int getMin() {
        return stack.back().second;
    }
};