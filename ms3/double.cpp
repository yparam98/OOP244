#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
	double one = 3.14159;
	cout << one << endl;
	cout << setprecision(2) << one << " setprecision(2) " << endl;
	cout << setprecision(3) << one << " setprecision(3) " << endl;
	cout << setprecision(4) << one << " setprecision(4) " << endl;

	return 0;
}
