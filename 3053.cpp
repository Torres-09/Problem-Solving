#include<iostream>
#include<cmath>


using namespace std;

# define PI 3.14159265358979323846
constexpr double my_pi = 3.141592653589793238462643383279502884L;

int main()
{
	
	
	double R;
	cin >> R;
	cout << fixed;
	cout.precision(6);

	cout << pow(R, 2) * PI << "\n";
	cout << pow(R*2, 2) / 2 << "\n";
	system("pause");
}