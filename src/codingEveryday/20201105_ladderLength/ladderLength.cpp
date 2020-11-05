/********************************************
* ladderLength.cpp                              *
* Created by lugf027 on 2020/11/5.            *
* Github: https://github.com/lugf027        *
*********************************************/

/// 127 单词接龙
/// 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
///     每次转换只能改变一个字母。
///     转换过程中的中间单词必须是字典中的单词。
/// 说明:
///     如果不存在这样的转换序列，返回 0。
///     所有单词具有相同的长度。
///     所有单词只由小写字母组成。
///     字典中不存在重复的单词。
///     你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

#include <string>
#include <vector>
#include <cstring>

using namespace std;

/**
 * 超时
 */
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        wordList.push_back(beginWord);
        wordList.push_back(endWord);

        vector<vector<int>> wordMap(wordList.size(), vector<int>(wordList.size(), 0));
        int begin = -1, end = -1;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (wordList[i] == beginWord) begin = i;
            if (wordList[i] == endWord)
            {
                if (end == -1 && i == wordList.size() - 1) return 0;
                end = i;
            }

            for (int j = 0; j < wordList.size(); ++j)
            {
                wordMap[i][j] = wordMap[j][i] = judgePass(wordList[i].c_str(), wordList[j].c_str());
            }
        }
        if (begin == -1 || end == -1) return 0;

        stepMin = 0;
        dfs(wordMap, begin, end, 1);
        return stepMin;
    }

private:
    int stepMin;

    void dfs(const vector<vector<int>> &wordMap, int begin, int end, int stepNow)
    {
        if ((stepMin != 0 && stepNow > stepMin) || stepNow > wordMap.size())
        { // 超过最短步数无意义继续了，同时防止局部环的死循环
            return;
        }

        if (wordMap[begin][end] == 1)
        {
            stepMin = stepMin == 0 ? stepNow + 1 : min(stepMin, stepNow + 1);
        }

        for (int i = 0; i < wordMap[begin].size(); ++i)
        {
            if (wordMap[begin][i] == 1)
            {
                dfs(wordMap, i, end, stepNow + 1);
            }
        }
    }

    static int judgePass(const char *str1, const char *str2)
    {
        if (str1 == nullptr || str2 == nullptr || strlen(str1) != strlen(str2)) return 0;
        int count = 0;
        for (int i = 0; i < strlen(str1); ++i)
        {
            if (str1[i] != str2[i])
            {
                if (++count > 1) return 0;
            }
        }
        return count;
    }
};
/**
"cet"
"ism"
["kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now",
 "boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid",
 "ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip",
 "fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig",
 "fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet",
 "too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old",
 "fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip",
 "jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei",
 "wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag",
 "ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his",
 "sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie",
 "mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam",
 "new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog",
 "nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six",
 "ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat",
 "sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw",
 "vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig",
 "rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir",
 "nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos",
 "son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit",
 "fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe",
 "our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep",
 "bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen",
 "odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw",
 "nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew",
 "hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub",
 "low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir",
 "sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow",
 "sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all",
 "pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big",
 "ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she",
 "sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid",
 "gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo",
 "win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol",
 "arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin",
 "dun","pat","ten","mob"]
 */

#include <unordered_map>
#include <queue>

/**
 * 方法一：广度优先搜索 + 优化建图
 */
class Solution1
{
public:
    unordered_map<string, int> word_id;
    vector<vector<int>> edge;

    int nodeNum = 0;

    void addWord(string &word)
    {
        if (!word_id.count(word))
        {
            word_id[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string &word)
    {
        addWord(word);
        int id1 = word_id[word];
        for (char &it:word)
        {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = word_id[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (string &word : wordList)
            addEdge(word);

        addEdge(beginWord);

        if (!word_id.count(endWord))
            return 0;

        vector<int> dis(nodeNum, INT_MAX);
        int begin_id = word_id[beginWord];
        int end_id = word_id[endWord];

        dis[begin_id] = 0;

        queue<int> que;
        que.push(begin_id);
        while (!que.empty())
        {
            int x = que.front();
            que.pop();
            if (x == end_id)
                return dis[end_id] / 2 + 1;

            for (int &it:edge[x])
            {
                if (dis[it] == INT_MAX)
                {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }
};

/**
 * 方法二：双向广度优先搜索
 */
class Solution2
{
public:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;

    void addWord(string &word)
    {
        if (!wordId.count(word))
        {
            wordId[word] = nodeNum++;
            edge.emplace_back();
        }
    }

    void addEdge(string &word)
    {
        addWord(word);
        int id1 = wordId[word];
        for (char &it : word)
        {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (string &word : wordList)
        {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord))
        {
            return 0;
        }

        vector<int> disBegin(nodeNum, INT_MAX);
        int beginId = wordId[beginWord];
        disBegin[beginId] = 0;
        queue<int> queBegin;
        queBegin.push(beginId);

        vector<int> disEnd(nodeNum, INT_MAX);
        int endId = wordId[endWord];
        disEnd[endId] = 0;
        queue<int> queEnd;
        queEnd.push(endId);

        while (!queBegin.empty() && !queEnd.empty())
        {
            int queBeginSize = queBegin.size();
            for (int i = 0; i < queBeginSize; ++i)
            {
                int nodeBegin = queBegin.front();
                queBegin.pop();
                if (disEnd[nodeBegin] != INT_MAX)
                {
                    return (disBegin[nodeBegin] + disEnd[nodeBegin]) / 2 + 1;
                }
                for (int &it : edge[nodeBegin])
                {
                    if (disBegin[it] == INT_MAX)
                    {
                        disBegin[it] = disBegin[nodeBegin] + 1;
                        queBegin.push(it);
                    }
                }
            }

            int queEndSize = queEnd.size();
            for (int i = 0; i < queEndSize; ++i)
            {
                int nodeEnd = queEnd.front();
                queEnd.pop();
                if (disBegin[nodeEnd] != INT_MAX)
                {
                    return (disBegin[nodeEnd] + disEnd[nodeEnd]) / 2 + 1;
                }
                for (int &it : edge[nodeEnd])
                {
                    if (disEnd[it] == INT_MAX)
                    {
                        disEnd[it] = disEnd[nodeEnd] + 1;
                        queEnd.push(it);
                    }
                }
            }
        }
        return 0;
    }
};
