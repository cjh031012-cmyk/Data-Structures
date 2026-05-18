///14번
int get_sum(TreeNode* root) {
	if (root == NULL)
		return 0;
	int sum = root->key;
	sum = sum + get_sum(root->left) + get_sum(root->right);
	return sum;
}

int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	int sum = get_sum(root);
	printf("노드의 합은%d입니다", sum);

	return 0;
}
