/********************************************
* wordBreak140.cpp                              *
* Created by lugf027 on 2020/11/1.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 140.单词拆分
/// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，
/// 在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
/// 说明：
/// 拆分时可以重复使用字典中的单词。
/// 你可以假设字典中没有重复的单词。

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;

public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(const string &s, int index) {
        if (!ans.count(index)) {
            if (index == s.size()) {
                ans[index] = {""};
                return;
            }
            ans[index] = {};
            for (int i = index + 1; i <= s.size(); ++i) {
                string word = s.substr(index, i - index);
                if (wordSet.count(word)) {
                    backtrack(s, i);
                    for (const string &succ: ans[i]) {
                        ans[index].push_back(succ.empty() ? word : word.append(" ").append(succ));
                    }
                }
            }
        }
    }
};
