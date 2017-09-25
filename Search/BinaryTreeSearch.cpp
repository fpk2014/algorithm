#include <iostream>
#include <malloc.h>

using namespace std;

struct node{
	int value;
	struct node *left;
	struct node *right;
};

typedef struct node tree;

void insert(tree **t, int value){
	node *tmp = NULL;	
	if((*t) == NULL){
		tmp = (node *) malloc(sizeof(node));
		tmp->left = tmp->right = NULL;
		tmp->value = value;
		*t = tmp;
		return;
	}
	
	if(value < (*t)->value){
		insert(&(*t)->left, value);
	}else if(value > (*t)->value){
		insert(&(*t)->right, value);
	}
}

void delTree(tree *t){
	if(t != NULL){
		delTree(t->left);
		delTree(t->right);
		free(t);
	}	
}


void printPreorder(tree *t){
	if(t != NULL){
		cout << t->value << " ";
		printPreorder(t->left);
		printPreorder(t->right);
	}
}

//中序
void printInorder(tree *t){
	if(t != NULL ){
		printInorder(t->left);
		cout << t->value << " ";
		printInorder(t->right);
	}
}


void printPostorder(tree *t){
	if(t != NULL){
		printPostorder(t->left);
		printPostorder(t->right);	
		cout << t->value << " ";
	}
}

tree *BinaryTreeSearch(tree *t, const int key){
	if( t != NULL ){
		if(key == t->value)
			return t;
		else if(key < t->value)
			return BinaryTreeSearch(t->left, key);
		else
			return BinaryTreeSearch(t->right, key);
	}
	return NULL;
}




int main(){
	const int length = 6;
	int my_array[length] = {5, 8, 2, 1, 4, 5};
	tree *t = NULL;
	for(int i=0; i<length; i++)
		insert(&t, my_array[i]);

	printPreorder(t); cout << endl;
	printInorder(t);  cout << endl;
	printPostorder(t);cout << endl;

	for(int i=0; i<length; i++){
		if(BinaryTreeSearch(t, my_array[i])->value != my_array[i])
			cout << i << " error" << endl;
	}

	delTree(t);
	return 0;
}
