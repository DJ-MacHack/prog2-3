/**
 * 
 * @file   ArrayTest.cpp
 * @author Folz
 * @date   10.05.2016
 */

#include "ArrayTools.h"



void starteTests() {
	const size_t SIZE = 10;
	cout << "int-Array testen" << endl;
	int itab[SIZE];
	testeArray(itab, SIZE);

	cout << "\ndouble-Array testen" << endl;
	double dtab[SIZE];
	testeArray(dtab, SIZE);
}


int main() {
	starteTests();
}
