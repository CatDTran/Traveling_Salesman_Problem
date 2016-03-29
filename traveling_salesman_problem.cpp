/*Author: CAT TRAN
ASSIGNMENT: TRAVELING SALESMAN PROBLEM
UNIVERSITY OF NORTH TEXAS || CSCE 2110*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	
	//declare and open input and output files
	char inFileName[20];
	// scanf("%s",inFileName);
	// cout << inFileName << endl;
	// char *outFileName;
	// ifstream inFile;
	// ofstream outFile;
	//inFile.open(inFileName, ios::in);
	//outFile.open(outFile, ios::out);
	// if(!inFile.is_open())
	// {
	// 	cout << "No input file found..." << endl;
	// 	return 0;
	// }

	//At this state proper arguments and input file are entered
	int cityCount = 0, pathCount = 0;
	int lineCount = 0;
	string dummy;
	//count number of lines, cities, and paths
	while(getline(cin, dummy))
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
	while(getline(cin, lines[i]))
	{
		
	}
	return 0;
}
