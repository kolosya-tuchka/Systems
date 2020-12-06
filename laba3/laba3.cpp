#include <iostream>
#include <string>
#include <vector>

unsigned long int Fibbonachi(int count)
{
	unsigned long int cur{ 1 }, prev{ 0 }, next;

	for (int i{ 2 }; i < count; ++i)
	{
		next = cur + prev;
		prev = cur;
		cur = next;
	}
	return cur;
}

unsigned long int RFibbonachi(int count, int first, int second)
{
	if (count > 2)
	{
		RFibbonachi(count - 1, second, first + second);
	}
	else return first + second;
}

int ToInt(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 10;
	}
	else if (c >= 'a' && c <= 'z')
	{
		return c - 'a' + 10;
	}
}

std::string ToString(int i, int sys)
{
	using namespace std;
	string str;
	while (i > 0)
	{
		int j{0};
		char c;
		j = i % sys;
		if (j < 10)
		{
			c = '0' + j;
		}
		else
		{
			c = 'A' + j - 10;
		}
		str.insert(str.begin(), c);
		i /= sys;
	}
	return str;
}

int Power(int num, int pow)
{
	int i = num;
	if (pow == 0)
	{
		return 1;
	}
	else if (pow < 0)
	{
		for (int j{ 0 }; j < pow - 1; ++j)
		{
			num /= i;
		}
	}
	else
	{
		for (int j{ 0 }; j < pow - 1; ++j)
		{
			num *= i;
		}
	}
	return num;
}

int trans(int sys, int index, std::string num)
{
	int result{ 0 };
	using namespace std;
	for (int i{ 0 }; i < num.size(); ++i)
	{
		result += Power(sys, i) * ToInt(num[num.size() - 1 - i]);
	}
	return result;
}


bool Check(int sys, std::string num)
{
	using namespace std;
	for (int i{0}; i < num.size(); ++i)
	{
		if (ToInt(num[i]) >= sys)
		{
			return false;
		}
	}
	return true;
}
//std::string mainFun(int sys, std::string num)
//{
//
//}

int main()
{
	int sys1, sys2;
	using namespace std;
	string num;
	cout << "Enter systems" << endl;
	do
	{
		cin >> sys1 >> sys2;
	} while (sys1 < 2 || sys2 < 2 || sys1 > 36 || sys2 > 36);
	do
	{
		cin >> num;
	} while (!Check(sys1, num));
	cout << trans(sys1, num.size() - 1, num) << endl;
	cout << ToString(trans(sys1, num.size() - 1, num), sys2);
}
