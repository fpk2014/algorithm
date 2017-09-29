#include <iostream>

using namespace std;


void insert(int **t){
	int *tmp = NULL;
	*t = tmp;
	return;
}


void delNode(int **t){
	int **tmp;
	int  a=1; int *b=&a;
	tmp = &b;  //*tmp = b  错误
}


int main(){
	int *a;
	int **b;
	int c = 1;

	a = &c;
	insert(&a);
	delNode(&a);
	return 0;
}
