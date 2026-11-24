class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int answer = min(n, 2);

        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                bool valid = true;

                for (int a = i; a <= j && valid; a++) {
                    for (int b = a + 1; b <= j; b++) {
                        if (gcd(nums[a], nums[b]) != 1) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid) {
                    break;
                }

                answer = max(answer, j - i + 1);
            }
        }

        return answer;
    }
};