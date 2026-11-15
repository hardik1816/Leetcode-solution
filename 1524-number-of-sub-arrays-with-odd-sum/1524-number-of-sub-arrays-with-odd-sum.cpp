
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1000000007;

        int odd = 0;
        int even = 1;
        int parity = 0;

        long long ans = 0;

        for (int i = 0; i < arr.size(); i++) {

            parity = (parity + arr[i]) % 2;

            if (parity == 0) {
                ans += odd;
                even++;
            }
            else {
                ans += even;
                odd++;
            }

            ans = ans % mod;
        }

        return ans;
    }
};
