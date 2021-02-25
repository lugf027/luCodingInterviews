/*************************************************************
 * Name     : 349_intersection
 * Title    : 349. 两个数组的交集
 * Author   : lugf027 14:23 2021/2/25.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace intersection {
    class Solution {
    public:
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
            vector<int> res;
            unordered_set<int> nums1_set(nums1.begin(), nums1.end());
            for (auto num:nums2) {
                if (nums1_set.find(num) != nums1_set.end()) {
                    res.push_back(num);
                    nums1_set.erase(num);
                }
            }
            return res;
        }
    };

    /**
     * 双指针
     */
    class Solution1 {
    public:
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
            vector<int> res;
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());

            int index1 = 0, index2 = 0;
            int length1 = nums1.size(), length2 = nums2.size();

            while (index1 < length1 && index2 < length2) {
                if (nums1[index1] == nums2[index2]) {
                    if (res.empty() || nums1[index1] != res.back()) {
                        res.push_back(nums1[index1]);
                    }
                    ++index1;
                    ++index2;
                } else if (nums1[index1] < nums2[index2]) {
                    ++index1;
                } else {
                    ++index2;
                }
            }

            return res;
        }
    };
}
