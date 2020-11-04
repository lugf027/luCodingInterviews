/********************************************
* insert.cpp                              *
* Created by lugf027 on 2020/11/4.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 57.插入区间
/// 给出一个无重叠的 ，按照区间起始端点排序的区间列表。
/// 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;

        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }

        bool flag0 = true;
        bool flag1 = true;
        for (int i = 0; i < intervals.size(); ++i) {
            if (res.empty() || res.back().size() != 1) {
                if (flag0 && intervals[i][0] >= newInterval[0]) {
                    flag0 = false;

                    if (intervals[i][0] > newInterval[1]) {
                        res.push_back(newInterval);
                        res.push_back(intervals[i]);
                    } else {
                        vector<int> half;
                        half.push_back(newInterval[0]);
                        res.push_back(half);
                    }
                } else {
                    res.push_back(intervals[i]);
                }

            } else {  // 已经插入个一半的区间
                if (flag1 && intervals[i][0] > newInterval[1]) {
                    flag1 = false;
                    res.at(res.size() - 1).push_back(newInterval[1]);
                    res.push_back(intervals[i]);
                } else if (flag1 && intervals[i][1] >= newInterval[1]) {
                    flag1 = false;
                    res.at(res.size() - 1).push_back(intervals[i][1]);
                } else {
                    continue;
                }
            }
        }
        if (res.back().size() == 1) {
            res[res.size() - 1].push_back(newInterval[1]);
        }

        return res;
    }
};

class Solution1 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
