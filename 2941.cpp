#include<iostream>
#include<string>

using namespace std;

int main()
{
	string Sentence;
	getline(cin, Sentence);

	while (Sentence.find("dz=") != string::npos)
	{
		Sentence.replace(Sentence.find("dz="),  3, "d00");
	}
	while (Sentence.find("c=")!=string::npos)
	{
		Sentence.replace(Sentence.find("c="), 2, "c0");
	}
	while (Sentence.find("s=") != string::npos)
	{
		Sentence.replace(Sentence.find("s="), 2, "s0");
	}
	while (Sentence.find("z=") != string::npos)
	{
		Sentence.replace(Sentence.find("z="), 2, "z0");
	}
	while (Sentence.find("c-") != string::npos)
	{
		Sentence.replace(Sentence.find("c-"), 2, "c0");
	}
	while (Sentence.find("d-") != string::npos)
	{
		Sentence.replace(Sentence.find("d-"), 2, "d0");
	}
	while (Sentence.find("lj") != string::npos)
	{
		Sentence.replace(Sentence.find("lj"), 2, "l0");
	}
	while (Sentence.find("nj") != string::npos)
	{
		Sentence.replace(Sentence.find("nj"), 2, "n0");
	}

	int zerocounter = 0;
	for (int i = 0; i < Sentence.size(); i++)
	{
		if (Sentence[i] == '0')
			zerocounter++;
	}
	cout << Sentence.size() - zerocounter << endl;
}