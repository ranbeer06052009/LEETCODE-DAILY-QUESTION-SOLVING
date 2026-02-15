class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.length();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int centers[2][2] = {{i, i}, {i, i + 1}};
            for (auto& p : centers) {
                int l = p[0], r = p[1];
                while (l >= 0 && r < n && s[l] == s[r]) {
                    l--;
                    r++;
                }
                
                int coreLen = r - l - 1;
                if (coreLen > 1) {
                    ans = max(ans, coreLen);
                }
                
                if (l >= 0 && r < n) {
                    int l1 = l - 1, r1 = r;
                    while (l1 >= 0 && r1 < n && s[l1] == s[r1]) {
                        l1--;
                        r1++;
                    }
                    ans = max(ans, r1 - l1 - 1); 

                    int l2 = l, r2 = r + 1;
                    while (l2 >= 0 && r2 < n && s[l2] == s[r2]) {
                        l2--;
                        r2++;
                    }
                    ans = max(ans, r2 - l2 - 1);
                } else if (l >= 0 || r < n) {
                    ans = max(ans, coreLen + 1);
                }
            }
        }
        return ans;
    }
};
