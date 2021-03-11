/*************************************************************
 * Name     : 27_removeElement
 * Title    : 
 * Author   : lugf027 11:53 2021/3/7.
 * Describe : 
 *************************************************************/
#include "util.h"

namespace removeElement {

/**
 * 快慢指针
 */
    class Solution1 {
    public:
        int removeElements(vector<int> &nums, int val) {
            int i = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] != val) {
                    nums[i] = nums[j];
                    i++;
                }
            }
            return i;
        }
    };

/**
 * 正方向、反方向
 */
    class Solution {
    public:
        int removeElement(vector<int> &nums, int val) {
            int start = 0;
            int end = nums.size() - 1;
            for (; start <= end; ++start) {
                if (nums[start] == val) {
                    while (end >= 0 && nums[end] == val) {
                        nums.erase(nums.begin() + end);
                        --end;
                    }
                    if (start < end) {
                        nums[start] = nums[end];
                        nums.erase(nums.begin() + end);
                        --end;
                    }
                }
            }
            return nums.size();
        }

        int removeElement1(vector<int> &nums, int val) {
            int start = 0;
            int end = nums.size() - 1;
            while (start < end) {
                if (nums[start] == val) {
                    nums[start] = nums[end];
                    nums.erase(nums.begin()+end);
                    --end;
                } else {
                    ++start;
                }
            }
            return nums.size();
        }
    };

}
