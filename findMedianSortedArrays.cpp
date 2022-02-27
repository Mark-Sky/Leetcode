//
// Created by 11056 on 2021/5/6.
//
#include <iostream>
#include <vector>
using namespace std;
//第一次想到的版本是用排序算法的merge，但是这种方法是O(n+m)的时间复杂度，会RunTimeError
class Solution {
public:

#define Solution1
#ifdef Solution1
#define MedianOfArray(nums) (double)(nums.size() & 1) ? nums[nums.size()/2] : (double)(nums[nums.size()/2] + nums[nums.size()/2 - 1])/2;

    vector<int> Merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> MergeNums(nums1.size()+nums2.size());
        int pointer1 = 0, pointer2 = 0;
        if(nums1.size()==0)
            return nums2;
        if(nums2.size()==0)
            return nums1;
        for(int i = 0; pointer1 != nums1.size() || pointer2 != nums2.size(); i++){
            if((nums1[pointer1] <= nums2[pointer2] || pointer2 == nums2.size())&&pointer1!=nums1.size()){
                MergeNums[i] = nums1[pointer1];
                pointer1 ++;
            } else{
                MergeNums[i] = nums2[pointer2];
                pointer2 ++;
            }
        }
        return MergeNums;
    }

    double findMedian(vector<int>& MergeNums){
        return MedianOfArray(MergeNums)
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> MergeNums = Merge(nums1,nums2);
        return findMedian(MergeNums);
    }

#endif
};
//虽然知道是用二分搜索来做，但是就是nmd想不到怎么二分搜索做，感觉要分的情况有点多，有点复杂
//分情况先吧
class Solution2{
public:
#ifndef Solution2
#define Solution2
#define MedianOfArray(nums) (double)(nums.size() & 1) ? nums[nums.size()/2] : (double)(nums[nums.size()/2] + nums[nums.size()/2 - 1])/2;
#define Condition1(numsA,numsB) (double)(numsA.size() > numsB.size())? (double)numsA[]
    int Median;
    int nums1Start, nums1End, nums1Median;
    int nums2Start, nums2End, nums2Median;
    int MedianIndex(vector<int>& nums1, vector<int>& nums2){
        if(nums1[nums1Median] + nums2[] )
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        Median = (nums1.size() + nums2.size())/2;
        nums1Start = 0;
        nums2Start = 0;
        nums1End = nums1.size() - 1;
        nums2End = nums2.size() - 1;
        nums1Median = (nums1Start + nums1End) / 2;
        nums2Median = (nums2Start + nums2End) / 2;
        if(nums1.size() == 0)
            return MedianOfArray(nums2);
        if(nums2.size() == 0)
            return MedianOfArray(nums1);
        if(nums1[0] >= nums2[nums2End])
            return (nums2.size() > nums1.size())? (double)nums2[nums2End - (Median - nums1.size())]
        MedianIndex(nums1,nums2);

    }

#endif
};
int main(){
    Solution A;
    vector<int> a = {1,3};
    vector<int> b = {0,0};
    cout<<A.findMedianSortedArrays(a,b);
}