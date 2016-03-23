/*Author: CAT TRAN
ASSIGNMENT: TRAVELING SALESMAN PROBLEM
UNIVERSITY OF NORTH TEXAS || CSCE 2110*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char ** argv)
{
	if(argc < 3)
	{
		cout << "Too few arguments..." << endl;
		return 0;
	}
	else if(argc > 3)
	{
		cout << "Too many arguments..." << endl;
		return 0;
	}

	//declare and open input and output files
	ifstream inFile;
	ofstream outFile;
	inFile.open(argv[1], ios::in);
	outFile.open(argv[2], ios::out);
	if(!inFile.is_open())
	{
		cout << "No input file found..." << endl;
		return 0;
	}

	//At this state proper arguments and input file are entered
	int cityCount = 0, pathCount = 0;
	int lineCount = 0;
	string dummy;
	//count number of lines, cities, and paths
	while(getline(inFile, dummy))
	{
		if(dummy[0] == 'c')
			cityCount++;
		else if(dummy[0] == 'a')
			pathCount++;
		lineCount++;
		cout << lineCount << "|| cityCount: " << cityCount << "|| pathCount: " << pathCount << endl;
	}
	//a string array to store lines
	string lines[lineCount];
	int i = 0;
	while(getline(inFile, lines[i]))
	{
		
	}
	return 0;
}
