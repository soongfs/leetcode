#include <algorithm>
#include <vector>

class Solution {
public:
    double separateSquares(std::vector<std::vector<int>> &squares) {
        long long tot_area = 0;
        int max_y = 0;
        for (auto &sq : squares) {
            int l = sq[2];
            tot_area += 1LL * l * l;
            max_y = std::max(max_y, sq[1] + l);
        }

        auto check = [&](double y) -> bool {
            double area = 0;
            for (auto &sq : squares) {
                double yi = sq[1];
                if (yi < y) {
                    double l = sq[2];
                    area += l * std::min(y - yi, l);
                }
            }
            return area >= tot_area / 2.0;
        };

        double left = 0, right = max_y;
        for (int i = 0; i < 47; ++i) {
            double mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return (left + right) / 2;
    }
};
