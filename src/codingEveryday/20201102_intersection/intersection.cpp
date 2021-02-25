/********************************************
* intersection.cpp                              *
* Created by lugf027 on 2020/11/2.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 349. 两个数组的交集
/// 给定两个数组，编写一个函数来计算它们的交集。

#include <vector>
#include <unordered_set>

using namespace std;

/**
 * 哈希 O(1) 查找
 */
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        if (nums1.empty() || nums2.empty()) return res;

        unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        for (int i:nums2) {
            if (nums1Set.find(i) != nums1Set.end()) {
                res.push_back(i);
                nums1Set.erase(i);
            }
        }
        return res;
    }
};

/**
 * 哈希O(1)查找的小小优化
 */
class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 优化重复
        unordered_set<int> set1, set2;
        for (auto& num : nums1) {
            set1.insert(num);
        }
        for (auto& num : nums2) {
            set2.insert(num);
        }
        return getIntersection(set1, set2);
    }

    vector<int> getIntersection(unordered_set<int>& set1, unordered_set<int>& set2) {
        // 优化循环
        if (set1.size() > set2.size()) {
            return getIntersection(set2, set1);
        }
        vector<int> intersection;
        for (auto& num : set1) {
            if (set2.count(num)) {
                intersection.push_back(num);
            }
        }
        return intersection;
    }
};

#include <algorithm>

/**
 * 排序+双指针
 * 时间复杂度：O(mlogm+nlogn)，其中 m 和 n 分别是两个数组的长度。对两个数组排序的时间复杂度分别是 O(mlogm) 和 O(nlogn)，
 *          双指针寻找交集元素的时间复杂度是 O(m+n)，因此总时间复杂度是 O(mlogm+nlogn)。
 * 空间复杂度：O(logm+logn)，其中 m 和 nn分别是两个数组的长度。空间复杂度主要取决于排序使用的额外空间。
 */
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 = 0, index2 = 0;
        vector<int> res;
        while (index1 < length1 && index2 < length2) {
            int num1 = nums1[index1], num2 = nums2[index2];
            if (num1 == num2) {
                // 保证加入元素的唯一性
                if (res.empty() || num1 != res.back()) {
                    res.push_back(num1);
                }
                index1++;
                index2++;
            } else if (num1 < num2) {
                index1++;
            } else {
                index2++;
            }
        }
        return res;
    }
};
