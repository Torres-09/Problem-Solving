#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	
	int T;
	cin >> T;
	while (T--)
	{
		int x1, y1, x2, y2, r1, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (distance + min(r1,r2)<=max(r1,r2)) {		//내접하는 경우
			if (x1 == x2&&y1 == y2) {					//내접하는 경우 : 두 원 중심이 같을 때
				if (r1 == r2) {							//반지름이 같으면 같은 원
					cout << "-1\n";
				}
				else {									//반지름이 다르면 접점 없음
					cout << "0\n";
				}
			}
			else if (max(r1, r2) - distance > min(r1, r2)) {		//원이 원 안에 있는 경우
				cout << "0\n";
			}
			else {												//원이 내접할때
				cout << "1\n";
			}
			
			
		}
		else											//외접하는 경우
		{
			if (distance > r1 + r2)
				cout << "0\n";
			else if (distance == r1 + r2)
				cout << "1\n";
			else if (distance < r1 + r2)
				cout << "2\n";
		}
	}
	system("pause");
}