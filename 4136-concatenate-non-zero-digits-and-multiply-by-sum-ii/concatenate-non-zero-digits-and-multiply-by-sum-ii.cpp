class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        long long mod=1e9+7;
        vector<long long> prefd(n+1,0);
        vector<long long> prefNum(n+1, 0);
        vector<long long> power10(n+1, 1);
        vector<int> nonZeroCount(n+1, 0);
        for(int i=0; i<n; i++){
            prefd[i+1]=prefd[i]+(s[i]-'0');
            power10[i+1] = (power10[i] * 10) % mod;
            
            if(s[i] != '0') {
                prefNum[i+1] = (prefNum[i] * 10 + (s[i]-'0')) % mod;
                nonZeroCount[i+1] = nonZeroCount[i] + 1;
            } else {
                prefNum[i+1] = prefNum[i];
                nonZeroCount[i+1] = nonZeroCount[i];
            }
        }
        int q=queries.size();
        vector<int> ans(q);
        for(int i=0; i<q; i++){
            int l=queries[i][0];
            int r=queries[i][1];
            long long digit_sum = prefd[r+1] - prefd[l];
            int k = nonZeroCount[r+1] - nonZeroCount[l];
            
            long long range_num = 0;
            if (k > 0) {
                range_num = (prefNum[r+1] - (prefNum[l] * power10[k]) % mod + mod) % mod;
            }
            
            ans[i] = ((digit_sum % mod) * (range_num % mod)) % mod;
        }
        return ans;
    }
};