#include <iostream>

using namespace std;

int main() {
	int colorNum[6]; // 색종이의 개수. 모든 색종이는 큰 색종이부터 사용하고 작은 색종이로 공백을 채움.
	for (int i = 0; i < 6; i++) {
		cin >> colorNum[i];
	}

	int numBoard = 0; // 판의 개수
	while (colorNum[5] != 0) { // 6cm 색종이 모두 사용
		colorNum[5]--; // 6cm 색종이 1개 사용해서 1판 모두 채우기
		numBoard++;
	}

	while (colorNum[4] != 0) { // 5cm 색종이 모두 사용
		colorNum[4]--; // 5cm 색종이 1개 사용해서 채우기
		numBoard++;
		if (colorNum[0] >= 11) { // 공백에 1cm 색종이 최대 11개까지 채우기
			colorNum[0] -= 11;
		}
		else {
			colorNum[0] = 0;
		}
	}

	while (colorNum[3] != 0) { // 4cm 색종이 모두 사용
		colorNum[3]--; // 4cm 색종이 1개 사용해서 채우기
		numBoard++;
		if (colorNum[1] >= 5) { // 공백에 2cm 색종이 최대 5개까지 채우기
			colorNum[1] -= 5;
		}
		else { // 2cm 색종이로 공백을 다 못채운 경우 1cm 색종이를 공백에 채우기
			if (colorNum[0] >= 20 - colorNum[1] * 4) {
				colorNum[0] -= 20 - colorNum[1] * 4;
				colorNum[1] = 0;
			}
			else {
				colorNum[1] = 0;
				colorNum[0] = 0;
			}
		}
	}

	while (colorNum[2] != 0) { // 3cm 색종이 모두 사용
		if (colorNum[2] >= 4) {
			colorNum[2] -= 4; // 3cm 색종이 4개를 사용해서 1판 채우기
			numBoard++;
		}
		else if (colorNum[2] == 3) { 
			colorNum[2] = 0; // 3cm 색종이 3개를 모두 사용
			numBoard++;
			if (colorNum[1] >= 1) { // 공백에 2cm 색종이 최대 1개까지 채우기
				colorNum[1]--;
				if (colorNum[0] >= 5) { // 2cm 색종이로 공백을 다 못채운 경우 1cm 색종이를 최대 5개까지 공백에 채우기
					colorNum[0] -= 5;
				}
				else {
					colorNum[0] = 0;
				}
			}
			else {
				if (colorNum[0] >= 9) { // 2cm 색종이가 없어서 1cm 색종이로만 최대 9개를 사용
					colorNum[0] -= 9;
				}
				else {
					colorNum[0] = 0;
				}
			}
		}
		else if (colorNum[2] == 2) {
			colorNum[2] = 0; // 3cm 색종이 2개를 모두 사용
			numBoard++;
			if (colorNum[1] >= 3) { // 공백에 2cm 색종이 최대 3개까지 채우기
				colorNum[1] -= 3;
				if (colorNum[0] >= 6) { // 남은 공백에 1cm 색종이 최대 6개까지 채우기
					colorNum[0] -= 6;
				}
				else {
					colorNum[0] = 0;
				}
			}
			else {
				if (colorNum[0] >= 18 - colorNum[1] * 4) {
					colorNum[0] -= 18 - colorNum[1] * 4;
					colorNum[1] = 0;
				}
				else {
					colorNum[1] = 0;
					colorNum[0] = 0;
				}
			}
		}
		else if (colorNum[2] == 1) {
			colorNum[2] = 0; // 3cm 색종이 1개를 사용
			numBoard++;
			if (colorNum[1] >= 5) { // 공백에 2cm 색종이 최대 5개까지 채우기
				colorNum[1] -= 5;
				if (colorNum[0] >= 7) { // 남은 공백에 1cm 색종이 최대 7개까지 채우기
					colorNum[0] -= 7;
				}
				else {
					colorNum[0] = 0;
				}
			}
			else {
				if (colorNum[0] >= 27 - colorNum[1] * 4) {
					colorNum[0] -= 27 - colorNum[1] * 4;
					colorNum[1] = 0;
				}
				else {
					colorNum[1] = 0;
					colorNum[0] = 0;
				}
			}
		}
	}

	while (colorNum[1] != 0) { // 2cm 색종이 모두 사용
		numBoard++;
		if (colorNum[1] >= 9) { // 공백에 2cm 색종이 최대 9개까지 사용
			colorNum[1] -= 9;
		}
		else {
			if (colorNum[0] >= 36 - colorNum[1] * 4) { // 남은 공백에 1cm 최대 36개까지 채우기
				colorNum[0] -= 36 - colorNum[1] * 4;
				colorNum[1] = 0;
			}
			else {
				colorNum[1] = 0;
				colorNum[0] = 0;
			}
		}
	}

	while (colorNum[0] != 0) { // 1cm 색종이 모두 사용
		numBoard++;
		if (colorNum[0] >= 36) {
			colorNum[0] -= 36;
		}
		else {
			colorNum[0] = 0;
		}
	}

	cout << numBoard;

}