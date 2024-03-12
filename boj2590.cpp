#include <iostream>

using namespace std;

int main() {
	int colorNum[6]; // �������� ����. ��� �����̴� ū �����̺��� ����ϰ� ���� �����̷� ������ ä��.
	for (int i = 0; i < 6; i++) {
		cin >> colorNum[i];
	}

	int numBoard = 0; // ���� ����
	while (colorNum[5] != 0) { // 6cm ������ ��� ���
		colorNum[5]--; // 6cm ������ 1�� ����ؼ� 1�� ��� ä���
		numBoard++;
	}

	while (colorNum[4] != 0) { // 5cm ������ ��� ���
		colorNum[4]--; // 5cm ������ 1�� ����ؼ� ä���
		numBoard++;
		if (colorNum[0] >= 11) { // ���鿡 1cm ������ �ִ� 11������ ä���
			colorNum[0] -= 11;
		}
		else {
			colorNum[0] = 0;
		}
	}

	while (colorNum[3] != 0) { // 4cm ������ ��� ���
		colorNum[3]--; // 4cm ������ 1�� ����ؼ� ä���
		numBoard++;
		if (colorNum[1] >= 5) { // ���鿡 2cm ������ �ִ� 5������ ä���
			colorNum[1] -= 5;
		}
		else { // 2cm �����̷� ������ �� ��ä�� ��� 1cm �����̸� ���鿡 ä���
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

	while (colorNum[2] != 0) { // 3cm ������ ��� ���
		if (colorNum[2] >= 4) {
			colorNum[2] -= 4; // 3cm ������ 4���� ����ؼ� 1�� ä���
			numBoard++;
		}
		else if (colorNum[2] == 3) { 
			colorNum[2] = 0; // 3cm ������ 3���� ��� ���
			numBoard++;
			if (colorNum[1] >= 1) { // ���鿡 2cm ������ �ִ� 1������ ä���
				colorNum[1]--;
				if (colorNum[0] >= 5) { // 2cm �����̷� ������ �� ��ä�� ��� 1cm �����̸� �ִ� 5������ ���鿡 ä���
					colorNum[0] -= 5;
				}
				else {
					colorNum[0] = 0;
				}
			}
			else {
				if (colorNum[0] >= 9) { // 2cm �����̰� ��� 1cm �����̷θ� �ִ� 9���� ���
					colorNum[0] -= 9;
				}
				else {
					colorNum[0] = 0;
				}
			}
		}
		else if (colorNum[2] == 2) {
			colorNum[2] = 0; // 3cm ������ 2���� ��� ���
			numBoard++;
			if (colorNum[1] >= 3) { // ���鿡 2cm ������ �ִ� 3������ ä���
				colorNum[1] -= 3;
				if (colorNum[0] >= 6) { // ���� ���鿡 1cm ������ �ִ� 6������ ä���
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
			colorNum[2] = 0; // 3cm ������ 1���� ���
			numBoard++;
			if (colorNum[1] >= 5) { // ���鿡 2cm ������ �ִ� 5������ ä���
				colorNum[1] -= 5;
				if (colorNum[0] >= 7) { // ���� ���鿡 1cm ������ �ִ� 7������ ä���
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

	while (colorNum[1] != 0) { // 2cm ������ ��� ���
		numBoard++;
		if (colorNum[1] >= 9) { // ���鿡 2cm ������ �ִ� 9������ ���
			colorNum[1] -= 9;
		}
		else {
			if (colorNum[0] >= 36 - colorNum[1] * 4) { // ���� ���鿡 1cm �ִ� 36������ ä���
				colorNum[0] -= 36 - colorNum[1] * 4;
				colorNum[1] = 0;
			}
			else {
				colorNum[1] = 0;
				colorNum[0] = 0;
			}
		}
	}

	while (colorNum[0] != 0) { // 1cm ������ ��� ���
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