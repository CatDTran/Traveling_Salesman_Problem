/*Author: CAT TRAN
ASSIGNMENT: TRAVELING SALESMAN PROBLEM
UNIVERSITY OF NORTH TEXAS || CSCE 2110*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void swap(int *x, int *y);
void permute(int *a, int beginIndex, int endIndex);

int main()
{	
	int cityCount = 0, pathCount = 0;
	int lineCount = 0;
	string dummy;
	//count number of lines, cities, and paths
	while(getline(cin, dummy))
	{
		if(dummy[0] == 'c')
		{
			cityCount++;
		}
		else if(dummy[0] == 'a')
		{
			pathCount++;
			lineCount++;
		}
	}
	cout << "lineCount: " << lineCount << "|| cityCount: " << cityCount << "|| pathCount: " << pathCount << endl;

	//
	int *cities = (int *) malloc( cityCount * (sizeof(int)));

	for(int i = 0; i < cityCount; i++)
	{
		cities[i] = i + 1;
		printf("%d ", cities[i] );
	}
	cout << endl;
	permute(cities, 0, cityCount);
	return 0;
}

//==============SWAP===================//
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
//=============PERMUTATION=============//
void permute(int *a, int beginIndex, int endIndex)
{
	if(beginIndex == endIndex)
	{
		for(int i = 0 ;i <= endIndex; i++)
			printf("%d ", a[i]);
		cout << endl;
		return;
	}
	else
	{
		for(int i = beginIndex; i <= endIndex; i++)
		{
			swap((a + beginIndex), (a + i));
			permute(a, beginIndex + 1, endIndex);
			swap((a + beginIndex), (a + i));
		}
	}
}