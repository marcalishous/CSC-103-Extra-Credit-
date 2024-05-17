#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to generate circular primes below a given limit
vector<int> generateCircularPrimes(int limit) {
    vector<int> circularPrimes;

    // Iterate through numbers below the limit
    for (int i = 2; i < limit; ++i) {
        // Check if the number is prime
        if (isPrime(i)) {
            int temp = i;
            int num_digits = log10(i) + 1;

            // Check all rotations of the number
            bool isCircularPrime = true;
            for (int j = 0; j < num_digits; ++j) {
                // Check if the rotation is prime
                if (!isPrime(temp)) {
                    isCircularPrime = false;
                    break;
                }
                // Rotate the digits
                int first_digit = temp % 10;
                temp = temp / 10 + first_digit * pow(10, num_digits - 1);
            }

            // If all rotations are prime, add to circular primes vector
            if (isCircularPrime)
                circularPrimes.push_back(i);
        }
    }

    return circularPrimes;
}

int main() {
    int limit = 1000;
    vector<int> circularPrimes = generateCircularPrimes(limit);

    cout << "Circular Prime Numbers below 1 million:\n";
    for (int prime : circularPrimes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}