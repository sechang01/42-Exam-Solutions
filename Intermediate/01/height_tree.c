	struct s_node {
		int           value;
		struct s_node **nodes;
	};


int height_tree(struct s_node *root)
{
	if (root == 0)
		return (-1);
	if (root->nodes == 0 || *(root->nodes) == 0)
		return (0);

	int i = 0;
	int max_height = height_tree((root->nodes)[i]);
	int cur_height;
	while ((root->nodes)[++i] != 0)
	{
		cur_height = height_tree((root->nodes)[i]);
		if (cur_height > max_height)
			max_height = cur_height;
	}
	return (max_height + 1);
}
