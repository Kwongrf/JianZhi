class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int>stk;
        int i = 0, j = 0;
        while(1)
        {
            if(stk.empty() || stk.top()!=popV[j])
            {
                if(i < pushV.size())
                {
                    stk.push(pushV[i]);
                    i++;
                }
                else
                {
                    if(j == popV.size())
                        return true;
                    else
                        return false;
                }
                    
            }
            if(stk.top()==popV[j])
            {
                stk.pop();
                j++;
                if(j == popV.size())
                    return true;
            }
        }
    }
};
