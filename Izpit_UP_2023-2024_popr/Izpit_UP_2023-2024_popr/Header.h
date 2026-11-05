#pragma once
#include <iostream>
//zad1
int size(const char* arr)
{
	int index = 0;
	while (arr[index] != '\0')
	{
		index++;
	}
	return index;
}
bool checkThisCharIsInArray(const char* arr, char ch)
{
	bool check = false;
	int sizeArr = size(arr);
	for (int i = 0; i < sizeArr; i++)
	{
		if (ch == arr[i])
		{
			check = true;
			break;
		}
	}
	return check;
}
bool analyzeArr(const char* arr)
{
	int sizeArr = size(arr);
	int index = 0;
	char* upperArr = new char[sizeArr + 1];
	for (int i = 0; i < sizeArr; i++)
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z')
		{
			upperArr[index] = arr[i];
			index++;
		}

	}
	upperArr[index] = '\0';
	int sizeUpperArr = index;
	bool check = true;
	for (int i = 0; i < sizeUpperArr; i++)
	{
		if (!checkThisCharIsInArray(arr, upperArr[i] + ('a' - 'A')))
		{
			delete[] upperArr;
			check = false;
			break;
		}
	}
	delete[] upperArr;
	return check;

}
//zad2
const int SIZEOFDATE = 10;
const int DAY = 4;
const int MONTH = 4;
const int YEAR = 5;
const int TEN = 10;
int Power(int a, int b)
{
	int pow = 1;
	for (int i = 0; i < b; i++)
	{
		pow *= a;
	}
	return pow;
}
int fromCharToInt(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	return -1;
}
int* fromCharArrayToIntArray(char* arr, size_t size)
{
	int* intArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		intArr[i] = fromCharToInt(arr[i]);
	}
	return intArr;
}
long fromIntArrayToLong(int* arr, size_t size)
{
	long N = 0;
	for (int i = 0; i < size; i++)
	{
		N += arr[i] * Power(TEN, size - 1 - i);
	}
	return N;
}
bool isAllNumbers(char* arr, size_t size)
{
	bool check = true;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < '0' || arr[i]>'9')
		{
			check = false;
			break;
		}
	}
	return check;
}
bool validDay(char* date, int& month, bool& isLeapYear)
{
	size_t size = DAY - 1;
	bool check = isAllNumbers(date, size - 1);
	if (month == -1)
	{
		return false;
	}
	if (date[0] == '0' && date[1] == '0')
	{
		return false;
	}
	if (check)
	{
		switch (month)
		{

		case 1:case 3:case 5:case 7:case 8: case 10:case 12:
		{
			if (date[0] >= '0' && date[0] <= '3')
			{
				if (date[0] == '3')
				{
					if (date[1] < '0' || date[1] > '1')
					{
						check = false;
					}
				}
			}
			else
			{
				check = false;
			}
			break;
		}
		case 4:case 6:case 9:case 11:
		{
			if (date[0] >= '0' && date[0] <= '3')
			{
				if (date[0] == '3')
				{
					if (date[1] != '0')
					{
						check = false;
					}
				}
			}
			else
			{
				check = false;
			}
			break;
		}
		case 2:
		{
			if (isLeapYear)
			{
				if (date[0] < '0' || date[0] > '2')
				{
					check = false;
				}
			}
			else
			{
				if (date[0] >= '0' && date[0] <= '2')
				{
					if (date[0] == '2')
					{
						if (date[1] < '0' || date[1]>'8')
						{
							check = false;
						}

					}

				}
				else
				{
					check = false;
				}
			}
			break;
		}
		default:
		{
			check = false;
		}
		}
		if (date[2] != '-')
		{

			check = false;
		}

	}
	return check;

}
bool validMonth(char* date, int& month)
{
	month = 0;
	size_t size = MONTH - 1;
	bool check = isAllNumbers(date, size - 1);
	if (date[0] == '0' && date[1] == '0')
	{
		month = -1;
		return false;
	}

	if (check)
	{
		if (date[0] >= '0' && date[0] <= '1')
		{
			month += fromCharToInt(date[0]) * TEN;
			if (date[0] == '0')
			{
				month += fromCharToInt(date[1]);
			}
			if (date[0] == '1')
			{
				if (date[1] >= '0' && date[1] <= '2')
				{
					month += fromCharToInt(date[1]);
				}
				else
				{
					month = -1;
					check = false;
				}

			}
		}
		else
		{
			month = -1;
			check = false;
		}
		if (date[2] != '-')
		{
			month = -1;
			check = false;
		}
	}
	else
	{
		month = -1;
	}
	return check;
}
bool validYear(char* date, bool& isLeapYear)
{
	size_t size = YEAR - 1;
	bool check = isAllNumbers(date, size);
	if (check)
	{
		int* yearArr = fromCharArrayToIntArray(date, size);
		long year = fromIntArrayToLong(yearArr, size);
		delete[] yearArr;
		if (year % 4 == 0 && year % 100 != 0)
		{
			isLeapYear = true;
		}
		else if (year % 400 == 0)
		{
			isLeapYear = true;
		}
		else
		{
			isLeapYear = false;
		}
	}
	else
	{
		isLeapYear = false;
	}
	return check;
}
bool validDate(const char* date)
{
	if (SIZEOFDATE != size(date))
	{
		return false;
	}

	char days[DAY];
	char month[MONTH];
	char years[YEAR];
	int index = 0;
	for (int i = 0; i < DAY - 1; i++)
	{
		days[i] = date[index];
		index++;
	}
	days[DAY - 1] = '\0';
	for (int i = 0; i < MONTH - 1; i++)
	{
		month[i] = date[index];
		index++;
	}
	month[MONTH - 1] = '\0';
	for (int i = 0; i < YEAR - 1; i++)
	{
		years[i] = date[index];
		index++;
	}
	years[YEAR - 1] = '\0';
	bool isLeapYear = false;
	int m = 0;
	bool isValidYear = validYear(years, isLeapYear);
	bool isvalidMonth = validMonth(month, m);
	bool isvalidDay = validDay(days, m, isLeapYear);
	return isValidYear && isvalidMonth && isvalidDay;

}
//zad3

int sizeTypeLong(long N)
{
	int index = 1;
	while (N / TEN != 0)
	{
		N /= TEN;
		index++;
	}
	return index;
}

int* fromLongToArray(long N)
{
	int size = sizeTypeLong(N);
	int* arr = new int[sizeTypeLong(N)];
	for (int i = size - 1; i >= 0; i--)
	{
		arr[i] = N % TEN;
		N /= TEN;
	}
	return arr;
}

int* takeOnlynNumbers(int* arr, int stzrtIndex, int n)
{
	int* newArr = new int[n];
	int index = 0;
	for (int i = stzrtIndex; i < n + stzrtIndex; i++)
	{
		newArr[index] = arr[i];
		index++;
	}
	return newArr;
}
int Find(long N, int n)
{
	if (N <= 0 || n >= 8 || n <= 0)
	{
		return -1;
	}
	int size = sizeTypeLong(N);
	int* arr = fromLongToArray(N);
	int* row = new int[n];
	long max = 0;
	for (int i = 0; i < size; i++)
	{
		if (i + n <= size)
		{
			delete[] row;
			row = takeOnlynNumbers(arr, i, n);
			long newN = fromIntArrayToLong(row, n);
			if (newN > max)
			{
				max = newN;
			}
		}

	}
	long newN = fromIntArrayToLong(row, n);
	if (newN > max)
	{
		max = newN;
	}
	delete[] row;
	delete[] arr;
	return max;
}