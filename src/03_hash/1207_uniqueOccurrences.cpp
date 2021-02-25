/*************************************************************
 * Name     : 1207_uniqueOccurrences
 * Title    : 1207. 独一无二的出现次数
 * Author   : lugf027 14:37 2021/2/25.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace uniqueOccurrences{
    class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            // 优化写法
//            unordered_map<int, int> num_times_map;
//            for(int i: arr){
//                num_times_map[i]++;
//            }

            unordered_map<int, int> num_times_map;
            for(auto n:arr){
                if(num_times_map.find(n) != num_times_map.end()){
                    num_times_map[n]++;
                }else{
                    num_times_map[n] = 1;
                }
            }

            unordered_set<int> times;
            for(auto num_times:num_times_map){
                if(times.find(num_times.second) != times.end())
                    return false;
                times.insert(num_times.second);
            }
            return true;
        }
    };
}
