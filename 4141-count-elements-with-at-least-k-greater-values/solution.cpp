class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        if (k == 0) return n;
        int i = n - k;  

        int v = sorted[i];

        int ans = 0;
        for (int x : nums) {
            if (x < v) ans++;
        }
     return ans;
    }
};
