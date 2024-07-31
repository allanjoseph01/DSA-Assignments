//Design Browser History
//
//leetcode submission id : https://leetcode.com/submissions/detail/1329530092/

class BrowserHistory {
public:
    stack<string>main;
    stack<string>support;
    BrowserHistory(string homepage) {
        while(!main.empty()){
            main.pop();
        }
        main.push(homepage);
    }
    
    void visit(string url) {
        main.push(url);
        while(!support.empty()){
            support.pop();
        }
    }
    
    string back(int steps) {
        while(steps && !main.empty()){
            support.push(main.top());
            main.pop();
            steps--;
        }
        if(main.empty()){
            main.push(support.top());
            support.pop();
        }
        return main.top();
    }
    
    string forward(int steps) {
        while(steps && !support.empty()){
            main.push(support.top());
            support.pop();
            steps--;
        }
        return main.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */