#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int d, h, w;
	cin >> d >> h >> w;

	double result = pow(d, 2) / (pow(h, 2) + pow(w, 2));
	
	result = sqrt(result);
	
	cout << floor((result * h)) << " " << floor(result*w);
}