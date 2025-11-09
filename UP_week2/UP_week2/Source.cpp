#include <iostream>
using namespace std;

int main()
{
	//1

	/*int a, b, c, max;

	cin >> a >> b >> c;
	if (a > b && a>c)
	{
		max = a;
	}
	else if(b>a && b>c)
	{
		max = b;
	}
	else
	{
		max = c;
	}
	cout << max;
	*/

	//2

	/*char a;
	cin >> a;
	cout << (a > 'a' && a < 'z');
	*/

	//3

	/*char a;
	cin >> a;
	if (a >= 'a' && a <= 'z')
	{
		cout << (char)(a-32);

	}
	else if (a >= 'A' && a <= 'Z')
	{
		cout << (char)(a+32);

	}
	else
	{
		cout <<"Error!";

	}*/

	//4

	/*int x1, y1, x2, y2, x, y;
	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
	if (x > x1 && x <x2 && y > y1 && y < y2)
	{
		cout << "Inside";
	}
	else if(x==x1 || y == y1 || x==x2 || y==y2)
	{
		cout << "On the border";
	}
	else
	{
		cout << "Outside";
	}*/

	//5

	/*int r, x, y;
	cin >> r >> x >> y;
	if (sqrt(pow((0 - x), 2) + pow((0 - y), 2)) < r)
	{
		cout << "Inside";
	}
	else if (sqrt(pow((0 - x), 2) + pow((0 - y), 2)) == r)
	{
		cout << "On the border";
	}
	else
	{
		cout << "Outside";
	}*/

	//6

	/*int a;
	cin >> a;
	if ((a % 4 == 0 && a % 100 != 0) || a%400==0)
	{
		cout << "Leap";
	}
	else
	{
		cout << "Not Leap";
	}*/

	//7
	/*int a;
	cin >> a;
	if (a >= 35)
	{
		cout << "Very hot!!!";
	}
	else if (a >= 25 && a < 35)
	{
		cout << "Hot!";
	}
	else if (a >= 15 && a < 25)
	{
		cout << "Hot.";
	}
	else if (a >= 5 && a < 15)
	{
		cout << "Normal.";
	}
	else if(a<5)
	{
		cout << "Cold!";
	}
	else
	{
		cout << "Invalid";
	}*/

	//8

	/*
	int a;
	cin >> a;

	int q = a % 7;
	switch (q)
	{
		case 0:
		{
			cout << "Monday";
			break;
		}
		case 1:
		{
			cout << "Teusday";
			break;
		}
		case 2:
		{
			cout << "Wensday";
			break;
		}
		case 3:
		{
			cout << "Thersday";
				break;
		}
		case 4:
		{
			cout << "Friday";
			break;
		}
		case 5:
		{
			cout << "Saterday";
			break;
		}
		case 6:
		{
			cout << "Sunday";
			break;
		}
	}*/

	//9 

	/*cout << "Enter one of these operations:\n(1 +\n(2 -\n(3 *\n(4 /\n";
	char a;
	double number_1, number_2,sum=0;
	cin >> a;
	cout << "Enter two numbers:";
	cin >> number_1 >> number_2;
	switch (a)
	{
		case '+':
		{
			sum = number_1 + number_2;
			break;
		}
		case '-':
		{
			sum = number_1 - number_2;
			break;
		}
		case '*':
		{
			sum = number_1 * number_2;
			break;//slavi
		}
		case '/':
		{
			sum = number_1 / number_2;
			break;
		}
	}
	switch (a)
	{
		case '1':
		{
			sum = number_1 + number_2;
			break;
		}
		case '2':
		{
			sum = number_1 - number_2;
			break;
		}
		case '3':
		{
			sum = number_1 * number_2;
			break;//slavi
		}
		case '4':
		{
			sum = number_1 / number_2;
			break;
		}
	}
	cout << sum;*/

	return 0;
}