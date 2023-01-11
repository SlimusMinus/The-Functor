#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Funct
{
private:
	vector <int> vec;
	int size;
	int sum_ev = 0;
	int sum_od = 0;

public:

	void operator() (int size)
	{
		for (int i = 0; i < size; i++)
			vec.push_back(rand() % 25 + 5);

		for (auto it : vec)
		{
			cout << it << "  ";
			if (it % 2 == 0)
				sum_ev += it;
			else
				sum_od += it;
		}
		cout << endl;
		
	}

	void operator() ()
	{
		cout << "\n\nSum of all even numbers = " << sum_ev << endl;
		cout << "Sum of odd even numbers = " << sum_od << endl;
		if (sum_ev > sum_od)
			cout << "The sum of all even numbers is greater than the sum of odd numbers" << endl;
		else if (sum_ev < sum_od)
			cout << "The sum of all odd numbers is greater than the sum of even numbers" << endl;
		else
			cout << "Amounts are equal " << endl;
	}

};

int main()
{
	srand(time(NULL));
	int size;
	do
	{
	try
		{
			cout << "Enter size array: ";
			cin >> size;
			if (size == 0)
				throw exception("Size array must be an integer number");
			if (size < 0)
				throw exception("Size array must be a positive number");
		}
		catch (exception& str)
		{
			cout << str.what() << endl;
		}

	} while (size < 0);
		
	cout << "\n";
	Funct f;
	vector <int> vec;
	f(size);
	f();
}