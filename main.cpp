// CSS 342 Fall 2018
// Lab 2 - Gordon Malan
// This program tracks the Sieve of Eratosthenes

#include <iostream>
#include <vector>
#include <math.h>
#include <sys/time.h>

using namespace std;

int sieve(int n, vector<int> &primes) {
	int cost = 0;
	bool array[n + 1];

	// array initialization
	for (int i = 0; i < n; i++)
		array[i] = true;

	// sieve implementation
	int max = int(sqrt(double(n)));
	for (int j = 2; j <= max; j++) {
		if (array[j] == false) {
			continue;
		}
		for (int k = j + 1; k <= n; k++) {
			if (k % j == 0) {
				array[k] = false;
				cost++;
			}
		}
	}

	// collect all prime numbers      
	for (int i = 0; i < n; i++)
		if (array[i] == true)
			primes.push_back(i);

	return cost;
}

main() {
	int n = 0;
	struct timeval startTime, endTime;

	while (n < 2) {
		cout << "Enter n ";
		cin >> n;
	}

	char printOption = 'n';
	cout << "print all primes (y|n)? ";
	cin >> printOption;

	for (int i = 2; i <= n; i++) {
		gettimeofday(&startTime, NULL);

		vector<int> primes;
		int cost = sieve(i, primes);

		gettimeofday(&endTime, NULL);
		cout << "primes[1.." << i << "] took " << cost
			<< " sweeping operations...time required = "
			<< (endTime.tv_sec - startTime.tv_sec) * 1000000 +
			(endTime.tv_usec - startTime.tv_usec) << endl;

		if (printOption == 'y') {
			cout << "all primes = ";
			for (int j = 0; j < primes.size(); j++)
				cout << primes[j] << " ";
			cout << endl;
		}

		cerr << i << " " << cost << endl;
	}
}

