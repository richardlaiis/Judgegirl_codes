#include <iostream>
using namespace std;
int main() {
	int arr[10];
	for(int i = 0; i < 10; i++) arr[i] = i*i;
	for(int i = -1; i < 11; i++) {
		cout << arr[i] << ' ';
	}
	cout << arr[10] << endl;
}
