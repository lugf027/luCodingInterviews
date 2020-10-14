/********************************************
* commonChars.cpp                              *
* Created by lugf027 on 2020/10/14.            *
* Github: https://github.com/lugf027        *
*********************************************/

/**
 * 给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
你可以按任意顺序返回答案。
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 3 层循环不改变参数
     * @param A
     * @return
     */
    vector<string> commonChars(vector<string> &A) {
        vector<string> ret;
        if (A.empty())
            return ret;

        vector<char> first;
        for (char ch:A.at(0)) {
            first.push_back(ch);
        }

        for (int i = 1; i < A.size(); ++i) {
            vector<char> newChs;
            for (int j = 0; j < A.at(i).size(); ++j) {
                for (int m = 0; m < first.size(); ++m) {
                    if (first.at(m) == A.at(i).at(j)) {
                        newChs.push_back(first.at(m));
                        first.at(m) = 0;
                        break;
                    }
                }
            }
            first.clear();
            first = newChs;
        }

        for (char ch: first) {
            ret.emplace_back(1, ch);
        }

        return ret;
    }

    /**
     * 2层，计数
     * @param A
     * @return
     */
    vector<string> commonChars1(vector<string> &A) {
        vector<int> minfreq(26, INT_MAX);
        vector<int> freq(26);
        for (const string& word: A) {
            fill(freq.begin(), freq.end(), 0);
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = min(minfreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1, i + 'a');
            }
        }
        return ans;
    }
};
