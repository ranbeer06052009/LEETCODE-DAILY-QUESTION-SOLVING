class Solution {
public:
    int reflection(int x) {
        string b = "";
        while (x > 0) {
            b.push_back((x & 1) + '0');
            x >>= 1;
        }
        return stoi(b, nullptr, 2);
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int ra = reflection(a);
            int rb = reflection(b);
            if (ra != rb) return ra < rb;
            return a < b;
        });
        return nums;
    }
};
