#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
         vector<vector<int> > result;
        if(sum <= 1) return result;
        int i, j;
       
        
        for(j = (int)sqrt(2*sum);j <= sum/2+1;j++)
        {
            int right = j*j + j - 2 * sum;
            i = (int)sqrt(right);
            
            if(i*(i+1) == right )
            {
                vector<int> tmp;
                for(int k = i+1;k <= j;k++) tmp.push_back(k);
                result.push_back(tmp);
            }
            else if( i*(i-1) == right )
            {
                vector<int> tmp;
                for(int k = i;k <= j;k++) tmp.push_back(k);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
int main()
{
	Solution s;
	s.FindContinuousSequence(9);
}
