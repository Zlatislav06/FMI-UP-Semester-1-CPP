#include <iostream>
using namespace std;

//zad1
double myAbs(double x)
{
	if (x < 0)
	{
		return -x;
	}
	else
	{
		return x;
	}

}

double myMin(double a, double b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

double myMax(double a, double b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

double myPow(double a,int b)
{
	double pow = 1;
	if (b >= 1)
	{
		for (int i = 0; i < b; i++)
		{
			pow *= a;
		}
		
	}
	else if (b == 0)
	{
		pow = 1;
	}
	else
	{
		for (int i = 0; i < - b; i++)
		{
			pow *= a;
		}
		pow = 1 / pow;
	
	}
	return pow;
}

//zad2
int CountOfNumbers(int a)
{
	int br = 0;
	while (a % 10 != 0 || a / 10 != 0)
	{
		a = a / 10;
		br++;
	}
	return br;
}

//zad3
void GeometricProgretion(int a0,int q,int n)
{
	int pow = 1;
	cout<<"Thouse are the first " <<n<<" elements from this porgretion:\n" << a0 << ' ';
	for (int i = 1; i < n; i++)
	{
		pow *= q;
		cout << a0 * pow<<' ';
	}
}

//4
void Palindrom(long long n)
{
	if (n < 0)
	{
		cout << "Error!!!";
	}
	else
	{
		int br = 0;
		long long new_n = n,palindrom=0;

		while (new_n % 10 != 0 || new_n / 10 != 0)
		{
			new_n = new_n / 10;
			br++;
		}
		int* arr = new int[br]();
		new_n = n;
		for (int i = 0; i < br; i++)
		{
			palindrom+= n % 10;
			n = n / 10;
			palindrom *= 10;
		}							
		if (palindrom / 10 == new_n)
		{
			cout << "\nThis is palindrom";
		}
		else
		{
			cout << "\nThis isn't palindrom";
		}
	}

}
//5
long long Kontenatisia(int a,int b)
{
	int new_b = b,br=0;
	while (new_b/10!=0 || new_b%10!=0)
	{
		new_b /= 10;
		br++;
	}
	for (int i = 0; i < br; i++)
	{
		a *= 10;
	}
	long long n = a + b;
	return n;
}
//6
int SumOfNumbers(int a)
{
	int sum = 0;
	while (a / 10 != 0 || a % 10 != 0)
	{
		sum += a % 10;
		a /= 10;
	}
	while (sum > 10)
	{
		int sum1 = sum;
		sum = 0;
		while (sum1/10!=0 || sum1%10!=0)
		{
			sum += sum1 % 10;
			sum1 /= 10;
		}
		
	}
	return sum;
}
//7
void Proverka(int a,int b)
{
	double new_a = a * 1.0;
	double new_b = b * 1.0;
	if (a > b)
	{
		int division = a / b;
		double new_division = new_a / new_b;
		if (new_division > division)
		{
			
			cout << "The " << a << " isn't exactly divisible by " << b << '!';
		}
		else
		{
			cout << "The " << a << " is exactly divisible by " << b << '!';
		}
	}
	else if (a < b)
	{
		int division =  b/a;
		double new_division = new_b/new_a;
		if (new_division > division)
		{
			cout << "The " << b << " isn't exactly divisible by " << a << '!';
		}
		else
		{
			cout << "The " << b << " is exactly divisible by " << a << '!';
			
		}
	}
	else
	{
		cout << "The "<<a <<" is exactly divisible by " << b<<" and is equal that, the " << b<< " is exactly divisible by " << a<<'!';
	}
	

}
//8
void TestDate(int day,int mounth,int year)
{
	bool f = true;
	switch (mounth)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{
			if (day > 31 || day < 0)
			{
				f = false;
			}
			break;
		}
		case 4:case 6: case 11:
		{
			if (day > 30 || day < 0)
			{
				f = false;
			}
			break;
		}
		case 2:
		{
			if ((year % 10 != 0 && year % 4 == 0) || year % 40 == 0)
			{
				if (day > 29 || day < 0)
				{
					f = false;
				}
			}
			else
			{
				if (day > 28 || day < 0)
				{
					f = false;
				}
			}
			break;
		}
	default:
		break;
	}
	if (f)
	{
		cout << "Valid date!!!";
	}
	else
	{
		cout << "Invalid date!!!";
	}
}
//9
void PurfectNumbers(int a,int b)
{
	for (int i = a; i < b+1; i++)
	{
		int purfectnumber = i;
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sum += j;
			}

		}
		if (sum == purfectnumber)
		{
			cout << purfectnumber << " ";
		}
	}

}
int main()
{

	//cout<<CountOfNumbers(12346438);
	//GeometricProgretion(5,2,10);
	//Palindrom(1579456);
	//Palindrom(99999999);
	//cout << Kontenatisia(123,456);
	//cout << SumOfNumbers(9517);
	//Proverka(2,10);
	//TestDate(29,2,2400);
	//PurfectNumbers(1,100);
	return 0;
}