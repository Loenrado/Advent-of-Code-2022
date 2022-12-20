#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void p1() {
	ifstream fin("day1.in");

	string in;
	long long sum, maxSum = 0;
	while(getline(fin, in, '\n')) {
		if (in == "") {
			maxSum = max(maxSum, sum);
			sum = 0;
			continue;
		}
		sum += stoll(in);
	}

	cout << maxSum << '\n';
}

void p2() {
	ifstream fin("day1.in");

	priority_queue<long long, vector<long long>, greater<long long> > pq;

	string in;
	long long sum;
	while(getline(fin, in, '\n')) {
		if (in == "") {
			long long third_max = 0;
			if (!pq.empty()) {
				third_max = pq.top();
			}
			if (pq.size() == 3) {
				pq.pop();
				third_max = max(sum, third_max);
			}
			pq.push(third_max);

			sum = 0;
			continue;
		}
		sum += stoll(in);
	}

	sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << '\n';
}

int main() {
	p1();
	p2();

	return 0;
}