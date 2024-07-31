//Design a Stack With Increment Operation
//
//
//letcode submission id : https://leetcode.com/submissions/detail/1329545189/

class CustomStack {
public:
    stack<int>st;
    int msz;
    int sz=0;
    CustomStack(int maxSize) {
        msz=maxSize;
    }
    
    void push(int x) {
        if(sz<msz){
            st.push(x);
            sz++;
        }
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }
        int n=st.top();
        st.pop();
        sz--;
        return n;
    }
    
    void increment(int k, int val) {
        stack<int>st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        while(k && !st2.empty()){
            st.push(st2.top()+val);
            st2.pop();
            k--;
        }
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */