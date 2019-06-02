struct s_node {
        int value;
        struct s_node *next;
};

int     is_looping(struct s_node *node)
{
	struct s_node *r1 = node;
	struct s_node *r2 = node;

	while (r1 && r2)
	{
		r1 = r1->next;
		if (!r1->next)
			return (0);
		if (r1 == r2 || r1->next == r2)
			return (1);
		r1 = r1->next;
		r2 = r2->next;
	}
	return (0);
}

/*
#include <stdlib.h>
#include <stdio.h>
int		main()
{
	struct s_node *n1 = (struct s_node *)malloc(sizeof(struct s_node));
	struct s_node *n2 = (struct s_node *)malloc(sizeof(struct s_node));
	struct s_node *n3 = (struct s_node *)malloc(sizeof(struct s_node));
	struct s_node *n4 = (struct s_node *)malloc(sizeof(struct s_node));
	struct s_node *n5 = (struct s_node *)malloc(sizeof(struct s_node));
	struct s_node *n6 = (struct s_node *)malloc(sizeof(struct s_node));

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n3;

	printf("Result: %d\n", is_looping(n1));
	return (0);
}
*/

/*
Assignment name  : is_looping
Expected files   : is_looping.c
Allowed functions:
--------------------------------------------------------------------------------

ALERT: OPTIMIZED SOLUTION REQUIRED.

Given the first node of a linked list as parameter, create a function which
returns 1 if the linked list is looping, otherwise 0.

The linked list uses the following structure:

struct s_node {
        int value;
        struct s_node *next;
};

The function must be declared as follows:

int     is_looping(struct s_node *node);


Considerations:

- Be careful: the naive solution won't work on our big input, you have to
find a solution with better complexity than O(N^2) time (where N is the
number of nodes).
- The values of each node does not matter.
- The bigger test we will do is on a linked list of 500.000 nodes, with the
beginning of the loop at the middle. It should run in less than 2 seconds.


Example 1:

1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |         v
          |         6
           \        |
            \______/

In this case, it should return 1 (at the node 3 begins the loop).

Example 2:

12 -> 150 -> 30 -> 50 -> 345 -> 120
       ^                         |
       |                         v
       |                        200
        \                      /
         \____________________/

In this case, it should return 1 (the loop begins at node 150).

Example 3:

12 -> 150 -> 30 -> 50 -> 345 -> 120

In this case, it should return 0 (no loop begins).

Example 4:

12 -> 19 -> 14
            ^ \
            | |
            \/

In this case, it should return 1 (the loop begins at node 14).
*/
