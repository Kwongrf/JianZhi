class Solution {
public:
    void push(int value) {
        stk.push(value);
        if(minStk.empty())
            minStk.push(value);
        else
            if(minStk.top() > value)
                minStk.push(value); 
    }
    void pop() {
        if(stk.top() == minStk.top())
            minStk.pop();
        stk.pop();
    }
    int top() {
        return stk.top();
    }
    int min() {
        return minStk.top();
    }
private:
    stack<int> stk;
    stack<int> minStk;
};
