
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sa(n), rank(n), newRank(n);
        vector<int> values = nums;

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = lower_bound(values.begin(), values.end(), nums[i]) - values.begin();
        }

        for (int len = 1; len < n; len *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b]) {
                    return rank[a] < rank[b];
                }

                int ra = (a + len < n) ? rank[a + len] : -1;
                int rb = (b + len < n) ? rank[b + len] : -1;

                return ra < rb;
            });

            newRank[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1];
                int b = sa[i];

                int a1 = rank[a];
                int b1 = rank[b];

                int a2 = (a + len < n) ? rank[a + len] : -1;
                int b2 = (b + len < n) ? rank[b + len] : -1;

                newRank[b] = newRank[a] + (a1 != b1 || a2 != b2);
            }

            rank = newRank;

            if (rank[sa[n - 1]] == n - 1) {
                break;
            }
        }

        vector<int> lcp(n, 0);
        vector<int> position(n);

        for (int i = 0; i < n; i++) {
            position[sa[i]] = i;
        }

        int common = 0;

        for (int i = 0; i < n; i++) {
            int p = position[i];

            if (p == 0) {
                common = 0;
                continue;
            }

            int j = sa[p - 1];

            while (i + common < n &&
                   j + common < n &&
                   nums[i + common] == nums[j + common]) {
                common++;
            }

            lcp[p] = common;

            if (common > 0) {
                common--;
            }
        }

        int answer = n;

        for (int i = 0; i < n; i++) {
            int maxLCP = lcp[i];

            if (i + 1 < n) {
                maxLCP = max(maxLCP, lcp[i + 1]);
            }

            int requiredLength = maxLCP + 1;
            int suffixLength = n - sa[i];

            if (requiredLength <= suffixLength) {
                answer = min(answer, requiredLength);
            }
        }

        return answer;
    }
};
