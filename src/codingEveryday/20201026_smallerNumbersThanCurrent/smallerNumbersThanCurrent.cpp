/********************************************
* smallerNumbersThanCurrent.cpp                              *
* Created by lugf027 on 2020/10/26.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 1365. 有多少小于当前数字的数字
/// 给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
/// 换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
/// 以数组形式返回答案。

/// 2 <= nums.length <= 500
/// 0 <= nums[i] <= 100

#include <vector>

using namespace std;

/**
 * 让每个数字跟他后面的数字比较
 */
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> *res = new vector<int>(nums.size(), 0);
        for(int i=0; i<nums.size(); ++i){
            for(int j=i+1; j < nums.size(); ++j){
                if(nums[i] > nums[j]){
                    res->at(i) = res->at(i) + 1;
                }else if(nums[i] < nums[j]){
                    res->at(j) = res->at(j) + 1;
                }
            }
        }
        return *res;
    }
};

#include <algorithm>

/**
 * 时间复杂度：O(N\log N)O(NlogN)，其中 NN 为数组的长度。排序需要 O(N\log N)O(NlogN) 的时间，随后需要 O(N)O(N) 时间来遍历。
 * 空间复杂度：O(N)O(N)。因为要额外开辟一个数组。
 */
class Solution1 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> data;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            data.emplace_back(nums[i], i);
        }
        sort(data.begin(), data.end());

        vector<int> ret(n, 0);
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (prev == -1 || data[i].first != data[i - 1].first) {
                prev = i;
            }
            ret[data[i].second] = prev;
        }
        return ret;
    }
};

/**
 * 计数排序
 * 时间复杂度：O(N+K)，其中 K 为值域大小。需要遍历两次原数组，同时遍历一次频次数组 cnt 找出前缀和。
 * 空间复杂度：O(K)。因为要额外开辟一个值域大小的数组。
 */
class Solution2 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }
        for (int i = 1; i <= 100; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            ret.push_back(nums[i] == 0 ? 0: cnt[nums[i]-1]);
        }
        return ret;
    }
};

