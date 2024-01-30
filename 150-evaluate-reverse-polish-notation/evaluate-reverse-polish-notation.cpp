class Solution {
public:
    int evalexp(string operand,stack<int>&st){
        int op2 = st.top();
        st.pop();
        int op1 = st.top();
        st.pop();
        if(operand == "+")return op1 + op2;
        else if(operand == "-")return op1 - op2;
        else if(operand == "*")return op1 * op2;
        else return op1 / op2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        cout<<tokens.size()<<endl;
         std::vector<std::string>::iterator it;
        for (it=tokens.begin(); it<tokens.end(); it++){
            string inp = *it;
            
            if(inp != "+" && inp != "-" && inp != "*" && inp != "/"){
                st.push(stoi(inp));
            }
            else st.push(evalexp(inp,st));
        }
        return st.top();
    }
};