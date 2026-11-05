#pragma once
#include <iostream>
//zad 1
int size(const char* arr)
{
	int index = 0;
	while (arr[index]!='\0')
	{
		index++;
	}
	return index;
}
long findSeq(const char* arr, char S)
{
	int sizeArr = size(arr);
	long max = 0;
	long br = 1;
	for (int i = 1; i < sizeArr; i++)
	{
		if (arr[i - 1] == arr[i] && arr[i] == S)
		{
			br++;
		}
		else
		{
			if (max < br)
			{
				max = br;
			}
			br = 1;
		}
	}
	if (max < br)
	{
		max = br;
	}
	return max;
}
//zad3
int* findSets(const int* arr, size_t N)
{

}