#pragma once
#include <iostream>
//zad 1
const int SIZE = 10;
int size(const char* arr)
{
	int index = 0;
	while (arr[index]!='\0')
	{
		index++;
	}
	return index;
}
int fromCharToInt(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	return -1;
}
int* fromCharArrayToIntArray(const char* arr)
{
	int sizeArr = size(arr);
	int* intArr = new int[sizeArr];
	for (int i = 0; i < sizeArr; i++)
	{
		intArr[i] = fromCharToInt(arr[i]);
	}
	return intArr;
}
int analyzeArray(const char* arr)
{
	int checkArr[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
	int sizeArr = size(arr);
	int* intArr = fromCharArrayToIntArray(arr);
	for (int i = 0; i < sizeArr; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (intArr[i] == checkArr[j])
			{
				checkArr[j] = -1;
				break;
			}
		}
	}
	int max = -1;
	for (int i = 0; i < SIZE; i++)
	{
		if (max < checkArr[i])
		{
			max = checkArr[i];
		}
	}
	delete[] intArr;
	return max;
}
//zad 2
int findIndex(const int* arr, size_t L)
{
	int M = L;
	int br = 0;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (arr[j] >= M)
			{
				br++;
			}
		}
		if (br == M)
		{
			return M;
		}
		else if(br<M || br>M)
		{
			M--;
		}
		br = 0;
	}
	return M;
}
//zad3
const int TEN = 10;
long mod(long a)
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
long max(const long* arr,size_t size)
{
	long max = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int sizeTypeLong(long N)
{
	int index = 1;
	while (N / TEN != 0)
	{
		index++;
		N /= TEN;
	}
	return index;
}
char fromIntToChar(int a)
{
	if (a >= 0 && a <= 9)
	{
		return a + '0';
	}
	return -1;
}
char* fromLongToCharArray(long N)
{
	
	int size = sizeTypeLong(N);
	char* arr = new char[size + 1];
	for (int i = size-1; i >= 0; i--)
	{
		arr[i] = fromIntToChar(N % TEN);
		N /= TEN;
	}
	
	arr[size] = '\0';
	return arr;
}
char* concat(char* arr1,char* arr2)
{
	int size1 = size(arr1);
	int size2 = size(arr2);
	char* marge = new char[size1 + size2 + 2];
	int index = 0;
	for (int i = 0; i < size1; i++)
	{
		
		marge[index] = arr1[i];
		index++;
	}
	marge[index] = ',';
	index++;
	for (int i = 0; i < size2; i++)
	{
		marge[index] = arr2[i];
		index++;
	}
	marge[index] = '\0';
	return marge;
}
char* findDiff(const long* arr, size_t N)
{
	long min = max(arr,N), firstNumber = 0, secondNumber = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			long q = mod(arr[i] - arr[j]);
			if (min > q)
			{
				min = q;
				if (arr[i] > arr[j])
				{
					firstNumber = arr[i];
					secondNumber = arr[j];
					
				}
				else
				{
					firstNumber = arr[j];
					secondNumber = arr[i];
				}
			}
		}
	}
	char* firstNumberLikeCharArray = fromLongToCharArray(firstNumber);
	char* secondNumberLikeCharArray = fromLongToCharArray(secondNumber);

	char* result = concat(firstNumberLikeCharArray, secondNumberLikeCharArray);
	delete[] firstNumberLikeCharArray;
	delete[] secondNumberLikeCharArray;
	return result;
}