#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("day6.in");

void p1() {
	vector<int> c (26, 0);
	char b;
	int i = 0;
	queue<char> q;
	while(fin >> b) {
		++i;
		++c[b-'a'];
		q.push(b);
		if (q.size() > 4) {
			--c[q.front()-'a'];
			q.pop();
		}
		if (q.size() != 4) continue;
		bool g = true;
		for(int i = 0; i < 26; ++i) {
			if (c[i] > 1) {
				g = false;
				break;
			}
		}
		if (g) {
			cout << i << '\n';
			break;
		}
	}
}

void p2() {
	vector<int> c (26, 0);
	char b;
	int i = 0;
	queue<char> q;
	while(fin >> b) {
		++i;
		++c[b-'a'];
		q.push(b);
		if (q.size() > 14) {
			--c[q.front()-'a'];
			q.pop();
		}
		if (q.size() != 14) continue;
		bool g = true;
		for(int i = 0; i < 26; ++i) {
			if (c[i] > 1) {
				g = false;
				break;
			}
		}
		if (g) {
			cout << i << '\n';
			break;
		}
	}
}

int main() {
	p2();
	return 0;
}