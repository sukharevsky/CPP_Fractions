//============================================================================
// Name        : MathWorks_Assignment.cpp
// Author      : Alex Sukharevsky
// Version     :
// Copyright   : LHASA LLC
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Fraction.h"

using namespace std;
using namespace Fraction_al;
int main(int argc, char* argv[]) {
	if (argc == 4) {
		puts("!!!Hello World!!!");
		Fraction fraction_1(argv[1]);
		Fraction fraction_2(argv[2]);
		string operation = string(argv[3]);
		if (operation == "Add")  // Addition
			fraction_1.Add(fraction_2).Display();
		else if (operation == "Subtract") // Subtraction
			fraction_1.Subtract(fraction_2).Display();
		else if (operation == "Multiply") // Multiplication
			fraction_1.Multiply(fraction_2).Display();
		else if (operation == "Divide") // Division
			fraction_1.Divide(fraction_2).Display();
		else if (operation == "IsEqual") // Equality
			printf("%d", fraction_1.IsEqual(fraction_2));
		else if (operation == "IsNotEqual") // Non-Equality
			printf("%d", fraction_1.IsNotEqual(fraction_2));
		else if (operation == "GreaterThan")	// Greater than
			printf("%d", fraction_1.GreaterThan(fraction_2));
		else if (operation == "LessThan") // Less than
			printf("%d", fraction_1.LessThan(fraction_2));
		else if (operation == "Display") { // Display
			fraction_1.Display();
			fraction_2.Display();
		}
		else
		    cerr << "Unknown Operation Requested";
	} else {
		cerr << "Usage: " << argv[0] << " FRACTION_1 FRACTION_2 OPERATION" << endl;
		return 1;
	}
	return EXIT_SUCCESS;
}
