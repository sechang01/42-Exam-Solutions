int	is_anagram(char *a, char *b)
{
	int ascii[127] = { 0 };
	int	i = 0;

	while (a[i])
	{
		ascii[(int)a[i]]++;
		i++;
	}
	i = 0;
	while (b[i])
	{
		ascii[(int)b[i]]--;
		i++;
	}
	i = 0;
	while (i < 127)
	{
		if (ascii[i] != 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>
int		main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%d\n", is_anagram(argv[1], argv[2]));
	}
	return (0);
}
*/
