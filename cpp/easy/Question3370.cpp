class Solution {
public:
    int smallestNumber(int n) {
        int ret = 1;
        while (ret < n) {
            ret *= 2;
            ret++;
        }
        return ret;
    }
};