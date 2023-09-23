#User function Template for python3


class Solution:
    def getIndex(self,arr,n,x):
        for i in range(0,n):
            if arr[i] == x:
                return i;
        return -1
            
    def find(self, arr, n, x):
        
        # code here
        ans=[]
        first = self.getIndex(arr,n,x)
        if first == -1:
            ans.append(-1)
            ans.append(-1)
            return ans
        ans.append(first)
        last = first
        while (last + 1 < n) and (arr[last + 1] == x):
            last = last + 1
        ans.append(last)
        return ans

#{ 
 # Driver Code Starts
t=int(input())
for _ in range(0,t):
    l=list(map(int,input().split()))
    n=l[0]
    x=l[1]
    arr=list(map(int,input().split()))
    ob = Solution()
    ans=ob.find(arr,n,x)
    print(*ans)
# } Driver Code Ends