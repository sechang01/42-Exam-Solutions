typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char water = tab[begin.y][begin.x];

	tab[begin.y][begin.x] = 'F';
	if (begin.y-1 >= 0 && tab[begin.y-1][begin.x] == water)
	{
		begin.y -= 1;
		flood_fill(tab, size, begin);
		begin.y += 1;
	}
	if (begin.x-1 >= 0 && tab[begin.y][begin.x-1] == water)
	{
		begin.x -= 1;
		flood_fill(tab, size, begin);
		begin.x += 1;
	}
	if (begin.y+1 < size.y && tab[begin.y+1][begin.x] == water)
	{
		begin.y += 1;
		flood_fill(tab, size, begin);
		begin.y -= 1;
	}
	if (begin.x+1 < size.x && tab[begin.y][begin.x+1] == water)
	{
		begin.x += 1;
		flood_fill(tab, size, begin);
		begin.x -= 1;
	}
}

/*
// Test Main
#include <stdlib.h>
#include <stdio.h>
int		main()
{
	char **area;
	t_point size = {5, 8};
	t_point begin = {2, 2};

	area = (char **)malloc(sizeof(char *) * 8);
	for (int i = 0; i < 8; i++)
	{
		area[i] = (char *)malloc(sizeof(char) * 5);
		for (int j = 0; j < 5; j++)
		{
			area[i][j] = '0';
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf(" %c ", area[i][j]);
		}
		printf("\n");
	}

	flood_fill(area, size, begin);

	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf(" %c ", area[i][j]);
		}
		printf("\n");
	}
	return (0);
}
*/

/*
   Assignment name  : flood_fill
   Expected files   : *.c, *.h
   Allowed functions: -
   --------------------------------------------------------------------------------

   Write a function that takes a char ** as a 2-dimensional array of char, a
   t_point as the dimensions of this array and a t_point as the starting point.

   Starting from the given 'begin' t_point, this function fills an entire zone
   by replacing characters inside with the character 'F'. A zone is an group of
   the same character delimitated horizontally and vertically by other characters
   or the array boundry.

   The flood_fill function won't fill diagonally.

   The flood_fill function will be prototyped like this:
   void  flood_fill(char **tab, t_point size, t_point begin);

   The t_point structure is prototyped like this:

   typedef struct  s_point
   {
   int           x;
   int           y;
   }               t_point;

Example:

$> cat test_main.c
#include "test_functions.h"
#include "flood_fill.h"

int main(void)
{
char **area;
t_point size = {8, 5};
t_point begin = {2, 2};
char *zone[] = {
"1 1 1 1 1 1 1 1",
"1 0 0 0 1 0 0 1",
"1 0 0 1 0 0 0 1",
"1 0 1 1 0 0 0 1",
"1 1 1 0 0 0 0 1",
}

area = make_area(zone);
print_tab(area);
flood_fill(area, size, begin);
putc('\n');
print_tab(area);
return (0);
}

$> gcc flood_fill.c test_main.c test_functions.c -o flood_fill; ./flood_fill
1 1 1 1 1 1 1 1
1 0 0 0 1 0 0 1
1 0 0 1 0 0 0 1
1 0 1 0 0 0 0 1
1 1 0 0 0 0 0 0

1 1 1 1 1 1 1 1
1 F F F 1 0 0 1
1 F F 1 0 0 0 1
1 F 1 0 0 0 0 1
1 1 0 0 0 0 0 0
$>

*/
