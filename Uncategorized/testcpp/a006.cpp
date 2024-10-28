#include <iostream>
#include <math.h>
using namespace std;
int main () {
	int a, b, c;
	cin >> a >> b >> c;
	if(b*b-4*a*c>=0) {
		int x1,x2;
		x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
		x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
		if(x1==x2) {

		}else {

		}
	}else {
		cout << "No real root\n";
	}
}
