#include<stdio.h>
#include<stdlib.h>

int main()
{
	char str[100] = {0};
	char ch;
	int i, j;

	i = 0;
	ch = getchar();
	while (ch != '@')
	{
		*(str + i) = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
	j = i-1;

	i = 0;
	while (i < j)
	{
		if (str[i] != str[j])
			break;
		i++; j--;
	}
	if (i >= j)
		printf("\n%s is palindrome", str);
	else
		printf("\n%s is not palindrome", str);

	return 0;
}