//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

//方法一 先追加 在排序 时间复杂度O(nlogn) 空间复杂度 O(m+n) //具体看使用什么排序方法 
//方法二 从后往前比较追加 时间复杂度 O(m+n) 空间复杂度 O(m+n)
//法二
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n - 1;

    while ((p1 >= 0) && (p2 >= 0)) {
      nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
    }

    while (p1 >= 0) {
        nums1[p--] = nums1[p1--];
    }
    
    while (p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }

    }

};
