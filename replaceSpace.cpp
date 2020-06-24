class Solution {
public:
	void replaceSpace(char *str,int length) {
		int count = 0;
        if(length <= 0) return;
		for(int i = 0;i < length; i++)
		{
			if(str[i] == ' ')
				count++;
		}
        if(count) return;
		int new_length = length + 2 * count;

		int j = new_length - 1;
		for(int i = length - 1;i >= 0;i--)
		{
			if(str[i] == ' ')
			{
				str[j] = '0';
				j--;
				str[j] = '2';
				j--;
				str[j] = '%';
				j--;
			}
			else
			{
				str[j] = str[i];
				j--;
			}	
			
		}
	}
};
