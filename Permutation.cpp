#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
//链接：https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?answerType=1&f=discussion
//来源：牛客网
//
//class Solution {
//public:
//    void perm(int pos, string s, set<string> &ret) {
//        if (pos+1 == s.length()) {
//            ret.insert(s);
//            return;
//        }
//        // for循环和swap的含义：对于“ABC”，
//        // 第一次'A' 与 'A'交换，字符串为"ABC", pos为0， 相当于固定'A'
//        // 第二次'A' 与 'B'交换，字符串为"BAC", pos为0， 相当于固定'B'
//        // 第三次'A' 与 'C'交换，字符串为"CBA", pos为0， 相当于固定'C'
//        for (int i = pos; i < s.length(); i++) {
//            swap(s[pos], s[i]);
//            perm(pos+1, s, ret);
//            swap(s[pos], s[i]);
//            // 回溯的原因：比如第二次交换后是"BAC"，需要回溯到"ABC"
//            // 然后进行第三次交换，才能得到"CBA"
//        }
//    }
//    vector<string> Permutation(string s) { 
//        if (s.empty()) return {};
//        set<string> ret;
//        perm(0, s, ret);
//        return vector<string>({ret.begin(), ret.end()});
//    }
//};
class Solution {
public:
    vector<string> Permutation(string str) {
        set<string>all_set;
        vector<string> res;
        if(str.length() == 0) return res;
        combine(str, 0, all_set);
        res.assign(all_set.begin(), all_set.end());
        return res;
    }
    void combine(string str, int pos, set<string> &res)
    {
    	cout<<pos<<endl; 
        if(pos + 1 == str.length())
        {
        	cout<<str<<endl; 
            res.insert(str);
            return;
        }
        else
        {
            for(int i = pos;i < str.length();++i)
            {
            	cout<<i<<endl;
            	cout<<str<<endl;
                swap(str[pos], str[i]);
                cout<<str<<endl;
//                break;
                combine(str, pos+1, res);
                swap(str[pos], str[i]);
            }
        }
    }

};
int main()
{
	Solution s;
	vector<string> res = s.Permutation("abc");
}
