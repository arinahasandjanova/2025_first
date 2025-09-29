#include <iostream>
#include <algorithm>

int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;

    long long best = -1, mmax = std::max(n, m), mmin = std::min(n, m);

    for (long long h = mmax; h > 0; h--) {
        long long x = m * n - k + 1;
        long long candidate = x - (x % h);
        if (candidate > best && x / h <= mmin) best = candidate;
    }

    std::cout << best << std::endl;
    return 0;
}