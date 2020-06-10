#include "Chapter6.h"

class TreeNode {
	int _object_level = 0;
	char _object_symbol = (rand() % 2) ? 'a' + (rand() % 26) : 'A' + (rand() % 26); // Random letter

public:
	TreeNode *parent_node = NULL;
	TreeNode *child_one = NULL;
	TreeNode *child_two = NULL;

	TreeNode() { }

	TreeNode(TreeNode *parent_object) {
		parent_node = parent_object;
		_object_level = parent_node->_object_level + 1;
	}

	int getNumber() {
		return _object_level;
	}

	char getSymbol() {
		return _object_symbol;
	}

	void setParent(TreeNode *parent_object) { // In case the object was created by the empty constructor
		parent_node = parent_object;
		_object_level = parent_node->_object_level + 1;
	}

	void showTreeNodes() { // Show each of the nodes
		cout << string(_object_level, '\t');
		printf("This is node on level %d and letter %c\n", _object_level, _object_symbol);

		if (child_one)
			child_one->showTreeNodes();

		if (child_two)
			child_two->showTreeNodes();
	}
};

void deleteTree(TreeNode *tn) { // Delete each node in the tree and give feedback in the console
	cout << string(tn->getNumber(), '\t');
	printf("Deleted node on level %d with letter %c\n", tn->getNumber(), tn->getSymbol());

	if (tn->child_one)
		deleteTree(tn->child_one);

	if (tn->child_two)
		deleteTree(tn->child_two);

	delete tn;
}

void chapter6Task4() {
	printf("TASK 4: Program which creates tree of objects. Each tree node has 2 subnodes\n");
	srand((unsigned int)time(0)); // Use current time as seed for random generator avoiding data loss warning

	int obj_lvl;
	printf("Enter tree level (for each parent node, 2 subnodes will be added): ");
	cin >> obj_lvl;

	if (obj_lvl < 0)
		printf("Invalid input!\n");
	else {
		TreeNode *tn = new TreeNode;
		TreeNode *current_tn = tn;

		int current_level = 0; // Counter for the elements on every level

		for (int i = 0; i < obj_lvl; i++)
		{
			TreeNode *first_node_in_level = current_tn;

			for (int k = 0; k < pow(2, current_level); k++)
			{
				current_tn->child_one = new TreeNode(current_tn);
				current_tn->child_two = new TreeNode(current_tn);

				if (k == ((int)pow(2, current_level) - 1))
					break;

				if (i != 0 && current_tn == current_tn->parent_node->child_one)
					current_tn = current_tn->parent_node->child_two;
				else if (i != 0 && current_tn == current_tn->parent_node->child_two)
					current_tn = current_tn->parent_node->parent_node->child_one->child_one;
			}

			if (i != 0)
				current_tn = first_node_in_level->child_one;
			else
				current_tn = current_tn->child_one;

			current_level++;
		}

		tn->showTreeNodes();
		printf("\n");
		deleteTree(tn);
	}

	printTaskEndLine(); // Used from Main
}