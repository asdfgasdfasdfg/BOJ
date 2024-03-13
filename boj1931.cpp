#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main() {
	int maxMeeting = 1; // Ȯ���� ȸ�� ����
	int N; // ȸ���� ����
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		v.push_back({ temp2, temp1 }); // ���� �ð�, ���� �ð� ������ ����
	}

	sort(v.begin(), v.end()); // ȸ�� ���� �ð��� �������� ������������ ����

	int time = v[0].first; // ó�� ȸ���� ����ð�
	for (int i = 1; i < N; i++)
	{
		if (time <= v[i].second) // ����� ���ÿ� �����ϰų� ���� �� �����ϴ� ȸ���� ���
		{
			maxMeeting++;
			time = v[i].first; // ����ð� ����
		}
	}

	cout << maxMeeting;
	return 0;


}