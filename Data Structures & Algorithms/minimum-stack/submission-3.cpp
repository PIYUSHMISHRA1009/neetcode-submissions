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
            st.push(2*val-minelement);
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
            int prevmin=2*minelement-st.top();
            minelement=prevmin;
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minelement;
    }
};
