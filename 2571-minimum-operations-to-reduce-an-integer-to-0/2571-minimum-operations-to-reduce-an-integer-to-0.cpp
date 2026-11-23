class Solution {
public:
    int minOperations(int n) {
        int operations = 0;

        while (n > 0) {
            if ((n & (n - 1)) == 0) {
                operations++;
                break;
            }

            if (n % 2 == 0) {
                n /= 2;
            }
            else if (n % 4 == 1 || n == 3) {
                n--;
                operations++;
            }
            else {
                n++;
                operations++;
            }
        }

        return operations;
    }
};