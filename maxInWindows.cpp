#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        queue<int> b2s;
        vector<int> result;
        if(size == 0) return result;
		if(num.empty()) return result; 
        int i,j;
        for(i = 0, j = 0;j < num.size();j++)
        {
               
            
            if(b2s.empty())
                b2s.push(num[j]);
            else
            {
                if(num[j] > b2s.front())
                {
                    b2s = queue<int>();
                    b2s.push(num[j]);
                }
                else
                {
                    queue<int> temp;
                    while(!b2s.empty() && b2s.front()>=num[j])
                    {
                        temp.push(b2s.front());
                        b2s.pop();
                    }
                    temp.push(num[j]);
                    b2s = temp;
                }
            }
            if(j >= size - 1)
            {
                result.push_back(b2s.front());
                if(num[i] == b2s.front())
                    b2s.pop();
                i++;
            } 
            
        }
        return result;
    }
};
int main()
{
	Solution s;
	int a[8] = {2,3,4,2,6,2,5,1};
	vector<int> n(a, a+8);
	vector<int> r = s.maxInWindows(n, 3);
	for(int i = 0;i < r.size();i++) cout<<r[i]<<endl;
	}
