
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp;
        int balance = 0;

        for (char ch : s) {
            if (ch == '(') {
                balance++;
                temp += ch;
            }
            else if (ch == ')') {
                if (balance > 0) {
                    balance--;
                    temp += ch;
                }
            }
            else {
                temp += ch;
            }
        }

        string answer;
        balance = 0;

        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == ')') {
                balance++;
                answer += temp[i];
            }
            else if (temp[i] == '(') {
                if (balance > 0) {
                    balance--;
                    answer += temp[i];
                }
            }
            else {
                answer += temp[i];
            }
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }
};
