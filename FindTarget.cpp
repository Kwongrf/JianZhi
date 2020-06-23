#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
//    bool Find(int target, vector<vector<int> > array) {
//        int w = array[0].size();
//        int h = array.size();
//        if(w == 0 || h == 0)
//            return false;
//        int x0 = 0;
//        int x1 = h-1;
//        int y0 = 0;
//        int y1 = w-1;
//        return search(target, array, x0, x1, y0, y1, w, h);
//    }
//    bool search(int target, vector<vector<int> > a, int x0,int x1, int y0, int y1, int w, int h)
//    {
//        int x = (x0 + x1) / 2;
//        int y = (y0 + y1) / 2;
//        if(x0 > x1 || y0 > y1)
//            return false;
//        if(x0 < 0 || y0 < 0 || x0 >= h || y0 >= w 
//          || x1 < 0 || y1 < 0 || x1 >= h || y1 >= w )
//            return false;
//        
//        if(a[x][y] == target)
//            return true;
////        cout<<a[x][y]<<" "<<x0<<" "<<x1<<" "<<y0<<" "<<y1<<endl; 
//        if(x0 == x1 && y0 == y1)
//            return false;
//           
//        if(a[x][y] < target)
//        { 
//            
//            return search(target, a, x+1, x1, y+1, y1, w, h)
//                ||search(target, a, x+1, x1, y0, y, w, h)//左下角 
//                ||search(target, a, x0, x, y+1, y1, w, h);//右上角 
//        }
//        else
//        {
//            return search(target, a, x0, x-1, y0, y-1, w, h)
//                ||search(target, a, x, x1, y0, y-1, w, h)//左下角 
//                ||search(target, a, x0, x-1, y, y1, w, h);//右上角 
//        }
//    }
//    
//};
//链接：https://www.nowcoder.com/questionTerminal/abc3fe2ce8e146608e868a70efebf62e?f=discussion
//来源：牛客网

  bool Find(int target, vector<vector<int> > array) {
        int rowCount = array.size();
        int colCount = array[0].size();
        int i,j;
        for(i=rowCount-1,j=0;i>=0&&j<colCount;)
        {
            if(target == array[i][j])
                return true;
            if(target < array[i][j])
            {
                i--;
                continue;
            }
            if(target > array[i][j])
            {
                j++;
                continue;
            }
        }
        return false;
    }
};
int main()
{
	vector<vector<int> > arr;
	int a[4] = {1,2,8,9};
	vector<int> t(a, a+4);
	arr.push_back(t);
	int b[4] = {2,4,9,12};
	vector<int> y(b, b+4);
	arr.push_back(y);
	int c[4] = {4,7,10,13};
	vector<int> u(c, c+4);
	arr.push_back(u);
	int d[4] = {6,8,11,15};
	vector<int> v(d, d+4);
	arr.push_back(v);
	
	Solution s;
	cout<<s.Find(7, arr);
	
 } 
