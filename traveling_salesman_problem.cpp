/*Author: CAT TRAN
ASSIGNMENT: TRAVELING SALESMAN PROBLEM
UNIVERSITY OF NORTH TEXAS || CSCE 2110*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stddef.h>
#define TABLE_SIZE 20
using namespace std;

void swap(int *x, int *y);
void permute(int *a, int beginIndex, int endIndex);

int permutationCount =0;
int costTable[TABLE_SIZE][TABLE_SIZE];//2d array table contains weight of each edge
int lowestCost;
int *lowestPath;

int main()
{	
	int cityCount = 0, pathCount = 0;
	int lineCount = 0;
	string dummy;//dummy string will store each line that is read in

	//initialize costTable to zero
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		for(int j = 0; j < TABLE_SIZE; j++)
		{
			costTable[i][j] = 0;
		}
	}
	//count number of lines, cities, and paths
	while(getline(cin, dummy))
	{
		if(dummy[0] == 'c')//if line contains city infomation
		{
			cityCount++;
		}
		else if(dummy[0] == 'a')//if line contains edge information
		{
			pathCount++;
			lineCount++;
			//storing each arc cost in table
			char *arcCost =  (char*) malloc(10 * sizeof(char));
			dummy.copy(arcCost, 10, 6);
			cout << dummy[2] << "->" << dummy[4] << " : " << (string) arcCost << endl;
			int i = atoi(&dummy[2]), j = atoi(&dummy[4]);
			costTable[i][j] = atoi(arcCost);
		}
	}
	cout << costTable[1][2] << endl;
	cout << "lineCount: " << lineCount << "|| cityCount: " << cityCount << "|| pathCount: " << pathCount << endl;
	// for(int i = 0; i < TABLE_SIZE; i++)
	// {
	// 	printf("%.5d ", i);
	// 	for(int j = 0; j < TABLE_SIZE; j++)
	// 	{
	// 		cout << j;
	// 		printf(" %.5d", costTable[i][j]);
	// 	}
	// 	cout << endl;
	// }
	// //
	int *cities = (int *) malloc( (cityCount + 1) * (sizeof(int)));

	cout << "Cities: ";
	for(int i = 0; i <= cityCount; i++)
	{
		cities[i +1] = i + 1;
		printf("%d ", cities[i] );
	}
	cout << endl;
	lowestPath = (int *) malloc((cityCount + 1) * sizeof(int));
	//permute(cities, 1, cityCount);
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
		for(int i = 1 ;i <= endIndex; i++)
		{
			printf("%d ", a[i]);			
		}
		permutationCount++;
		printf("Permutation counts: %d", permutationCount);
		cout << endl;
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

//============COST===================//