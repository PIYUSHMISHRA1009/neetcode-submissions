class Solution {
public:
    int performcalculations(string opr,int val1,int val2){
        if(opr=="+"){
            return val1+val2;
        }
        else if(opr=="-"){
            return val1-val2;
        }
        else if(opr=="*"){
            return val1*val2;
        }
        else{
            return val1/val2;
        }
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==0){
            return 0;
        }
        stack<string> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"|| tokens[i]=="-"||
            tokens[i]=="/"|| tokens[i]=="*"){
                int val2=stoi(st.top());
                st.pop();
                int val1=stoi(st.top());
                st.pop();
                int res=performcalculations(tokens[i],val1,val2);
                st.push(to_string(res));
            }
            else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};
