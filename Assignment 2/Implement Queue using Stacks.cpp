
// Implement Queue using Stacks

//leetcode submission id: https://leetcode.com/submissions/detail/1275481540/



class MyQueue {
public:
    int size;
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        size=0;
        // stack<int>s1;
        // stack<int>s2;
    }
    
    void push(int x) {
        s1.push(x);
        size++;
    }
    
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int a= s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        size--;
        return a;
    }
    
    int peek() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int b= s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return b;
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */