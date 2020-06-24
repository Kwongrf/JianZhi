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
            if(stage == 0)//������֮����������� ������С���㰡
            {
                if(*string >= '0' && *string <= '9')
                    stage = 1;
                else if(*string == '.')
                    stage = 3;
                else
                    return false;
            }
            else if(stage == 1)//���ֺ��������E/e��С�����������
            {
                if(*string == 'E' || *string == 'e')
                    stage = 2;
                else if(*string == '.')
                    stage = 3;
                else if(*string < '0' || *string > '9')
                    return false;
            }
            else if(stage == 2)//e����E֮�� ��λ�ɳ���+-���������������
            {
                if ( *string >= '0' && *string <= '9')
                    stage = 5;
                else if(*string == '+' || *string == '-' )
                    stage = 4;
                else
                    return false;
            }
            else if(stage == 3)//С����֮��ֻ�������ֻ���E/e,
            {
                if(*string == 'E' || *string == 'e')
                    stage = 2;
                else if(*string < '0' || *string > '9')
                    return false;
            }
            else if(stage == 4) //e������+-�ű���������
            {
                if(*string >= '0' && *string <= '9')
                    stage = 5;
                else
                    return false;
            }
            else if (stage == 5)//e�������ֺ����������
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
