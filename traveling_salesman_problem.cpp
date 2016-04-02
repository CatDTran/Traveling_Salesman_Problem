/*Author: CAT TRAN
ASSIGNMENT: TRAVELING SALESMAN PROBLEM
UNIVERSITY OF NORTH TEXAS || CSCE 2110*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stddef.h>
#include <sstream>

#define TABLE_SIZE 20
using namespace std;

int permutationCount =0;
int costTable[TABLE_SIZE][TABLE_SIZE];//2d array table contains weight of each edge
int lowestCost = 100000;
int *lowestPath;	
int cityCount = 0, pathCount = 0;
int lineCount = 0;

void swap(int *x, int *y);
void permute(int *a, int beginIndex, int endIndex);
int cost(int *a, int cityCount);
void printPath(int *a, int cityCount);

int main()
{
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
		string word1, word2, word3, word4;
		istringstream iss(dummy);
		iss >> word1;
		if(dummy[0] == 'c')//if line contains city infomation
		{
			cityCount++;
		}
		else if(dummy[0] == 'a')//if line contains edge information
		{

			iss >> word2;
			iss >> word3;
			iss >> word4;
			pathCount++;
			lineCount++;
			//storing each arc cost in table
			char *arcCost =  (char*) malloc(10 * sizeof(char));
			word4.copy(arcCost, 10, 0);

			// cout << word2 << "->" << word3 << " : " << (string) arcCost << endl;
			int i = atoi(&dummy[2]), j = atoi(&dummy[4]);
			costTable[i][j] = atoi(arcCost);
			costTable[j][i] = costTable[i][j];
		}
	}
	 // cout << costTable[1][2] << endl;
	 // cout << costTable[2][1] << endl;
	// cout << "lineCount: " << lineCount << "|| cityCount: " << cityCount << "|| pathCount: " << pathCount << endl;
	int *cities = (int *) malloc( (cityCount + 1) * (sizeof(int)));

	// cout << "Cities: ";
	for(int i = 0; i <= cityCount; i++)
	{
		cities[i +1] = i + 1;
		// printf("%d ", cities[i] );
	}
	// cout << endl;
	lowestPath = (int *) malloc((cityCount + 1) * sizeof(int));
	//lowestPath = cities;//initialize lowestPath
	lowestCost = cost(cities, cityCount);
	permute(cities, 1, cityCount);
	printPath(lowestPath, cityCount);	
	cout << " cost " << lowestCost << endl;
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
		if(cost(a, cityCount) <= lowestCost)
		{
			for(int i = 1; i <= cityCount;i++)
			{
				lowestPath[i] = a[i];
			}
			lowestCost = cost(a,cityCount);
			//printPath(lowestPath,cityCount);
		}
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
int cost(int *a, int cityCount)
{
	int totalCost = 0;
	for(int i = 1; i <= cityCount; i++)
	{
		totalCost = totalCost + costTable[a[i]][a[i+1]];
	}
	totalCost = totalCost + costTable[a[1]][a[cityCount]];
	return totalCost;
}

//==========PRINT PATH==============//
void printPath(int *a, int cityCount)
{
	cout << "The tour: ";
	for(int i = 1; i <= cityCount; i++)
	{
		cout << a[i] << " ";
	}
	cout << a[1];
}