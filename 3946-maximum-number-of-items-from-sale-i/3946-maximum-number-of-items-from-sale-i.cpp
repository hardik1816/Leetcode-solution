
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int minIndex = 0;

        for (int i = 1; i < n; i++) {
            if (items[i][1] < items[minIndex][1]) {
                minIndex = i;
            }
        }

        int minPrice = items[minIndex][1];

        vector<int> value(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    value[i]++;
                }
            }
        }

        const int NEG = -1000000000;

        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (i == minIndex) {
                continue;
            }

            int price = items[i][1];

            for (int b = budget; b >= price; b--) {
                if (dp[b - price] != NEG) {
                    dp[b] = max(dp[b], dp[b - price] + value[i]);
                }
            }
        }

        int answer = 0;

        for (int b = 0; b <= budget; b++) {
            if (dp[b] == NEG) {
                continue;
            }

            int remaining = budget - b;

            if (remaining < minPrice) {
                answer = max(answer, dp[b]);
            } else {
                int total = dp[b] + value[minIndex];
                total += (remaining - minPrice) / minPrice;

                answer = max(answer, total);
            }
        }

        return answer;
    }
};
