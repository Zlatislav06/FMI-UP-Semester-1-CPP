#pragma once
#include <iostream>
//zad 1
const int TEN = 10;
int sizeTypeLong(long N)
{
	int index = 1;
	while (N/ TEN !=0)
	{
		index++;
		N /= TEN;
	}
	return index;
}
int* fromLongToIntArray(long N)
{
	int size = sizeTypeLong(N);
	int* arr = new int[size];
	for (int i = size-1; i>=0; i--)
	{
		arr[i] = N % TEN;
		N /= TEN;
	}
	return arr;
}
int Power(int a, int b)
{
	int pow = 1;
	for (int i = 0; i < b; i++)
	{
		pow *= a;
	}
	return pow;
}
long fromIntArrayToLong(int* arr,size_t size)
{
	long N = 0;
	for (int i = 0; i < size; i++)
	{
		N += arr[i] * Power(TEN, size - i - 1);
	}
	return N;
}
long processNum(long N)
{
	
	int size = sizeTypeLong(N);
	if (size < 5)
	{
		return -1;
	}
	
	int* arr = fromLongToIntArray(N);
	int br = 1, maxBr = 0;;
	long max = 0,number=arr[0];
	
	for (int i = 1; i < size; i++)
	{

		if (arr[i - 1] == arr[i] +1)
		{

			number *= TEN;
			number += arr[i];
			br++;
		}
		else
		{
			if (maxBr < br)
			{
				max = number;
				maxBr = br;
			}
			else if (maxBr == br)
			{
				if (max < number)
				{
					max = number;
					maxBr = br;
				}
			}
			
			number = arr[i];
			br = 1;
		}
	}
	if (maxBr < br)
	{
		max = number;
		maxBr = br;
	}
	else if (maxBr == br)
	{
		if (max < number)
		{
			max = number;
			maxBr = br;
		}
	}
	delete[] arr;
	return max;
}
//zad2
int* reverseArray(int* arr,size_t size)
{
	int* reverse = new int[size];
	int index = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		reverse[index] = arr[i];
		index++;
	}
	return reverse;
}
int* mergeArray(int* arr1, int* arr2, int m)
{
	int* merge = new int[m];
	int* reverseArr2 = reverseArray(arr2, m);
	
	for (int i = 0; i < m; i++)
	{
		merge[i] = arr1[i]+ reverseArr2[i];
		
	}
	delete[] reverseArr2;
	return merge;
}
//zad3
const double  epsilon = 1e-9;
struct Point
{
	double x;
	double y;
};
double mod(double a)
{
	if (a < 0)
	{
		return -a;
	}
	else
	{
		return a;
	}
}
int CheckQ(Point point)
{
	// нека, ако е на осите да връща също нула
	if (mod(point.y) - epsilon < 0 || mod(point.x) - epsilon < 0)
	{
		return 0;
	}
	if (point.x > 0)
	{
		if (point.y > 0)
		{
			return 1;
		}
		if (point.y < 0)
		{
			return 4;
		}
	}
	if (point.x < 0)
	{
		if (point.y > 0)
		{
			return 2;
		}
		if (point.y < 0)
		{
			return 3;
		}
	}
	return -1;
}