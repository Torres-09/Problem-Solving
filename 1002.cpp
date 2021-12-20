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

		if (distance + min(r1,r2)<=max(r1,r2)) {		//�����ϴ� ���
			if (x1 == x2&&y1 == y2) {					//�����ϴ� ��� : �� �� �߽��� ���� ��
				if (r1 == r2) {							//�������� ������ ���� ��
					cout << "-1\n";
				}
				else {									//�������� �ٸ��� ���� ����
					cout << "0\n";
				}
			}
			else if (max(r1, r2) - distance > min(r1, r2)) {		//���� �� �ȿ� �ִ� ���
				cout << "0\n";
			}
			else {												//���� �����Ҷ�
				cout << "1\n";
			}
			
			
		}
		else											//�����ϴ� ���
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