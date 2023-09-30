//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    public:
    void booleanMatrix(vector<vector<int> > &m)
    {
        set<int>r;
        set<int>c;
        
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==1){
                   r.insert(i);
                   c.insert(j);
                }
            }
        }
        
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(r.count(i) || c.count(j))
                {
                    m[i][j]=1;
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends