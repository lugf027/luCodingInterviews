/********************************************
* findRepeatNumber.cpp                              *
* Created by lugf027 on 2020/10/12.            *
* Github: https://github.com/lugf027        *
*********************************************/

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*03 找出数组中重复的数字。
 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
 请找出数组中任意一个重复的数字。
示例 1：
    输入：
    [2, 3, 1, 0, 2, 5, 3]
    输出：2 或 3
限制：
2 <= n <= 100000*/

namespace findRepeatNumber {

    class Solution {
    public:
        /**
         * 原地哈希法
         * 时间O(n),空间O(1)，修改原数据
         * @param nums
         * @return
         */
        int findRepeatNumber0(vector<int> &nums) {
            for (int i = 0; i < nums.size(); ++i) {
                while (nums.at(i) != i) {
                    int m = nums.at(i);
                    if (nums.at(i) == nums.at(m)) {
                        return m;
                    }
                    else {
                        nums.at(i) = nums.at(m);
                        nums.at(m) = m;
                    }
                }
            }
            return -1;
        }

        /**
         * 集合法
         * 时间O(n),空间O(n),不修改原数据
         * @param nums
         * @return
         */

        int findRepeatNumber1(vector<int> &nums) {
            auto* had_numbers = new set<int>();
            for (int i = 0; i < nums.size(); ++i) {
                had_numbers->insert(nums.at(i));
                if (had_numbers->size() < i + 1) {
                    return nums.at(i);
                }
            }
            return -1;
        }

        /**
         * 排序比较法
         * 时间O(nlogn),空间O(1)，修改原数据
         * @param nums
         * @return
         */
        int findRepeatNumber2(vector<int> &nums) {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 1;) {
                if (nums.at(i) == nums.at(++i)) {
                    return nums.at(i);
                }
            }
            return -1;
        }

        /**
         * 二分查找
         * 时间O(nlongn),空间O(1),不修改原数据
         * 弊端，无法解决比如：[0,1,0]
         * @param nums
         * @return
         */
        int findRepeatNumber(vector<int> &nums) {
            if (nums.size() == 0)
                return -1;

            int min_value = 1;
            int max_value = nums.size() - 1;
            int count = 0;
            while (max_value >= min_value) {
                int mid_value = (max_value + min_value) >> 1;
                count = countNum(&nums, min_value, mid_value);
                if (max_value == min_value) {
                    if (count > 1)
                        return min_value;
                    else
                        break;
                }

                if (count > mid_value - min_value + 1) {
                    max_value = mid_value;
                }
                else {
                    // 注意这个地方需要加1，不然最后会陷入死循环
                    // 比如最后max_value为2,min_value为1，则会一直循环
                    // 对应的上面也可以给max_value复制的地方减1
                    min_value = mid_value + 1;
                }
            }
            return -1;
        }

        int countNum(const vector<int>* num, int min_value, int max_value) {
            int countRet = 0;
            for (int i: *num) {
                if (min_value <= i && i <= max_value) {
                    ++countRet;
                }
            }
            return countRet;
        }
    };

}


