#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

#define N 1e5

vll prime(N, true);
vll primes;
vll spd(N, -1);

void init() {
    prime[0] = prime[1] = false;
    for (ll i = 2; i < prime.size(); i++)
        if (prime[i])
            for (ll j = i * i; j < prime.size(); j += i)
                prime[j] = false;
    for (int i = 2; i < prime.size(); i++) if (prime[i]) primes.push_back(i);
    spd[0] = spd[1] = -1;
    for (ll j = 0; j < primes.size(); j++)
        for (ll i = 1; i < N && primes[j] * i < N; i++)
            if (spd[i * primes[j]] == -1) spd[i * primes[j]] = primes[j];
}

void printpfacts(int n) {
    while (n != 1) {
        assert(spd[n] != -1);
        cout << spd[n] << " ";
        n /= spd[n];
    }
    cout << endl;
}

int main() {
    init();
    for (int i = 2; i < N; i++) {
        cout << i << ": ";
        printpfacts(i);
    }
    return 0;
}
