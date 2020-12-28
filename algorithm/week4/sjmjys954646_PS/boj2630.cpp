#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int arr[128][128];
int N;
int totalWhite = 0;
int totalBlue = 0;
int row = 0;
int column = 0;

void Division(int N, int row, int column) 
{
	if(N==1)
	{
		if(arr[row][column] == 1)
		{
			totalBlue +=1;
		}
		else
		{
			totalWhite +=1;
		}
		return;
	}
	else
	{
		int sum = 0;
		
		for(int i = row;i<row+N;i++)
		{
			for(int j = column;j<column+N;j++)
			{
				sum += arr[i][j];
			}	
		}
		if(sum == N*N)
		{
			totalBlue +=1;
			return;
		}
		else if(sum == 0)
		{
			totalWhite +=1;
			return;
		}
		else
		{
			Division(N/2, row, column);
			Division(N/2, row + N/2, column);
			Division(N/2, row, column + N/2);
			Division(N/2, row + N/2, column + N/2);
		}
	}
}

int main(void)
{
	
	cin>>N;
	
	for(int i =0;i<N;i++)
	{
		for(int j =0;j<N;j++)
		{
			cin>>arr[i][j];
		}
	}
	Division(N, row, column);
	
	cout<<totalWhite<<"\n"<<totalBlue;
	
	return 0;
}