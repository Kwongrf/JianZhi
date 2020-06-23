class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), compAsc);
        string s = "";
        for(int i = 0; i < numbers.size(); i++)
        {
            s += to_string(numbers[i]);
        }
        return s;
            
    }
    static bool compAsc(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        if((s1 + s2) < (s2 + s1))
            return true;
        else
            return false;
    }
};
