#include <iostream>

using namespace std;

typedef struct btnode{
	int value;
	struct btnode *left;
	struct btnode *right;
}node, *btree;


void insert(btree t, int value){
	node *tmp = NULL;
	cout << value << endl;	
	tmp = (node *) malloc(sizeof(node));
	tmp->left = tmp->right = NULL;
	tmp->value = value;
	t = tmp;
}

int main(){
	btree t = NULL;

	cout << static_cast<const void *>(t) << endl;
	return 0;
}
