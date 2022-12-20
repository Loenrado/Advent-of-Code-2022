#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("day2.in");

void p1() {
	// abc * xyz
	int result[3][3] = {{3, 6, 0}, {0, 3, 6}, {6, 0, 3}};

	char a, x;
	long long score = 0;
	while (fin >> a >> x) {
		// cout << (x-'X') << ' ' << result[a-'A'][x-'X'] << '\n';
		score += (x-'X'+1) + result[a-'A'][x-'X'];
	}

	cout << score << '\n';
}

void p2() {
	int result[3][3] = {{3, 6, 0}, {0, 3, 6}, {6, 0, 3}};

	long long score = 0;
	char a, x;
	while (fin >> a >> x) {
		for (int i = 0; i < 3; ++i) {
			if (result[a-'A'][i] == (x-'X')*3) {
				x = 'X'+i;
				break;
			}
		}

		score += (x-'X'+1) + result[a-'A'][x-'X'];
	}

	cout << score << '\n';
}

int main() {
	p2();

	return 0;
}