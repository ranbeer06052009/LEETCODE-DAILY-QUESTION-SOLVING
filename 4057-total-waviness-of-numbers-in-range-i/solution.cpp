class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_waviness = 0;
        
        for (int num = num1; num <= num2; ++num) {
            if (num < 100) {
                continue; 
            }
                
            int temp = num;
            int right_digit = temp % 10;
            temp /= 10;
            int mid_digit = temp % 10;
            temp /= 10;
            while (temp > 0) {
                int left_digit = temp % 10;
                if ((left_digit < mid_digit && mid_digit > right_digit) || 
                    (left_digit > mid_digit && mid_digit < right_digit)) {
                    total_waviness++;
                }
                right_digit = mid_digit;
                mid_digit = left_digit;
                temp /= 10;
            }
        }
        
        return total_waviness;
    }
};
