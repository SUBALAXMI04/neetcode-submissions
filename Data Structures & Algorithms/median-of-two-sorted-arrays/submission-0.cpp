class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
        if(nums1.size() > nums2.size()) swap(nums1,nums2);
        int n1 = nums1.size(),n2 = nums2.size();
        int st = 0,end = n1,left = (n1 + n2 + 1)/2;
        while(st <= end){
            int mid1 = st + (end - st)/2;
            int mid2 = left - mid1;
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            if(l1 <= r2 && l2 <= r1){
                if((n1 + n2) % 2) return max(l1,l2);
                return (double)(max(l1,l2) + min(r1,r2))/2.0;
            }
            else if(l1 <= r2) st = mid1 + 1;
            else end = mid1 - 1;
        }
        return 0.0;
    }
};
