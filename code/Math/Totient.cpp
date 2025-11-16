#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int totient[N];

void precalculate() { // O(nloglog(n))
    int i, j;
    for(i = 0; i < N; i++) totient[i] = i;
    for(i = 2; i < N; i++) {
        if(totient[i] == i) {
            for(j = i; j < N; j += i) {
                totient[j] -= totient[j] / i;
            }
        }
    }

}


int phi(int n) { // O(sqrt(n))
	int ans = n;
	for (int p = 2; p * p <= n; p++) {
		if (n % p == 0) {
			while (n % p == 0) n /= p;
			ans -= ans / p;
		} // N*(p-1)/p = N-N/p
	}
	if (n > 1) ans -= ans / n;
	return ans;
}
int main()
{
    precalculate();
    for(int i = 1; i <= 20; i++) cout << phi(i) << " "; cout << '\n';
    for(int i = 1; i <= 20; i++) cout << totient[i] << " ";
}

