#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n < 0) return str;
        if(str.length() == 0) return str;
        string s1 = str.substr(0,n % str.length());
        cout<<s1<<endl;
        string s2 = str.substr(n % str.length());
        cout<<s2<<endl;
        return s2 + s1;
    }
};
int main()
{
	Solution s;
	string str = "abcXYZ";
	cout<<s.LeftRotateString(str,-9); 
}

