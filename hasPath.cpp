#include<cstring>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(str == NULL || rows <= 0 || cols <= 0)
            return false;
        bool** passed = new bool*[rows];
        for(int i = 0;i < rows; i++)
        {
            passed[i] = new bool[cols];
            for(int j = 0;j < cols; j++)
                passed[i][j] = false;
        }
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
            {
                if(dfs(matrix, i, j, passed, rows, cols, str))
                    return true;
            }   
        return false;
    }
    bool dfs(char* matrix,int i, int j, bool** passed, int rows, int cols, char* str)
    {
        if(strlen(str) == 0)
            return true;
        if(i == rows)
        {
            i = 0;
            j++;
        }
        if(i == -1)
        {
            i = rows-1;
            j--;
        }
        if(j == cols || j == -1)
            return false;
        if(passed[i][j] || *(matrix+i*cols + j) != *str)
            return false;
        else
        {
            passed[i][j] = true;
            
            bool flag = dfs(matrix, i+1, j, passed, rows, cols, str+1)
                ||dfs(matrix, i, j+1, passed, rows, cols, str+1)
                ||dfs(matrix, i-1, j, passed, rows, cols, str+1)
                ||dfs(matrix, i, j-1, passed, rows, cols, str+1);
            passed[i][j] = false;
			return flag;    
        }
        
    }
};
//class Solution {
//public:
//    bool hasPath(char* matrix, int rows, int cols, char* str)
//    {
//    	if(str == NULL || rows<=0 || cols <= 0)
//    		return false;
//        bool** passed = new bool*[rows];
//        for(int i = 0;i < rows; i++)
//        {
//            passed[i] = new bool[cols];
//            for(int j = 0;j < cols; j++)
//                passed[i][j] = false;
//        }
//        for(int i = 0; i < rows; i++)
//            for(int j = 0; j < cols; j++)
//            {
//                if(dfs(matrix, i, j, passed, rows, cols, str))
//                    return true;
//            }   
//        return false;
//    }
//    bool dfs(char* matrix,int i, int j, bool** passed, int rows, int cols, char* str)
//    {
//    	if(*str=='\0')
//           return true;
//		if(j == cols)
//		{
//			j = 0;
//			i++;
//		}
//		if(j == -1)
//		{
//			j = cols-1;
//			i--;
//		}
//		if(i < 0 || i >= rows)
//			return false;
//        if(passed[i][j] || matrix[i*cols + j] != *str)
//            return false;
//        else
//        {
//        	cout<<*str<<" ";
//            passed[i][j] = true;
//            bool flag = dfs(matrix, i+1, j, passed, rows, cols, str+1)
//                ||dfs(matrix, i-1, j, passed, rows, cols, str+1)
//                ||dfs(matrix, i, j+1, passed, rows, cols, str+1)
//                ||dfs(matrix, i, j-1, passed, rows, cols, str+1);
//        	passed[i][j] = false;
//        	return flag; 
//        }
//        
//    }
//};
int main()
{
	Solution s;
	char* matrix ="ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";//"ABCESFCSADEE";
	char* str = "SGGFIECVAASABCEHJIGQEM";
	cout<<s.hasPath(matrix,5,8,str);
	return 0;
}
