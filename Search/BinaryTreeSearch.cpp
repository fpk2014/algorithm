#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct btnode{
	int value;
	struct btnode *left;
	struct btnode *right;
}node, *btree;

void insert(btree *t, int value){
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

void delTree(btree t){
	if(t != NULL){
		delTree(t->left);
		delTree(t->right);
		free(t);
	}	
}

void printPreorder(btree t){
	if(t != NULL){
		cout << t->value << " ";
		printPreorder(t->left);
		printPreorder(t->right);
	}
}

//中序
void printInorder(btree t){
	if(t != NULL ){
		printInorder(t->left);
		cout << t->value << " ";
		printInorder(t->right);
	}
}


void printPostorder(btree t){
	if(t != NULL){
		printPostorder(t->left);
		printPostorder(t->right);	
		cout << t->value << " ";
	}
}

btree BinaryTreeSearch(btree t, const int key){
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

btree *parent(btree *t, const int key, btree *par){
	btree *tmp;
	if( *t != NULL ){
		if(key == ((*t)->value))
			return par;
		else if(key < ((*t)->value)){
			tmp = t;
			return parent(&(*t)->left, key, tmp);
		}
		else{
			tmp = t;
			return parent(&(*t)->right, key, tmp);
		}
	}
	return NULL;
}

void delNode(btree *t, int key){
	btree *par = parent(t, key, t);
	if(par==NULL){
		cout << "not found" << endl;
		return;
	}
	btree *deleteNode;
	if((*par)->value == key){
		deleteNode = par;
	}
	if((*par)->left != NULL){
		if((*par)->left->value == key)
			deleteNode = &(*par)->left;  //*deleteNode = (*par)->left; 发生段错误?
	}
	if((*par)->right != NULL){
		if((*par)->right->value == key)
			deleteNode = &(*par)->right;
	}

	if((*deleteNode)->left==NULL && (*deleteNode)->right==NULL){
		*deleteNode = NULL;
	}else if((*deleteNode)->left!=NULL && (*deleteNode)->right==NULL){
		*deleteNode = (*deleteNode)->left;
	}else if((*deleteNode)->left==NULL && (*deleteNode)->right!=NULL){
		*deleteNode = (*deleteNode)->right;
	}else{  //有两个节点
		btree *tmp;
		tmp = &(*deleteNode)->right;
		while((*tmp) != NULL){
			if((*tmp)->left == NULL)
				break;
			tmp = &(*tmp)->left;
		}
		(*deleteNode)->value = (*tmp)->value;
		*tmp = NULL;
	}
}

int main(){
	const int length = 7;
	int my_array[length] = {5, 8, 2, 1, 4, 5, 3};
	btree t = NULL;
	for(int i=0; i<length; i++)
		insert(&t, my_array[i]);

	printPreorder(t); cout << endl;
	printInorder(t);  cout << endl;
	printPostorder(t);cout << endl;

	for(int i=0; i<length; i++){
		if(BinaryTreeSearch(t, my_array[i])->value != my_array[i])
			cout << i << " error" << endl;
	}
	delNode(&t, 2);
	delNode(&t, 5);
	printInorder(t);  cout << endl;
	delTree(t);
	return 0;
}
