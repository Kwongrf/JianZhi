class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() == 0) return -1;
        
        int count[52];
        int index[52];
        for(int i = 0 ; i < 52; i++)
        {
            count[i] = 0;
            index[i] = -1;
        }
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] >= 'a')
            {
                count[str[i] - 'a' + 26]++;
                if(index[str[i] - 'a' + 26] == -1)
                    index[str[i] - 'a' + 26] = i;
            }
            else
            {
                count[str[i] - 'A']++;
                if(index[str[i] - 'A'] == -1)
                    index[str[i] - 'A'] = i;
            }
        }
        int first = 10001;
        for(int i = 0 ; i < 52; i++)
        {
            if(count[i] == 1)
            {
                if(index[i] < first)
                    first = index[i];
                
            }
        }
        return first;
        
    }
};
