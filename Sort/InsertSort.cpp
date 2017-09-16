#include <iostream>

using std::cout;

int main(){
	const int length = 5;
	int my_array[length] = {1,5,4,3,7};
	
	for(int i=1; i<length; i++){
		int tmp = my_array[i];
		int j = i -1;
		while(j>=0 && my_array[j] > tmp){
			my_array[j+1] = my_array[j];
			j--;
		}
		my_array[j+1] = tmp;
	}


	for(int i=0; i<length; i++){
		cout << my_array[i] << " ";
	}
	cout << "\n";
	return 0;
}
