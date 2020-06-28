#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
//���ӣ�https://www.nowcoder.com/questionTerminal/fe6b651b66ae47d7acce78ffdd9a96c7?answerType=1&f=discussion
//��Դ��ţ����
//
//class Solution {
//public:
//    void perm(int pos, string s, set<string> &ret) {
//        if (pos+1 == s.length()) {
//            ret.insert(s);
//            return;
//        }
//        // forѭ����swap�ĺ��壺���ڡ�ABC����
//        // ��һ��'A' �� 'A'�������ַ���Ϊ"ABC", posΪ0�� �൱�ڹ̶�'A'
//        // �ڶ���'A' �� 'B'�������ַ���Ϊ"BAC", posΪ0�� �൱�ڹ̶�'B'
//        // ������'A' �� 'C'�������ַ���Ϊ"CBA", posΪ0�� �൱�ڹ̶�'C'
//        for (int i = pos; i < s.length(); i++) {
//            swap(s[pos], s[i]);
//            perm(pos+1, s, ret);
//            swap(s[pos], s[i]);
//            // ���ݵ�ԭ�򣺱���ڶ��ν�������"BAC"����Ҫ���ݵ�"ABC"
//            // Ȼ����е����ν��������ܵõ�"CBA"
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
