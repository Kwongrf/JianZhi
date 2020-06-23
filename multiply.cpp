//class Solution {
//public:
//    vector<int> multiply(const vector<int>& A) {
//        vector<int> result;
//        if(A.empty())
//            return result;
//        for(int i = 0;i < A.size(); i++)
//            result.push_back(0);
//        int prev = 1, after = 1, depth = 0;
//        mul(A, result, depth, prev, after);
//        return result;
//    }
//    void mul(vector<int> A, vector<int> &result, int depth, int prev,int &after)
//    {
//        if(depth == A.size())
//            return;
//        mul(A,result, depth+1, prev*A[depth], after);
//        result[depth] = prev * after;
//        after *= A[depth];
//    }
//};
//链接：https://www.nowcoder.com/questionTerminal/94a4d381a68b47b7a8bed86f2975db46?f=discussion
//来源：牛客网

class Solution {
public:
  vector<int> multiply(const vector<int>& A) {
  vector<int> vec;
  int sz=A.size();
  if(sz==0)
   return vec;
  vec.push_back(1);
  for(int i=0;i<sz-1;i++)
   vec.push_back(vec.back()*A[i]);
  int tmp=1;
  for(int i=sz-1;i>=0;i--)
  {
   vec[i]=vec[i]*tmp;
   tmp=tmp*A[i];
  }
  return vec;
    }
};
