#include <vector>

using namespace std;

class NumArray {
    vector<int> pre_sum;

public:
    NumArray(vector<int> &nums) {
        // 这一步会默认初始化为全0，故pre_sum[0]=0
        pre_sum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        return pre_sum[right + 1] - pre_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */