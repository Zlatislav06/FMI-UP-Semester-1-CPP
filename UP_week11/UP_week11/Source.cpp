#include <iostream>
using namespace std;
const int SIZE = 100;
//1
void CreateArray(int n)
{
	int* arr = new int[n]();
	delete arr;
}
//2
void CreteMatrix(int n)
{
	int m;
	cin >> m;
	int* arr = new int[n,m]();
	delete arr;
}
//3
int* Pamet(int* arr_1,int*arr_2,int size1,int size2,int& K)
{
	int max_size = 0;
	int new_size = 0;
	if (size1 > size2)
	{
		max_size = size1;
	}
	else
	{
		max_size = size2;
	}
	for (int i = 0; i < max_size; i++)
	{
		if (*(arr_1+i) % K == 0)
		{
			new_size++;
		}
		if (*(arr_2 + i) % K == 0)
		{
			new_size++;
		}
	}
	
	int br = 0;
	int* new_arr = new int[new_size]();
	for (int i = 0; i < max_size; i++)
	{

		if (*(arr_1 + i) % K == 0)
		{
			new_arr[br] = *(arr_1 + i);
			br++;
		}
		if (*(arr_2 + i) % K == 0)
		{

			new_arr[br] = *(arr_2 + i);
			br++;
		}
		if (br >= new_size)
		{
			break;
		}
	}
	K = new_size;
	return new_arr;
	
}
//4
int* Index(int* arr,int& size,int* index_arr,int size_index)
{
	if (size != size_index)
	{
		cout << "Error!!!";
		return nullptr;
	}
	int br = 0,size_new_arr=0;
	for (int i = 0; i < size; i++)
	{
		if (*(index_arr + i) == 1)
		{
			size_new_arr++;
		}
	}
	int* new_arr = new int[size_new_arr];
	for (int i = 0; i < size; i++)
	{
		if (*(index_arr + i) == 1)
		{
			new_arr[br] = *(arr + i);
			br++;
		}
	}
	size = br;
	return new_arr;
}
//6
char* SmallAndBigSimvols(char *small_arr,char* big_arr)
{
	int br_first_arr = 0, br_second_arr=0;
	int smallsimvols = 0, bigsimvols = 0;
	while (*(small_arr+ br_first_arr)!='\0')
	{
		if (*(small_arr + br_first_arr) >= 'a' && *(small_arr + br_first_arr) <= 'z')
		{
			smallsimvols++;
		}
		br_first_arr++;
	}
	while (*(big_arr + br_second_arr) != '\0')
	{
		if (*(big_arr + br_second_arr) >= 'A' && *(big_arr + br_second_arr) <= 'Z')
		{
			bigsimvols++;
		}
		br_second_arr++;
	}
	char* arr = new char[smallsimvols + bigsimvols+1]();
	int new_br = 0;
	for (int i = 0; i < br_first_arr; i++)
	{
		if (*(small_arr + i) >= 'a' && *(small_arr + i) <= 'z')
		{
			arr[new_br] = *(small_arr + i);
			new_br++;
		}
	}
	for (int i = 0; i < br_second_arr; i++)
	{
		if (*(big_arr + i) >= 'A' && *(big_arr + i) <= 'Z')
		{
			arr[new_br] = *(big_arr + i);
			new_br++;
		}
	}
	arr[new_br] = '\0';
	return arr;
}
//7
char* NoNumbers(char* text,char*pattern)
{

	int size_text = 0, size_pattern = 0;
	while (*(text + size_text) != '\0')
	{
		size_text++;
	}
	while (*(pattern + size_pattern) != '\0')
	{
		size_pattern++;
	}
	if (*(pattern + size_pattern - 1) == ' ')
	{
		*(pattern + size_pattern - 1) = '\0';
		size_pattern--;
	}
	char* arr = new char[SIZE];
	int size_arr = 0;
	for (int i = 0; i < size_text; i++)
	{
		
			
			if (*(text + i) >= '0' && *(text + i) <= '9')
			{
				if (arr[size_arr - 1] != *(pattern + size_pattern - 1))
				{
					for (int j = 0; j < size_pattern; j++)
					{
						arr[size_arr] = *(pattern + j);
						size_arr++;
					}
				}
				
			}
			else
			{
				arr[size_arr] = *(text + i);
				size_arr++;
			}
		
		
	}
	arr[size_arr] = '\0';
	return arr;
}

int main()
{
	/*int arr[] = {1,2,3,4,5,8};
	int arr_1[] = { 1,0,1,0,1,1 };
	int k = 6;
	int* pamet= Index(arr,  k, arr_1, 6);
	for (int i = 0; i < k; i++)
	{
		cout << *(pamet+i)<<" ";
	}
	delete pamet;*/

	char arr[] = "Start 32 kekfep fkefk fkee 12 kdwoo kfef k 2 234";
	char arr_1[] = "ENd ";
	char* new_arr = NoNumbers(arr, arr_1);
	for (int i = 0; new_arr[i]!='\0'; i++)
	{
		cout << *(new_arr + i);
	}
	delete new_arr;
	return 0;
}