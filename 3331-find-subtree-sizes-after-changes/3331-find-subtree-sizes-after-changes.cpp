
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> nearest(26, -1);
        vector<int> newParent(n, -1);

        vector<tuple<int, int, int>> st;
        st.push_back({0, 0, -1});

        while (!st.empty()) {
            auto [node, state, previous] = st.back();
            st.pop_back();

            int ch = s[node] - 'a';

            if (state == 0) {
                previous = nearest[ch];

                if (node != 0) {
                    if (previous != -1) {
                        newParent[node] = previous;
                    } else {
                        newParent[node] = parent[node];
                    }
                }

                nearest[ch] = node;

                st.push_back({node, 1, previous});

                for (int i = children[node].size() - 1; i >= 0; i--) {
                    st.push_back({children[node][i], 0, -1});
                }
            } else {
                nearest[ch] = previous;
            }
        }

        vector<vector<int>> newChildren(n);

        for (int i = 1; i < n; i++) {
            newChildren[newParent[i]].push_back(i);
        }

        vector<int> answer(n, 1);
        vector<int> order;
        order.push_back(0);

        for (int i = 0; i < order.size(); i++) {
            int node = order[i];

            for (int child : newChildren[node]) {
                order.push_back(child);
            }
        }

        for (int i = order.size() - 1; i > 0; i--) {
            int node = order[i];
            answer[newParent[node]] += answer[node];
        }

        return answer;
    }
};
