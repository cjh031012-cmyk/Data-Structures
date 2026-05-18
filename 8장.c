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

///15번
int find_smaller(TreeNode* root, int value) {
	if (root == NULL)
		return 0;
	if (root->key < value)
		printf("%d보다 작은 노드: %d\n", value, root->key);
	find_smaller(root->left, value);
	find_smaller(root->right, value);
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

	int value = 0;
	printf("값을 입력하시오:");
	scanf("%d", &value);
	int smaller = find_smaller(root, value);

	return 0;
}
