class Solution:
    def duplicates(self, arr, n): 
    	# code here
    	ans=[]
    	dict={}
    	for i in arr:
    	    if i in dict:
    	        dict[i] += 1
    	    else:
    	        dict[i] = 1
    	for key in dict:
    	    if dict[key] > 1:
    	        ans.append(key)
    	if len(ans) == 0:
    	    return [-1]
    	ans.sort()
    	return ans


#{ 
 # Driver Code Starts
if(__name__=='__main__'):
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        res = Solution().duplicates(arr, n)
        for i in res:
            print(i,end=" ")
        print()



# } Driver Code Ends