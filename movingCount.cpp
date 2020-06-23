#include<cstring>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows == 0 || cols == 0)
            return 0;
        bool** passed = new bool*[rows];
        for(int i = 0; i < rows; i++)
        {
            passed[i] = new bool[cols];
            for(int j = 0; j < cols;j++)
                passed[i][j] = false;
        }    
            
        int count = 0;
        dfs(0, 0, threshold, rows, cols, count, passed);
        return count;
    }
    void dfs(int i, int j, int th, int rows, int cols, int &count, bool** &passed)
    {
        if(i >= rows || j >= cols || i < 0 || j < 0)
            return;
        if(passed[i][j])
            return;
        if(sumIndex(i) + sumIndex(j) > th)
            return;
        
        count+=1;
        passed[i][j] = true;
        dfs(i, j+1, th, rows, cols, count, passed);
        dfs(i+1, j, th, rows, cols, count, passed);
        dfs(i, j-1, th, rows, cols, count, passed);
        dfs(i-1, j, th, rows, cols, count, passed);
        
    }
    int sumIndex(int i)
    {
        int s = 0;
        while(i)
        {
            s += i%10;
            i = i/10;
        }
        return s;
    }
};
int main()
{
	Solution s;
	cout<<s.movingCount(5,10,10)<<endl;
	cout<<s.movingCount(15,20,20)<<endl;
 } 
