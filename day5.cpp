#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <regex>

using namespace std;

ifstream fin("day5.in");

void p1() {
	vector<stack<char> > vq;
	string line;
	while (getline(fin, line, '\n')) {
		if (vq.empty()) vq.resize((line.length() + 1) / 4);
		if (isdigit(line[1])) break;
		
		vector<char> l;
		for (int i = 1; i < line.length(); i += 4) {
			if (line[i] == ' ') continue;
			vq[i/4].push(line[i]);
		}

	}
	int N = vq.size();
	vector<stack<char> > actual (N);
	for (int i = 0; i < N; ++i) {
		while (!vq[i].empty()) {
			actual[i].push(vq[i].top());
			vq[i].pop();
		}
	}
	getline(fin, line, '\n');
	while (getline(fin, line, '\n')) {
		smatch match;
		regex_match(line, match, regex("move ([0-9]+) from ([0-9]+) to ([0-9]+)"));
		if (match.size() != 4) throw runtime_error("Match error.");

		int a[3];
		for (int i = 0; i < 3; ++i) {
			a[i] = stoi(match.str(i+1));
		}
		--a[1];
		--a[2];
		for (int i = 0; i < a[0]; ++i) {
			actual[a[2]].push(actual[a[1]].top());
			actual[a[1]].pop();
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << actual[i].top();
	}
	cout << '\n';
}

void p2() {
	vector<stack<char> > vq;
	string line;
	while (getline(fin, line, '\n')) {
		if (vq.empty()) vq.resize((line.length() + 1) / 4);
		if (isdigit(line[1])) break;
		
		vector<char> l;
		for (int i = 1; i < line.length(); i += 4) {
			if (line[i] == ' ') continue;
			vq[i/4].push(line[i]);
		}

	}
	int N = vq.size();
	vector<stack<char> > actual (N);
	for (int i = 0; i < N; ++i) {
		while (!vq[i].empty()) {
			actual[i].push(vq[i].top());
			vq[i].pop();
		}
	}
	getline(fin, line, '\n');
	while (getline(fin, line, '\n')) {
		smatch match;
		regex_match(line, match, regex("move ([0-9]+) from ([0-9]+) to ([0-9]+)"));
		if (match.size() != 4) throw runtime_error("Match error.");

		int a[3];
		for (int i = 0; i < 3; ++i) {
			a[i] = stoi(match.str(i+1));
		}
		--a[1];
		--a[2];
		stack<int> t;
		for (int i = 0; i < a[0]; ++i) {
			t.push(actual[a[1]].top());
			actual[a[1]].pop();
		}
		while (!t.empty()) {
			actual[a[2]].push(t.top());
			t.pop();
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << actual[i].top();
	}
	cout << '\n';
}

int main() {
	p2();

	return 0;
}