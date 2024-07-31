//Online Stock Span
//
//leetcode submission id : https://leetcode.com/submissions/detail/1329582153/

class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int k=1;
        while(!st.empty() && st.top().first<=price){
            k+=st.top().second;
            st.pop();
        }
        st.push(make_pair(price,k));
        return k;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */