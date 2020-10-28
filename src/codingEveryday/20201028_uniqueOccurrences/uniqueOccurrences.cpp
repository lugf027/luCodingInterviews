/********************************************
* uniqueOccurrences.cpp                              *
* Created by lugf027 on 2020/10/28.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 1207. 独一无二的出现次数
/// 给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
/// 如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        for(int i: arr){
            countMap[i]++;
        }

        unordered_set<int> times;
        for(auto i : countMap){
            if(times.find(i.second) != times.end())
                return false;
            times.insert(i.second);
        }
        return true;
    }
};
