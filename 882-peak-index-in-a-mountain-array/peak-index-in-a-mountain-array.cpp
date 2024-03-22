class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            
            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
        // At this point, start == end, which represents the peak index
        return start; // or end, they are the same
    }
};