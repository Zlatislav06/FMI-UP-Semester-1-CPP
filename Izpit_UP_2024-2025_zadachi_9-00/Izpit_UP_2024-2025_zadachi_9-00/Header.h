#pragma once
#include <iostream>
//zad 1
int max(const int* arr, size_t size)
{
	int maxArr = LONG_MIN;
	for (int i = 0; i < size; i++)
	{
		if (maxArr < arr[i])
		{
			maxArr = arr[i];
		}
	}
	return maxArr;
}
int min(const int* arr, size_t size)
{
	int minArr = max(arr,size);
	for (int i = 0; i < size; i++)
	{
		if (minArr > arr[i])
		{
			minArr = arr[i];
		}
	}
	return minArr;
}
int sum(const int* arr, size_t size)
{
	int sum = 0;
	
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int findMaxMin(const int* arr, size_t size, int& minVal, int& maxVal)
{
	minVal = min(arr, size);
	maxVal = max(arr, size);
	int sumArr = sum(arr, size);
	int averige = (double)sumArr / (double)size;
	if (sumArr % size >= size / 2)
	{
		averige++;
	}
	return averige;
}
//zad2
int strLen(const char* arr)
{
	int index = 0;
	while (arr[index]!='\0')
	{
		index++;
	}
	return index;
}
char* removedTwoElemenntsFromStr(const char* arr,int index1,int index2)
{
	int size = strLen(arr);
	char* newArr = new char[(size-2)+1];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != index1 && i != index2)
		{
			newArr[index] = arr[i];
			index++;
		}
	}
	newArr[index] = '\0';
	return newArr;
}
char* reverseStr(char* arr)
{
	int size = strLen(arr);
	char* reverseArr = new char[size + 1];
	int index = 0;
	for (int i = size-1; i>=0; i--)
	{
		reverseArr[index] = arr[i];
		index++;
	}
	reverseArr[index] = '\0';
	return reverseArr;
}
bool IsPalindrom(char* arr)
{
	int size = strLen(arr);
	char* reverseArr = reverseStr(arr);
	bool check = true;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != reverseArr[i])
		{
			check = false;
			break;

		}
	}
	delete[] reverseArr;
	return check;
}
bool checkStr(const char* arr)
{
	int size = strLen(arr);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i != j)
			{
				char* newArr = removedTwoElemenntsFromStr(arr, i, j);
				if (IsPalindrom(newArr))
				{
					delete[] newArr;
					return true;
				}
				delete[] newArr;
			}
			
		}
	}
	return false;
}
//zad3
const int MINK = 2;
const int MAXK = 36;
const int TEN = 10;
int fromCharToInt(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else if(ch>='A' && ch<='Z')
	{
		return (ch - 'A') + TEN;
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		return (ch - 'a') + TEN;
	}
	else
	{
		return -1;
	}
}
int* fromCharArrayToIntArray(const char* arr)
{
	int size = strLen(arr);
	int* intArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		intArr[i] = fromCharToInt(arr[i]);
	}
	return intArr;
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
int convert(const char* arr, int k)
{
	if (k < MINK || k>MAXK)
	{
		return -1;
	}
	int size = strLen(arr);
	int* intArr = fromCharArrayToIntArray(arr);
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (intArr[i] >= k)
		{
			return -1;
		}
		result += intArr[i] * Power(k, size - i - 1);
	}
	delete[] intArr;
	return result;
}