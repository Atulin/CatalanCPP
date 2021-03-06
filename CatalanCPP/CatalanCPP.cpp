// CatalanCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <stdlib.h>
#include <cstdio>
#include <chrono>
#include "InfInt.h"

using namespace std;
using namespace std::chrono;


// Calculate factorial
InfInt Factorial(InfInt number)
{
	if (number == 1)
		return 1;
	else
		return number * Factorial(number - 1);
}

// Calculate Catalan numbers
list<InfInt> Catalan(int n)
{
	InfInt CatalanN = 1;
	int i = 1;

	list<InfInt> result;

	while (n-- > 0)
	{
		CatalanN = Factorial(2 * i) / (Factorial(i + 1) * Factorial(i));
		result.push_back(CatalanN);
		i++;
	}

	return result;
}


// MAIN
int main()
{
	int iters;

	cout << "Number of iterations" << endl;
	cin >> iters;
	cout << endl;

	// Start timing
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	// Execute code
	list<InfInt> catalan = Catalan(iters);
	// Stop timing
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	int index = 1;
	for (InfInt i : catalan)
	{
		cout << index << ": " << i << endl;
		index++;
	}

	auto duration = duration_cast<milliseconds>(t2 - t1).count();

	cout << endl << "Calculating " << iters << " Catalan numbers took " << duration << " ms" << endl << endl;

	system("pause");

	return 0;
}


