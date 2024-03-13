#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main() {
	int maxMeeting = 1; // 확정된 회의 개수
	int N; // 회의의 개수
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		v.push_back({ temp2, temp1 }); // 종료 시간, 시작 시간 순으로 저장
	}

	sort(v.begin(), v.end()); // 회의 종료 시간을 기준으로 오름차순으로 정렬

	int time = v[0].first; // 처음 회의의 종료시간
	for (int i = 1; i < N; i++)
	{
		if (time <= v[i].second) // 종료와 동시에 시작하거나 종료 후 시작하는 회의인 경우
		{
			maxMeeting++;
			time = v[i].first; // 종료시간 갱신
		}
	}

	cout << maxMeeting;
	return 0;


}