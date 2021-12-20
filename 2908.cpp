#include<iostream>
#include<string>

using namespace std;

int main()
{
	string N1, N2;
	cin >> N1 >> N2;
	if (N1[2] > N2[2])
		cout << N1[2] << N1[1] << N1[0] << endl;
	else if(N1[2] < N2[2])
		cout << N2[2] << N2[1] << N2[0] << endl;
	else if (N1[2] == N2[2]) {
		if (N1[1] > N2[1])
			cout << N1[2] << N1[1] << N1[0] << endl;
		else if(N1[1]<N2[1])
			cout << N2[2] << N2[1] << N2[0] << endl;
		else if (N1[1] == N2[1]) {
			if(N1[0]>N2[0])
				cout << N1[2] << N1[1] << N1[0] << endl;
			else if(N1[0]<N2[0])
				cout << N2[2] << N2[1] << N2[0] << endl;
		}
			
	}
}