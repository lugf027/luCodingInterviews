/********************************************
* wordBreak139.cpp                              *
* Created by lugf027 on 2020/11/1.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 139. 单词拆分
/// 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
/// 说明：
/// 拆分时可以重复使用字典中的单词。
/// 你可以假设字典中没有重复的单词。

#include <string>
#include <vector>
#include <unordered_set>
#include <cstring>
//#include <algorithm>
//#include <cstdlib>

using namespace std;

/**
 * 超时
 * "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
 * ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
 */
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        str = s.c_str();
        wordSet = new unordered_set<string>(wordDict.begin(), wordDict.end());
        return wordBreakAux(0);
    }

private:
    unordered_set<string> *wordSet;
    const char *str;

    bool wordBreakAux(int step) {
        if (step == strlen(str)) return true;

        string strTemp = "";

        for (; step < strlen(str); ++step) {
            strTemp += str[step];
            if (wordSet->find(strTemp) != wordSet->end()) {
                if (wordBreakAux(step + 1)) return true;
                else continue;
            }
        }

        return false;
    }
};

/**
 * 动态规划-基础解法
 */
class Solution1 {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

/**
 * 动态规划 提升
 */
class Solution2 {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordDictSet;
        int maxWordSize = 0;
        for (const string &word : wordDict) {
            wordDictSet.insert(word);
            maxWordSize = maxWordSize > word.length() ? maxWordSize : word.length();
        }
        vector<bool> dp(s.size() + 1, 0);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0 && j >= i - maxWordSize; --j) {
                string a = s.substr(j, i);
                if (dp[j] && wordDictSet.find(s.substr(j, i-j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

/**
 * 字典树 ？
 */
