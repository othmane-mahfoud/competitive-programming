#include <bits/stdc++.h>

using namespace std;

//used for doubles comparison

const double EPS = 1e-5;

// Consider the following arithmetic progression a_n = a_(n-1) + c

int arithmetic_sequence_nth(int a1, int n, int c) {
    return a1 + ((n-1) * c);
}

int sum_to_n (int a1, int an, int n){
    return (n * ( a1 + an )) / 2;
}

// Consider the following geometric progression a_n = a * r^(n-1)

int geo_sum_from_m_to_n (int a, int r, int m, int n){
    return a * ((pow(r, m) - pow(r,n)) / (1 - r));
}

// Euclidean algorithm to compute the greatest common divisor of two integers + Lowest common multiple

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm (int a, int b) {
    return (a * b) / gcd(a, b);
}

// Prime numbers generation using sieve of eratosthenes

vector<int> eratosthenes(int n){
    bool *isMarked = new bool[n+1];
    memset(isMarked, 0, n+1);
    vector<int> primes;
    int i = 2;
    for(; i*i <= n; ++i)
        if (!isMarked[i]) {
            primes.push_back(i);
            for(int j = i; j <= n; j += i)
                isMarked[j] = true;
        }
    for (; i <= n; i++)
        if (!isMarked[i])
            primes.push_back(i);
    return primes;
}

// generating prime factors of a number

map<int, int> factor(int N) {
    vector<int> primes;
    primes = eratosthenes(static_cast<int>(sqrt(N+1)));
    map<int, int> factors;
    for(int i = 0; i < primes.size(); ++i){
        int prime = primes[i], power = 0;
        while(N % prime == 0){
            power++;
            N /= prime; }
        if(power > 0){
            factors[prime] = power;
        } }
    if (N > 1) {
        factors[N] = 1;
    }
    return factors;
}

int main(){
    
    // variables declarations
    
    double x = 16.0;
    double a = 1.33335;
    double b = 1.33336;
    
    int n = 18;
    int m = 12;
    
    // some math functions
    
    cout << log(x) << endl;
    cout << log10(x) << endl;
    cout << exp(x) << endl;
    
    // comparing double using a defined epsillon for precision
    
//    if (abs(a-b) < EPS)
//        cout << " a < b " << endl;
//    
//    else
//        cout << " b < a " << endl;
    
    // finding the gcd and lcm
    
    cout << "the gcd for " << n << " and " << m << " is " << gcd(n, m) << " and their lcm is " << lcm(n, m) << endl;
    
    // sieve and factorization
    
    cout << "all prime numbers less than " << n << ":" << endl;
    vector<int> primes = eratosthenes(n);
    vector<int>::iterator it;
    for (it = primes.begin(); it < primes.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << n << "'s prime factrization is as follows: ";
    map<int, int> factors = factor(n);
    for (int i = 0; i < factors.size(); i++) {
        if ( factors[i] != 0 ) {
            cout << i << "^" << factors[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
