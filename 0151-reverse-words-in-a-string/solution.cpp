class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0;
        int end = n - 1;

        while (s[start] == ' ')
            start++;
        while (s[end] == ' ')
            end--;

        string ans = "";
        string temp = "";

        while (start <= end) {
            if (s[end] != ' ') {
                temp += s[end];
            } else {
                if (temp != "") {
                    reverse(temp.begin(), temp.end());
                    ans += temp;
                    ans += " ";
                    temp = "";
                }
            }
            end--;
        }

        reverse(temp.begin(), temp.end());
        ans += temp;

        return ans;
    }
};
