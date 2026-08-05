class MinStack {
    //memorize this soln please
public:
    stack<int> st;
    int minelement=-1;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minelement=val;
        }
        else if(val<minelement){
            st.push(2LL*val-minelement);
            minelement=val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top()>=minelement){
            st.pop();
        }
        else{
            int prevmin=2LL*minelement-st.top();
            minelement=prevmin;
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<minelement){
            return minelement;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        return minelement;
    }
};
