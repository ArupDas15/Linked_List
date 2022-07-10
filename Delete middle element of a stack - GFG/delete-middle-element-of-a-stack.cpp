// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    void solve(stack<int>&s, int k){
        // Base Condition
        if(k==1){
            s.pop();
            return;
        }
        else{
            int temp = s.top();
            s.pop();
            // Hypothesis
            solve(s,k-1);
            // Induction
            s.push(temp);
        }
    }
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        if(sizeOfStack==0)
            return;
        else{
            /* We are dividing by 2.0 and not 2 although 2 is specified in the question because 
            when we divide by 2 ceil will have no effect as the number is already reduced to floor.
            For e.g., say, sizeOfStack=12, then k=6 if we divide by 2 but if we divide by 2.0 then 
            k=7 because of type promotion.
            */
            int k = ceil((sizeOfStack+1)/2.0); 
            solve(s,k);
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends
