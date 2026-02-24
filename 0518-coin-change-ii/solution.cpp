class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount+1, 0);

        // Base case for first coin
        for(int t = 0; t <= amount; t++)
            prev[t] = (t % coins[0] == 0);

        for(int i = 1; i < n; i++) {

            vector<unsigned long long> cur(amount+1, 0);   // 🔥 RESET HERE

            for(int t = 0; t <= amount; t++) {
                unsigned long long notT = prev[t];
                unsigned long long take = 0;
                if(t >= coins[i])
                    take = cur[t - coins[i]];

                cur[t] = take + notT;
            }
            prev = cur;
        }

        return prev[amount];
    }
};
