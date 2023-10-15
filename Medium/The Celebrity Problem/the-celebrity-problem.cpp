//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a,int b){
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //Initializing the Stack
        stack<int> s;
        for(int i =0;i<n;i++){
            s.push(i);
        }
        //Checking Knowns of 2 element
        while(s.size()>1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        //While exiting this loop , we have single element left in stack 
        //That is our potential celebrity.
        
        int ans = s.top();
        //Verfying 
        for(int i = 0;i<n;i++){
            if(M[ans][i]==1){
                return -1;
            }
        }
        for(int i =0;i<n;i++){
            if(ans==i){
                continue;
            }
            else{
                if(M[i][ans] == 0){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends