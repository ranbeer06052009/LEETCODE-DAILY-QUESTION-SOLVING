class Solution {
public:
    const long long MOD = 1e9 + 7;
    int divisibleGame(vector<int>& nums) {
        long long bestScore = -*min_element(nums.begin(), nums.end());
        int bestPrime = 2;
        set<int> prime;
        for(int num : nums) {
            int x = num;
            for(int i = 2; i * i <= x; i++) {
                if(x % i == 0) {
                    prime.insert(i);
                    while(x % i == 0) x/= i;
                }
            }
            if(x>1) prime.insert(x);
        }
        for(int p : prime) {
            long long cur = 0;
            long long maxi = -1e9;
            for(int num : nums) {
                long long val = (num % p == 0) ? num : -num;
                cur = max(val, val + cur);
                maxi = max(maxi, cur);
            }
            if(maxi > bestScore) {
                bestScore = maxi;
                bestPrime = p;
            }
            else if(maxi == bestScore && p < bestPrime) bestPrime = p;
        }
        bestScore = (bestScore % MOD + MOD) % MOD;
        return (bestScore * bestPrime) % MOD;
    }
};
