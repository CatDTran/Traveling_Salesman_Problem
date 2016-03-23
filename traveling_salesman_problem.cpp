/*Author: CAT TRAN
ASSIGNMENT: TRAVELING SALESMAN PROBLEM
UNIVERSITY OF NORTH TEXAS || CSCE 2110*/

#include <stio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char ** argv)
{
	if(argc < 3)
	{
		cout << "Too many arguments...";
		return 0;
	}
	else if(argc > 3)
	{
		cout << "Too few arguments...";
		return 0;
	}

	//declare and open input and output files
	ifstream inFile;
	ofstream outFile;
	inFile.open(argv[1]);
	outFile.open(argv[2]);

	return 0;
}