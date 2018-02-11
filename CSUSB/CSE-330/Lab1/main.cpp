#include <iostream>
#include <stdlib.h>
using namespace std;
#include "functions.h"

int main(int argc, char* argv[]) {

	for ( int i = 0; i < argc; ++i ) {
		cout << argv[i] << endl;
	}

	if ( argc!=3 ) {
		std::cout<<"\033[0;31mInvalid Arguments. "
			  "Enter numbers only\033[0m\n";
		return 0;
	}
	double a = atof(argv[1]);
	double b = atof(argv[2]);
	if ( (a==0)||(b==0) )
		std::cout<<"\033[0;31mInvalid input. "
			  "Enter numbers only\033[0m\n";
	else {
		double result = product(a, b);
		print(result);	
	}
	return 0;
}