#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	if(sequence.empty())
    		return false;
        int max = sequence[sequence.size()-1];
        int pivot = NULL;
        return verify(sequence, 0, sequence.size()-1, pivot, max);
        
    }
    bool verify(vector<int> seq, int start, int end, int pivot, int max)
    {
        if(start >= end)
        {
            return true;
        }
        int i = end - 1;
        for(; i >= start && seq[i] > seq[end]; i--)
            if(seq[i] > max)
                max = seq[i];
        if(pivot && max > pivot)
            return false;
        
        pivot = seq[end];
        return verify(seq, start, i, pivot, seq[i])&&verify(seq, i+1, end-1, NULL, seq[end-1]);
        
    }
};
int main()
{
	Solution s;
	int a[9] = {2,10,5,3,17,15,19,18,12};
	vector<int> seq(a, a+9);
	cout<<s.VerifySquenceOfBST(seq);
}
