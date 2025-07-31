#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;

        if (total % 2 == 1) {
            // 奇数情况：找第 (total+1)/2 小的数
            return findKth(nums1, nums2, (total + 1) / 2);
        } else {
            // 偶数情况：找第 total/2 和第 total/2+1 小的数的平均值
            return (findKth(nums1, nums2, total / 2) +
                    findKth(nums1, nums2, total / 2 + 1)) / 2.0;
        }
    }

private:
    double findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            // 边界情况
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1], pivot2 = nums2[newIndex2];

            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
};

int main() {
    Solution solution;
    
    // 测试用例1: nums1 = {1, 3}, nums2 = {2}
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Test 1: nums1 = {1, 3}, nums2 = {2}, result: " << result << endl;
    
    // 测试用例2: nums1 = {1, 2}, nums2 = {3, 4}
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    double result2 = solution.findMedianSortedArrays(nums3, nums4);
    cout << "Test 2: nums1 = {1, 2}, nums2 = {3, 4}, result: " << result2 << endl;
    
    // 测试用例3: nums1 = {1}, nums2 = {2, 3, 4, 5, 6}
    vector<int> nums5 = {1};
    vector<int> nums6 = {2, 3, 4, 5, 6};
    double result3 = solution.findMedianSortedArrays(nums5, nums6);
    cout << "Test 3: nums1 = {1}, nums2 = {2, 3, 4, 5, 6}, result: " << result3 << endl;
    
    // 测试用例4: nums1 = {}, nums2 = {1, 2, 3, 4, 5}
    vector<int> nums7 = {};
    vector<int> nums8 = {1, 2, 3, 4, 5};
    double result4 = solution.findMedianSortedArrays(nums7, nums8);
    cout << "Test 4: nums1 = {}, nums2 = {1, 2, 3, 4, 5}, result: " << result4 << endl;
    
    return 0;
}
