#include <iostream>
#include <iomanip>
using namespace std;

void Palindrom(int a) 
{
	int palindrom=0;
	int new_a = a;
	for (int i = 0; i < new_a; i++)
	{
		if (a / 10 == 0 && a % 10 == 0)
		{
			break;
		}
		else
		{
			
			palindrom+= a % 10;
			a = a / 10;
			palindrom *= 10;
		}
	}
	
	if (palindrom / 10 == new_a)
	{
		cout <<"true";
	}
	else
	{
		cout << "false";
	}
}
void CountOfRepeat(long long a)
{
	int br, repeat_number,max=0;
	long long new_a=a;
	for (int i = 0; i < a; i++)
	{
		if (a % 10 == 0 && a / 10 == 0)
		{
			break;
		}
		int number = a % 10;
		a = a / 10;
		int br = 0;
		for (int j = 0; j < a; j++)
		{
			if (new_a % 10 == 0 && new_a / 10 == 0)
			{
				break;
			}
			if (number == new_a % 10)
			{
				br++;
				new_a = new_a / 10;
			}
		}
		if (br > max)
		{
			max = br;
			repeat_number = number;
		}
		new_a = a;
	}
	cout << repeat_number<<' ' << max <<' ' << "times";
}
int main()
{
	//1

	/*int n,sum=1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		sum *= (n-i);
	}
	cout << sum;
	*/

	//2

	/*int br = 0, c,sum=0;
	for (int i = 0; i < 3; i++)
	{
		i--;
		cin >> c;
		if (c % 7 == 0)
		{
			sum += c;
			br++;
		}

		if (br == 3)
		{
			break;
		}
	}
	cout << sum;*/

	//3

	/*int a,b;
	cin >> a;
	for (int i = 0; i < 3; i++)
	{
		i--;
		b = a % 10;
		a = a / 10;
		cout << b;
		if (a == 0)
		{
			break;
		}
	}*/

	//4
	/*int x, y, n;
	cin >> x>> y;
	if (x > y)
	{
		n = x;
	}
	else
	{
		n = y;
	}
	for (int i = n; i >=1; i--)
	{
		if (x % i == 0 && y % i == 0)
		{
			cout << i<<" ";
		}
	}*/

	//5

	/*
	int n,max=0,min=LONG_MAX;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (max < x)
		{
			max = x;
		}
		if (min > x)
		{
			min = x;
		}
	}
	cout << "\nMax:" << max << "\nMin:" << min;
	*/

	//6
	/*int n, a = 1, b = 1, sum = 0;
	cin >> n;
	if (n % 2 == 1)
	{
		n++;
	}
	for (int i = 0; i < n/2; i++)
	{
		cout << a<<' ';
		if (n / 2 - i != 1)
		{
			cout << b << ' ';
		}
		
		sum += a + b;
		a = sum;
		b = a + b;
		sum = 0;
	}
	*/

	//7

/*
    int n;
	cin >> n;
	bool f = false;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error!!!";
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i != 0)
		{
			f = true;
		}
		if (n % i == 0)
		{
			f = false;
			break;
		}
	}
	if (f || n==1)
	{
		cout << "This number is prime number!";
	}
	else
	{
		cout << "This number isn't prime number!";
	}
	*/

	//8 - (Програмата дава грешка на число с над 10 цифри)

	/*int n,br=0;
	cin >> n;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error!!!";
		return 0;
	}
	int t = n;
	for (int i = 0; i < t; i++)
	{
		if (n % 10 != 0 || n / 10 != 0)
		{
			n = n / 10;
			br++;

		}
		else
		{
			break;
		}
	}
	cout <<"\nCount: " << br;*/

	//9

	/*int n, m;
	cout << "m=";
	cin >> m;
	cout << "n=";
	cin >> n;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error!!!";
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		cout << '|';
		if ((i + 1)%2 != 0)
		{

			for (int j = 0; j < n; j++)
			{
				cout << '-';
			}
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				cout << '*';
			}
		}
		cout << '|'<<endl;
	}*/
	
	//10 -(Програмата не е направена със setw())

	/*
	int n,begin=2;
	cout << "n=";
	cin >> n;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error!!!";
		return 0;
	}
	for (int i = begin; i < n+ begin; i++)
	{
		
		for (int j = 1; j < i; j++)
		{
			cout << j;
		}
		
		for (int j = i-2; j >= 1; j--)
		{
			cout << j;
		}
		cout << endl;
	}
	*/

	//11

	/*
	int n;
	cin >> n;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error!!!";
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << setw(2) << '$';
		}
		cout<<'\n';
	}*/

	//12
/*
	int n, number_seurch,br=0;
	cin >> n >> number_seurch;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Error!!!\n";
		return 0;
	}
	while (n%10!=0 || n/10!=0)
	{
		if (n % 10 == number_seurch)
		{
			br++;
		}
		n = n / 10;
	}
	cout <<"Count:" << br;*/

	//13
/*
	int number;
	cin >> number;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error!!!";
		return 0;
	}
	int new_number = number, br=1;
	if (number < 0)
	{
		cout << '-' << ' ';
		number = -number;
	}

	while (new_number / 10 != 0 && new_number % 10 != 0)
	{
		new_number=new_number / 10;
		br++;
	}
	const int br1 = br;
	int* arr = new int[br1]();

	for (int i = 0; i <br1; i++)
	{
		if (number % 10 == 0)
		{
			if (number == 0)
			{
				cout << number;
				return 0;
			}
			else
			{
				number = number / 10;
			}
		}
		else
		{
			arr[i] = (int)(number % 10);
			number = number / 10;
		}
		
	}

	for (int i = br1 - 1; i>=0; i--)
	{
		cout << arr[i]<<' ';
	}
	*/

	//14

	/*int n;
	cin >> n;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Error!!!";
		return 0;
	}
	Palindrom(n);*/

	//15
	long long n;
	cin >> n;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Error!";
	}
	CountOfRepeat(n);


	return 0;
}