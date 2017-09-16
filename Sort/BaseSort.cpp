#include <iostream>

using std::cout;
using std::endl;

int main(){
		const int length = 5;
		int my_array[length] = {1,3,5,4,2};

		for(int i=0; i<length; i++){
			for(int j=i; j<length; j++){
				if(my_array[i] > my_array[j]){
					int tmp = my_array[i];
					my_array[i] = my_array[j];
					my_array[j] = tmp;
				}
			}
		}

		for(int i=0; i<length; i++){
			cout << my_array[i] << " ";
		}
		cout << "\n";

		return 0;
}
