/********************************************
* minArray.cpp                              *
* Created by lugf027 on 2020/10/14.            *
* Github: https://github.com/lugf027        *
*********************************************/

/**
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
 */

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 遍历
     * @param numbers
     * @return
     */
    int minArray(vector<int> &numbers) {
        if (numbers.empty())
            return -1;

        if (numbers.size() == 1)
            return numbers.at(0);

        for (int i = 0; i < numbers.size();) {
            if (numbers.at(i) > numbers.at(++i))
                return numbers.at(i);
        }

        return -1;
    }

    /**
     * 二分查找
     * @param numbers
     * @return
     */
    int minArray1(vector<int> &numbers) {
        int left = 0;
        int right = numbers.size()-1;

        while (right - left > 1) {
            int mid = (right + left) / 2;
            if (numbers.at(right) > numbers.at(mid)) {
                right = mid;
            } else if (numbers.at(right) < numbers.at(mid)) {
                left = mid;
            } else {
                --right;
            }
        }

        return min(numbers.at(right), numbers.at(left));
    }

    /**
     * 二分查找 beauty
     * @param numbers
     * @return
     */
    int minArray2(vector<int> &numbers) {
        int left = 0;
        int right = numbers.size()-1;

        while (right > left) {
            int mid = (right + left) / 2;
            if (numbers.at(right) > numbers.at(mid)) {
                right = mid;
            } else if (numbers.at(right) < numbers.at(mid)) {
                left = mid + 1;
            } else {
                --right;
            }
        }

        return numbers.at(left);
    }

    /**
     * 二分查找 + 线性查找 (我觉得不好？)
     * @param numbers
     * @return
     */
    int minArray3(vector<int> &numbers) {
        int left = 0;
        int right = numbers.size()-1;

        while (right > left) {
            int mid = (right + left) / 2;
            if (numbers.at(right) > numbers.at(mid)) {
                right = mid;
            } else if (numbers.at(right) < numbers.at(mid)) {
                left = mid + 1;
            } else {
                --left;
                while(right > left){
                    if(numbers.at(++left) < numbers.at(right)){
                        return numbers.at(left);
                    }
                }
                return numbers.at(left);
            }
        }

        return numbers.at(left);
    }
};