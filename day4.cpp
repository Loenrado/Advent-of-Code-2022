#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

ifstream fin ("day4.in");

void p1() {
	string line;
	long long count = 0;
	while(getline(fin, line, '\n')) {
		smatch match;
		regex_match(line, match, regex("([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)"));
		if (match.size() != 5) throw runtime_error("Incorrect matches.");
		int a[4];
		for (int i = 0; i < 4; ++i) {
			a[i] = stoi(match.str(i+1));
		}
		if ((a[0] <= a[2] && a[1] >= a[3]) || (a[2] <= a[0] && a[3] >= a[1])) {
			++count;
		}
	}

	cout << count << '\n';
}

void p2() {
	string line;
	long long count = 0;
	while(getline(fin, line, '\n')) {
		smatch match;
		regex_match(line, match, regex("([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)"));
		if (match.size() != 5) throw runtime_error("Incorrect matches.");
		int a[4];
		for (int i = 0; i < 4; ++i) {
			a[i] = stoi(match.str(i+1));
		}
		if ((a[0] >= a[2] && a[0] <= a[3]) || (a[1] >= a[2] && a[1] <= a[3]) || (a[2] >= a[0] && a[2] <= a[1]) || (a[3] >= a[0] && a[3] <= a[1])) {
			++count;
		}
	}

	cout << count << '\n';
}

int main() {
	p2();
	return 0;
}