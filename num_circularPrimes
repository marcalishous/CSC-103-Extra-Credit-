#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool isCircularPrime(int n) {
    int numDigits = floor(log10(n)) + 1;
    int num = n;
    for (int i = 0; i < numDigits; ++i) {
        if (!isPrime(num)) return false;
        int lastDigit = num % 10;
        num = lastDigit * pow(10, numDigits - 1) + num / 10;
    }
    return true;
}

int countCircularPrimes(int limit) {
    int count = 0;
    for (int i = 2; i < limit; ++i) {
        if (isCircularPrime(i)) {
            ++count;
        }
    }
    return count;
}

int main() {
    int limit = 1000000;
    int circularPrimesCount = countCircularPrimes(limit);
    cout << "Number of circular prime numbers under " << limit << ": " << circularPrimesCount << endl;
    return 0;
}
