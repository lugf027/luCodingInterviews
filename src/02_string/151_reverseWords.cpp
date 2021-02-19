/*************************************************************
 * Name     : 151_reverseWords
 * Title    : 151. 翻转字符串里的单词
 * Author   : lugf027 9:59 2021/2/19.
 * Describe : 
 *************************************************************/

#include "util.h"

namespace reverseWords {
    class Solution {
    public:
        string reverseWords(string s) {
            reverse(s.begin(), s.end());

            int sLen = s.size();
            int idx = 0;
            for (int start = 0; start < sLen; ++start) {
                if (s[start] != ' ') {
                    // 填一个空白字符然后将idx移动到下一个单词的开头位置
                    if (idx != 0) s[idx++] = ' ';

                    // 循环遍历至单词的末尾
                    int end = start;
                    while (end < sLen && s[end] != ' ')
                        s[idx++] = s[end++];

                    // 反转整个单词
                    reverse(s.begin() + idx - (end - start), s.begin() + idx);

                    // 更新start，去找下一个单词
                    start = end;
                }
            }
            s.erase(s.begin() + idx, s.end());
            return s;
        }
    };

    class Solution1 {
    public:
        string reverseWords(string s) {
            int left = 0, right = s.size() - 1;
            // 去掉字符串开头的空白字符
            while (left <= right && s[left] == ' ') ++left;
            // 去掉字符串末尾的空白字符
            while (left <= right && s[right] == ' ') --right;

            deque<string> d;
            string word;

            while (left <= right) {
                char ch = s[left];
                if (word.size() && ch == ' ') {
                    d.push_back(move(word));
                    word = "";
                } else if (ch != ' ')
                    word += ch;
                ++left;
            }
            d.push_front(move(word));

            string ans;
            while (!d.empty()) {
                ans += d.front();
                d.pop_front();
                if (!d.empty()) ans += ' ';
            }
            return ans;
        }
    };

    class Solution2 {
    public:
        string reverseWords(string s) {
            int left = 0, right = s.size() - 1;
            // 去掉字符串开头的空白字符
            while (left <= right && s[left] == ' ') ++left;
            // 去掉字符串末尾的空白字符
            while (left <= right && s[right] == ' ') --right;

            stack<string> d;
            string word;

            while (left <= right) {
                char ch = s[left];
                if (word.size() && ch == ' ') {
                    d.push(move(word));
                    word = "";
                } else if (ch != ' ')
                    word += ch;
                ++left;
            }
            d.push(move(word));

            string ans;
            while (!d.empty()) {
                ans += d.top();
                d.pop();
                if (!d.empty()) ans += ' ';
            }
            return ans;
        }
    };
}
