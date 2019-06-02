#include <stdio.h>

int		main(int argc, char **argv)
{
	int i, j;
	int	first = 1;
	int	ascii[127] = { 0 };

	i = j = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				argv[1][i] += 32;
			}
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				if (ascii[(int)argv[1][i]] == 0)
				{
					j = i;
					while (argv[1][j])
					{
						if (argv[1][j] == argv[1][i])
						{
							ascii[(int)argv[1][i]]++;
						}
						j++;
					}

					if (first == 1)
					{
						printf("%d%c", ascii[(int)argv[1][i]], argv[1][i]);
						first = 0;
					}
					else
					{
						printf(", %d%c", ascii[(int)argv[1][i]], argv[1][i]);
					}
				}
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}

/*
   Assignment name  : count_alpha
   Expected files   : count_alpha.c
   Allowed functions: write, printf
   --------------------------------------------------------------------------------

   Write a program called count_alpha that takes a string and displays the number
   of occurences of its alphabetical characters. Other characters are not counted.
   The order is the order of occurence in the string. The display must be ended by
   a newline.

   The format is in the examples.

   If the number of arguments is not 1, display only a newline.

Examples :
$> ./count_alpha abbcc
1a, 2b, 2c
$> ./count_alpha "abbcc"
1a, 2b, 2c
$> ./count_alpha "abbcc" "dddeef" | cat -e
$
$> ./count_alpha "My Hyze 47y 7." | cat -e
1m, 3y, 1h, 1z, 1e$
$> ./count_alpha "" | cat -e
$

*/
