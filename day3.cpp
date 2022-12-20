#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

ifstream fin("day3.in");

void p1() {
	bool appears[52];

	string j;
	long long sum = 0;
	while (fin >> j) {
		memset(appears, 0, sizeof(appears));

		for (int i = 0; i < j.length() / 2; ++i) {
			appears[j[i]-'a' >= 0 ? j[i]-'a' : j[i]-'A'+26] = 1;
		}
		for (int i = j.length()/2; i < j.length(); ++i) {
			int index = j[i]-'a' >= 0 ? j[i]-'a' : j[i]-'A'+26;
			if (appears[index]) {
				sum += index + 1;
				break;
			}
		}
	}

	cout << sum << '\n';
}

void p2() {
	bool appears[3][52];

	string j[3];
	long long sum = 0;
	while (fin >> j[0] >> j[1] >> j[2]) {
		memset(appears, 0, sizeof(appears));

		for (int k = 0; k < 3; ++k) {
			for (int i = 0; i < j[k].length(); ++i) {
				int index = j[k][i]-'a' >= 0 ? j[k][i]-'a' : j[k][i]-'A'+26;
				appears[k][index] = 1;
			}
		}
		for (int i = 0; i < 52; ++i) {
			if (appears[0][i] && appears[1][i] && appears[2][i]) {
				sum += i + 1;
			}
		}
	}

	cout << sum << '\n';
}

int main() {
	p2();
	return 0;
}