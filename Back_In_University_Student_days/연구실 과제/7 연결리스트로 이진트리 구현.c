#include<stdio.h>
#include<stdlib.h>

typedef struct __treenode {
	struct __treenode* left;
	int data;
	struct __treenode* right;
}TreeNode; // Ʈ����� ����ü

TreeNode* makenewTreeNode(int data)
{
	TreeNode* treenode = (TreeNode*)malloc(sizeof(TreeNode));
	treenode->data = data;
	treenode->left = NULL;
	treenode->right = NULL;

	return treenode;
} // ���ο� ��带 �����ϴ� �Լ�


void callMenu(); // ���� �޴��� ���
int getNewData(); // �����͸� �Է¹޴� �Լ�
void setnewTreeNode(TreeNode** rootNode, int data); // ���ο� ��带 Ʈ���� ��������
TreeNode* searchNode(TreeNode** rootNode, int data); // �����Ϳ� �ش��ϴ� ��带 ã�Ƽ� ��ȯ����
TreeNode* searchRightsubEndofleft(TreeNode* Ptr); // left ���� Ʈ���� right ���� Ʈ���� ���� left����� left�� ���̴� �Լ�

void func1(TreeNode** rootNode); // �����͸� �Է¹޾� ���ο� ��带 Ʈ���� ��������
void func2(TreeNode** rootNode); // ���� ��ȸ�� Ʈ���� ���
void func3(TreeNode** rootNode); // ���� �Լ�

int main()
{
	TreeNode* rootNode;
	rootNode = NULL;
	int selectNum = 0;

	while (1)
	{
		callMenu();
		printf("��ȣ�� �Է��ϼ���.\n>>");
		scanf("%d", &selectNum);
		switch (selectNum)
		{
			case 1:
				func1(&rootNode);
				break;
			case 2:
				func2(&rootNode);
				printf("\n");
				break;
			case 3:
				func3(&rootNode);
				break;
			default:
				break;
		}

	}

	return 0;
}

void callMenu()
{
	printf("====================\n");
	printf("1.���ο� ������ �Է�\n");
	printf("2.��� ������ ���\n");
	printf("3.���� ������ ����\n");
	printf("====================\n");

	return;
}

int getNewData()
{
	int data = 0;
	printf("�Է� �� ������ �Է��ϼ���.\n>>");
	scanf("%d", &data);

	return data;
}

void setnewTreeNode(TreeNode** rootNode, int data)
{
	if (*rootNode == NULL) // ������� ��� �� �ڸ��� ���ο� ��带 Ʈ���� ��������
	{
		(*rootNode) = makenewTreeNode(data);
		return;
	}

	if ((*rootNode)->data >= data) // �����Ͱ� ���� ���
	{
		setnewTreeNode(&((*rootNode)->left), data);
	}
	else if ((*rootNode)->data < data) // �����Ͱ� Ŭ ���
	{
		setnewTreeNode(&((*rootNode)->right), data);
	}

	return;
}

TreeNode* searchNode(TreeNode** rootNode, int data)
{
	TreeNode* Ptr = *rootNode;
	TreeNode* temp;
	while (Ptr->data != data)
	{
		if (Ptr->data >= data)
		{
			if (Ptr->left->data == data)
				temp = Ptr;
			Ptr = Ptr->left;
			if (Ptr->data == data)
				temp->left = Ptr->right;
		}
		else
		{
			if (Ptr->right->data == data)
				temp = Ptr;
			Ptr = Ptr->right;
			if (Ptr->data == data)
				temp->right = Ptr->right;
		}
	}
	
	return Ptr;
}

TreeNode* searchRightsubEndofleft(TreeNode* Ptr)
{
	if (Ptr->left == NULL)
		return Ptr;
	else
		return searchRightsubEndofleft(Ptr->left);
}

void func1(TreeNode** rootNode)
{
	int data = getNewData();

	if (rootNode == NULL)
	{
		(*rootNode) = makenewTreeNode(data);
	}
	else
	{
		setnewTreeNode(rootNode, data);
	}

	return;
}

void func2(TreeNode** rootNode)
{
	if (*rootNode == NULL)
		return;
	func2(&((*rootNode)->left));
	func2(&((*rootNode)->right));
	printf("%d ", (*rootNode)->data);

	return;
}

void func3(TreeNode** rootNode)
{
	TreeNode* Ptr;
	int delData = 0;
	printf("���� �Ͻ� �����͸� �Է����ּ���.\n>>");
	scanf("%d", &delData);
	Ptr = searchNode(&(*rootNode), delData);
	if (Ptr->left == NULL && Ptr->right == NULL)
	{
		if (Ptr == *rootNode)
			*rootNode = NULL;
		free(Ptr);
	}
	else
	{
		searchRightsubEndofleft(Ptr->right)->left = Ptr->left;
		
		free(Ptr);
	}
	return;
}