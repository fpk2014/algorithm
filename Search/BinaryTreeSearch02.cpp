#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;
};

class Btree: private Node{
private:
	Node *root=NULL;
	void _insert(Node **n, int key);
	void _display(Node *n);
public:
	void insert(int key);
	void display();

};

void Btree::_insert(Node **n, int key){
	if(*n == NULL){
		Node *tmp = new Node();
		tmp->data = key;
		*n = tmp;
	}
	if(key < (*n)->data)
		this->_insert(&(*n)->left, key);
	else if(key > (*n)->data)
		this->_insert(&(*n)->right, key);
}

void Btree::insert(int key){
	this->_insert(&(this->root), key);
}

void Btree::_display(Node *t){
	if(t != NULL ){
		this->_display(t->left);
		cout << t->data << " ";
		this->_display(t->right);
	}
}

void Btree::display(){
	this->_display(this->root);
	cout << endl;
}


int main(){
	const int length = 6;
	int my_array[length] = {5, 8, 2, 1, 4, 5};
	Btree a;
	for(int i=0; i<length; i++)
		a.insert(my_array[i]);
	a.display();

	return 0;
}
