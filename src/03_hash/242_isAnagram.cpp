/*************************************************************
 * Name     : 242_isAnagram
 * Title    : 242. 有效的字母异位词
 * Author   : lugf027 14:06 2021/2/25.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace isAnagram{

/**
 * 内部排序
 * 时间复杂度：O(nlogn)
 * 空间复杂度：O(logn)
 */
    class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length() != t.length())
                return false;
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
    };

/**
 * hash
 */
    class Solution1 {
    public:
        bool isAnagram(string s, string t) {
            unordered_multiset<char> s_multiset(s.begin(), s.end());
            unordered_multiset<char> t_multiset(t.begin(), t.end());
            return s_multiset == t_multiset;
        }
    };

/**
 * hash
 */
    class Solution2 {
    public:
        bool isAnagram(string s, string t) {
            int freq[26] {};
            for (char ch : s) ++freq[ch - 'a'];
            for (char ch : t) --freq[ch - 'a'];
            return all_of(begin(freq), end(freq), [](int x) { return x == 0; });
        }
    };

// all_of	区间[开始, 结束)中是否所有的元素都满足判断式p，所有的元素都满足条件返回true，否则返回false。
// any_of	区间[开始, 结束)中是否至少有一个元素都满足判断式p，只要有一个元素满足条件就返回true，否则返回true。
// none_of	区间[开始, 结束)中是否所有的元素都不满足判断式p，所有的元素都不满足条件返回true，否则返回false。
/**
template<class InputIterator, class UnaryPredicate>
  bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (!pred(*first)) return false;
    ++first;
  }
  return true;
}
 */

}
