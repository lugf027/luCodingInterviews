/********************************************
* exchange.cpp                              *
* Created by lugf027 on 2020/11/24.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
/// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
/// 使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include <vector>

using namespace std;

namespace exchange {
    /**
     * 双指针
     */
    class Solution {
    public:
        vector<int> exchange(vector<int> &nums) {
            if(nums.size() < 2) return nums;

            int start = 0;
            int end = nums.size() - 1;

            while (start < end) {
                while (nums[start] & 1) {
                    if (start < end) {
                        ++start;
                    }
                    else {
                        break;
                    }
                }

                while (!(nums[end] & 1)) {
                    if (start < end)
                        --end;
                    else
                        break;
                }

                if (start < end) {
                    int tmp = nums[start];
                    nums[start] = nums[end];
                    nums[end] = tmp;
                }
            }
            return nums;

        }
    };

    /**
     * 双指针简洁些
     */
    class Solution0 {
    public:
        vector<int> exchange(vector<int>& nums) {
            int left = 0, right = nums.size() - 1;
            while (left < right) {
                if ((nums[left] & 1) != 0) {
                    left ++;
                    continue;
                }
                if ((nums[right] & 1) != 1) {
                    right --;
                    continue;
                }
                swap(nums[left++], nums[right--]);
            }
            return nums;
        }
    };

    /**
     * 快慢指针
     */
    class Solution1 {
    public:
        vector<int> exchange(vector<int>& nums) {
            int low = 0, fast = 0;
            while (fast < nums.size()) {
                if (nums[fast] & 1) {
                    swap(nums[low], nums[fast]);
                    low ++;
                }
                fast ++;
            }
            return nums;
        }
    };
}