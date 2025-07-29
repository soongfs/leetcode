package leetcode.easy;

import java.util.HashMap;
import java.util.Map;

import util.input.ArrayUtil;

public class Question1 {
    public static void main(String[] args) {
        class Solution {
            public int[] twoSum(int[] nums, int target) {
                Map<Integer, Integer> map = new HashMap<>();
                for (int i = 0; i < nums.length; i++) {
                    int expect = target - nums[i];
                    if (map.containsKey(expect)) {
                        return new int[] { map.get(expect), i };
                    }
                    map.put(nums[i], i);
                }
                return new int[0];
            }
        }
        ArrayUtil.showArray(new Solution().twoSum(new int[] { 2, 7, 11, 15 }, 9));
    }
}
