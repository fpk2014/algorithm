#include <iostream>

using namespace std;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

typedef struct btnode{
	int depth;
	int data;
	struct btnode *parent;
	struct btnode *left;
	struct btnode *right;
}node;

typedef node* btree;

void AVLTreeSearch(int *my_array, const int length, int key){

}

bool insert(btree *t, int key, node *parent){
	
	if((*t) == NULL){
		node *tmp = new node();
		tmp->data = key;
		tmp->depth = 1;
		tmp->parent = parent;
		*t = tmp;
		return true;

	}

	node *tmp2;
	if(key < (*t)->data){
		tmp2 = *t;
		//至少有一个为空
		if(insert(&(*t)->left, key, tmp2)==true && ((*t)->left==NULL || (*t)->right==NULL)) 
			(*t)->depth++;
		//与父节点深度相同
		if((*t)->left->depth==(*t)->depth)
			(*t)->depth++;
	}else if(key > (*t)->data){
		tmp2 = *t;
		if(insert(&(*t)->right, key, tmp2)==true && ((*t)->left==NULL || (*t)->right==NULL))
			(*t)->depth++;
		if((*t)->right->depth==(*t)->depth)
			(*t)->depth++;
	}
}


void printPreorder(btree t, int count){
	int tmp = count;
	if(t != NULL){
		for(int i=0; i<count; i++)
			cout << "    ";
		cout << t->depth << endl;
		printPreorder(t->left, ++count);
		printPreorder(t->right, ++tmp);
	}
}



int main(){
	const int length = 3;
	int my_array[length] = {1, 5, 7};

	btree *t = new btree();
	insert(t, 3, *t);
	insert(t, 2, *t);
	insert(t, 1, *t);
	insert(t, 7, *t);
	insert(t, 8, *t);
	insert(t, 5, *t);
	printPreorder(*t, 0);
	cout << endl << (*t)->depth  << (*t)->left->depth << endl;
	return 0; 
}
