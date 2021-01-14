/*************************************************************
 * Name     : 75_sortColors
 * Title    : 75. 颜色分类
 * Author   : lugf027 3:04 PM 1/11/2021.
 * Describe :
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
 * 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *
 * 进阶： 不使用排序函数； 常数空间一趟扫描
 * 一次遍历中等题，两次遍历简单题，调用sort入门题
 *************************************************************/

#include "util.h"

namespace sortColor {

    /**
     * 快速排序
     */
    class Solution {
    public:
        void sortColors(vector<int> &nums) {
            sort(nums.begin(), nums.end());
        }
    };

    /**
     * 一趟遍历
     */
    class Solution1 {
    public:
        void sortColors(vector<int> &nums) {
            int begin = 0;
            int mid = 0;
            int end = nums.size() - 1;

            while (mid <= end) {
                if(nums[mid] == 2){
                    swap(nums[mid], nums[end]);
                    --end;
                }else if(nums[mid] == 1){
                    ++mid;
                }else if(nums[mid] == 0){
                    swap(nums[mid], nums[begin]);
                    ++begin;
                    ++mid;
                }
            }
        }
    };

}
