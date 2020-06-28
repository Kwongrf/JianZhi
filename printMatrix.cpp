#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int i = 0,j = 0;
        int h = matrix.size();
        int w = matrix[0].size();
        
        vector<int> res;
        if(w == 0 || h == 0) return res;
        
        int th = h,tw = w, k = 0;
        while(th != 0 && tw != 0)
        {
            for(; k < tw ; k++)
                res.push_back(matrix[i][j+k]);
             
            j = j + k - 1; 
            i++;
            th--;
            if(th != 0 && tw != 0 && j < w)
            {
            	k = 0;
	            for(; k < th ; k++)
	                res.push_back(matrix[i+k][j]);
	            
	            i = i + k - 1;
	            j--;
	            tw--;
			}
            if(th != 0 && tw != 0 && i < h)
            {
            	k = 0;
	            for(; k < tw; k++)
	                res.push_back(matrix[i][j-k]);
	            
	            j = j - k + 1;
	            i--;
	            th--;
			}
            if(th != 0 && tw != 0 && j < w)
            {
            	k = 0;
	            for(; k < th; k++)
	                res.push_back(matrix[i-k][j]);
	            i = i - k + 1;
	            j++;
	            tw--;
	            
			}
            k = 0;
        }
        return res;
    }
};
int main()
{
	Solution s;
	vector<vector<int> > m;
//	int a[4] = {1,2,3,4};
//	vector<int> a1(a, a+4);
//	m.push_back(a1);
//	int b[4] = {5,6,7,8};
//	vector<int> b1(b, b+4);
//	m.push_back(b1);
//	int c[4] = {9,10,11,12};
//	vector<int> c1(c, c+4);
//	m.push_back(c1);
//	int d[4] = {13,14,15,16};
//	vector<int> d1(d, d+4);
//	m.push_back(d1);
//	int e[4] = {17,18,19,20};
//	vector<int> e1(e, e+4);
//	m.push_back(e1);
	vector<int> res = s.printMatrix(m);
	for(int i = 0; i < res.size();i++)
		cout<<res[i]<<" ";
}
