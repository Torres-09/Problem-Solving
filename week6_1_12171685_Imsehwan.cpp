#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;
int n, m, timeanswer;

struct customerinfo {
	int usetime, cost;
};

struct counterinfo {
	int endtime, number;

};

struct cmp
{
	bool operator()(counterinfo n1, counterinfo n2)
	{
		if (n1.endtime == n2.endtime)
			return n1.number > n2.number;
		return n1.endtime > n2.endtime;
	}
};

int main()
{
	cin >> n >> m;
	customerinfo* customer = new customerinfo[m];
	int *costanswer = new int[n];
	priority_queue<counterinfo, vector<counterinfo>, cmp> counterpq;
	for (int i = 0; i < n; i++)
	{
		costanswer[i] = 0;
	}
	timeanswer = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> customer[i].usetime >> customer[i].cost;
	}

	for (int i = 0; i < n; i++)
	{
		counterpq.push({ customer[i].usetime, i });
		costanswer[i] += customer[i].cost;
		timeanswer = max(timeanswer, customer[i].usetime);
	}

	for (int i = n; i < m; i++)
	{
		counterinfo countertemp = counterpq.top();
		counterpq.pop();
		countertemp.endtime += customer[i].usetime;
		costanswer[countertemp.number] += customer[i].cost;
		timeanswer = max(timeanswer, countertemp.endtime);
		counterpq.push(countertemp);
	}

	cout << timeanswer << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << costanswer[i] << "\n";
	}
}