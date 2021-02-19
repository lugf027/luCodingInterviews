/*************************************************************
 * Name     : 28_strStr
 * Title    : 28. 实现 strStr()
 * Author   : lugf027 17:19 2021/1/20.
 * Describe :
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
 * 如果不存在，则返回  -1。
 *************************************************************/

#include "util.h"

namespace strStr {
    /**
     * BF 算法
     * 时间复杂度：o(mn)
     */
    class Solution {
    public:
        int strStr(string haystack, string needle) {
            if (haystack.empty() && needle.empty()) return 0;
            for (int i = 0; i <= (int) haystack.size() - (int) needle.size(); ++i) {
                if (needle == haystack.substr(i, needle.size())) return i;
            }
            return -1;
        }
    };

    /**
     * KMP
     * 时间复杂度：o(m+n)
     */
    class Solution1 {
    private:
        void getNext(const string &p, vector<int> next) {
            next[0] = -1;
            int i = 0, j = -1;

            while (i < p.size()) {
                if (j == -1 || p[i] == p[j]) {
                    ++i;
                    ++j;
                    next[i] = j;
                } else
                    j = next[j];
            }
        }

    public:
        int strStrKMP(string haystack, string needle) {
            vector<int> next;
            getNext(needle, next);
            int i = 0;
            int j = 0;

            while (i < haystack.size() && j < needle.size()) {
                if (j == -1 || haystack[i] == needle[j]) {
                    ++i;
                    ++j;
                } else {
                    j = next[j];
                }
            }

            if (j == needle.size())
                return i - j;
            else
                return -1;
        }
    };

    /**
     * 双指针 - 线性时间复杂度
     * 实际还是 BF ...
     */
    class Solution2 {
    public:
        int strStr(string haystack, string needle) {
            if (needle.empty()) return 0;
            int pHaystack = 0;
            int haystackLen = haystack.size();
            int needleLen = needle.size();
            while (pHaystack < haystackLen - needleLen + 1) {
                // find the position of the first needle character in the haystack string
                while (pHaystack < haystackLen - needleLen + 1 && haystack[pHaystack] != needle[0]) ++pHaystack;

                // compute the max match string
                int curLen = 0;
                int pNeedle = 0;
                while (pNeedle < needleLen && pHaystack < haystackLen && haystack[pHaystack] != needle[pNeedle]) {
                    ++pHaystack;
                    ++pNeedle;
                    ++curLen;
                }

                // if the whole needle string is found, return its start position
                if (curLen == needleLen) return pHaystack - needleLen;
                // otherwise, backtrack
                pHaystack = pHaystack - curLen + 1;
            }
            return -1;
        }
    };

    /**
     * Rabin Karp - 常数复杂度
     * 在常数时间生成子串的哈希码
     * --> 滚动哈希：常数时间生成哈希码
     */
    class Solution3 {
    private:
        int charToInt(int index, const string &s) {
            return (int) s[index] - (int) 'a';
        }

    public:
        int strStr(string haystack, string needle) {
            if (needle.empty() || needle.size() > haystack.size()) return -1;
            // base value for the rolling hash function
            int a = 26;
            // modulus value for the rolling hash function to avoid overflow
            long modulus = (long) pow(2, 31);

            // compute the hash of strings haystack[:L], needle[:L]
            long h = 0, refH = 0;
            for (int i = 0; i < needle.size(); ++i) {
                h = (h * a + charToInt(i, haystack)) % modulus;
                refH = (refH * a + charToInt(i, needle)) % modulus;
            }
            if (h == refH) return 0;

            // const value to be used often : a**L % modulus
            long aL = 1;
            for (int i = 1; i <= needle.size(); ++i)
                aL = (aL * a) % modulus;

            for (int start = 1; start < (int) haystack.size() - (int) needle.size() + 1; ++start) {
                // compute rolling hash in O(1) time
                h = (h * a - charToInt(start - 1, haystack) * aL
                     + charToInt(start + needle.size() - 1, haystack)) % modulus;
                if (h == refH) return start;
            }
            return -1;
        }
    };
}
