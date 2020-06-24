class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str!='\0' && *pattern == '\0')
            return false;
        
        if(*(pattern+1) == '\0' || *(pattern+1) != '*')
        {
            if(*str == *pattern || (*pattern == '.' && *str != '\0'))
                return match(str + 1, pattern + 1);
            else
                return false;
        }
        else
        {
            if(*str == *pattern || (*pattern == '.' && *str != '\0'))
                return match(str, pattern+2) || match(str+1,pattern);
            else
                return match(str, pattern+2);
        }
        
            
    }
};
