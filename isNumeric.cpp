class Solution {
public:
    bool isNumeric(char* string)
    {
        if(*string == '\0')
            return false;
        int stage = -1;
        if(*string == '+' || *string == '-')
            stage = 0;
        else if( *string >= '0' || *string <= '9')
            stage = 1;
        else
            return false;
        string++;
        while(*string != '\0')
        {
            if(stage == 0)//正负号之后必须是数字 可以是小数点啊
            {
                if(*string >= '0' && *string <= '9')
                    stage = 1;
                else if(*string == '.')
                    stage = 3;
                else
                    return false;
            }
            else if(stage == 1)//数字后面可以是E/e，小数点或者数字
            {
                if(*string == 'E' || *string == 'e')
                    stage = 2;
                else if(*string == '.')
                    stage = 3;
                else if(*string < '0' || *string > '9')
                    return false;
            }
            else if(stage == 2)//e或者E之后 首位可出现+-，其余必须是数字
            {
                if ( *string >= '0' && *string <= '9')
                    stage = 5;
                else if(*string == '+' || *string == '-' )
                    stage = 4;
                else
                    return false;
            }
            else if(stage == 3)//小数点之后，只能是数字或者E/e,
            {
                if(*string == 'E' || *string == 'e')
                    stage = 2;
                else if(*string < '0' || *string > '9')
                    return false;
            }
            else if(stage == 4) //e出现了+-号必须是数字
            {
                if(*string >= '0' && *string <= '9')
                    stage = 5;
                else
                    return false;
            }
            else if (stage == 5)//e出现数字后必须是数字
            {
                if(*string < '0' || *string > '9')
                    return false;
            }
            string++;
        }
        if(stage == 0 || stage == 2 || stage == 4)
            return false;
        else
            return true;
    }

};
