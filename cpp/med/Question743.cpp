#include <bits/stdc++.h>

using namespace std;

/**
 * Dijkstra
 */
class Solution {
public:
    // int networkDelayTime(vector<vector<int>> &times, int n, int k)
    // {
    //     vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
    //     for (auto &t : times) {
    //         g[t[0] - 1][t[1] - 1] = t[2];
    //     }

    //     vector<int> dis(n, INT_MAX / 2), done(n);
    //     dis[k - 1] = 0;
    //     while (true) {
    //         int x = -1;
    //         for (int i = 0; i < n; i++) {
    //             if (!done[i] && (x < 0 || dis[i] < dis[x])) {
    //                 x = i;
    //             }
    //         }
    //         if (x < 0) {
    //             return ranges::max(dis);
    //         }
    //         if (dis[x] == INT_MAX / 2) {
    //             return -1;
    //         }
    //         done[x] = true;
    //         for (int y = 0; y < n; y++) {
    //             dis[y] = min(dis[y], dis[x] + g[x][y]);
    //         }
    //     }
    // }

    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times) {
            g[t[0] - 1].emplace_back(t[1] - 1, t[2]);
        }

        vector<int> dis(n, INT_MAX);
        dis[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k - 1);
        while (!pq.empty()) {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x]) {
                continue;
            }
            for (auto &[y, d] : g[x]) {
                int new_dis = dx + d;
                if (new_dis < dis[y]) {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }
        int mx = ranges::max(dis);
        return mx < INT_MAX ? mx : -1;
    }
};
