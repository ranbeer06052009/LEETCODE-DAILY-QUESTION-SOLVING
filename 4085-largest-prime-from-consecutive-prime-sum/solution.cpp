class Solution {
public:
    int largestPrime(int n) {
        if(n==1) return 0;
        vector<char> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;
        for (int p = 2; (long long)p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int j = p*p; j <= n; j += p) isPrime[j] = false;
            }
        }
        vector<int> primes;
        for (int i = 2; i <= n; ++i) if (isPrime[i]) primes.push_back(i);

        int sum = 0;
        int ans = 0;
        for (int p : primes) {
            sum += p;
            if (sum > n) break;
            if (isPrime[sum]) ans = sum; 
        }

        return ans;
    }
};
