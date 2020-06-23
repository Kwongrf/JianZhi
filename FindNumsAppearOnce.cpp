作者：宇神后桌
链接：https://www.nowcoder.com/questionTerminal/e02fdb54d7524710a7d664d082bb7811?f=discussion
来源：牛客网

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
  if(data.empty()) return ;
        
        int x = 0;
        for(auto i : data) x ^= i;
        
        int n1 = (~(~x + 1)) + 1; // 关键所在！ x - (x & (x-1)) // x^(x-1)&x;
        *num1 = *num2 = 0;
        for(auto i : data) {
            if(i & n1) 
                *num1 ^= i;
            else
                *num2 ^= i;
        }
    }
    
};
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty()) return;
        map<int, bool> appeared;
        for(int i = 0; i < data.size(); i++) 
            appeared[data[i]] = !appeared[data[i]];
        int c = 0;
        for(int i = 0; i < data.size(); i++)
        {
            if(appeared[data[i]]&&c==0)
            {
                *num1 = data[i];
                c++;
            }  
            else if(appeared[data[i]]&&c==1)
            {
                *num2 = data[i];
                return ;
            }  
        }
            
    }
};
