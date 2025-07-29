package leetcode.med;

import java.util.Arrays;

// import java.util.Map;
// import java.util.Set;
// import java.util.TreeMap;

public class Question826 {
    public static void main(String[] args) {
        /**
         * 相较上一次尝试其实只是改进了数据结构,用时稍微有点长
         * 724ms,击败8.09%.
         */
        class Solution {
            public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
                int n = difficulty.length;
                int[][] jobs = new int[n][2];
                for (int i = 0; i < n; i++) {
                    jobs[i][0] = difficulty[i];
                    jobs[i][1] = profit[i];
                }
                Arrays.sort(jobs, (x, y) -> x[0] - y[0]);
                int ans = 0;
                for (int i = 0; i < worker.length; i++) {
                    int j = 0, maxProfit = 0;
                    while (j < n && jobs[j][0] <= worker[i]) {
                        maxProfit = Math.max(maxProfit, jobs[j][1]);
                        j++;
                    }
                    ans += maxProfit;
                }
                return ans;
            }
        }

        /**
         * TreeMap 排序+贪心
         * 时间复杂度 O(nlogn)
         * 超时,可能是因为 TreeMap 是红黑树实现的,开销较大.
         */
        // class Solution {
        //     public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        //         Map<Integer, Integer> map = new TreeMap<>();
        //         for (int i = 0; i < difficulty.length; i++) {
        //             // 一个错误点,若有相同难度的工作,后添加的匹配会覆盖先添加的匹配
        //             // map.put(difficulty[i], profit[i]);
        //             map.put(difficulty[i], Math.max(map.getOrDefault(difficulty[i], 0), profit[i]));
        //         }
        //         Set<Integer> keySet = map.keySet();
        //         int ans = 0;
        //         for (int i = 0; i < worker.length; i++) {
        //             int pro = 0;
        //             for (int key : keySet) {
        //                 if (worker[i] < key) {
        //                     break;
        //                 } else {
        //                     pro = Math.max(pro, map.get(key));
        //                 }
        //             }
        //             ans += pro;
        //         }
        //         return ans;
        //     }
        // }

        int[] difficulty = new int[] { 66, 1, 28, 73, 53, 35, 45, 60, 100, 44, 59, 94, 27, 88, 7, 18, 83, 18, 72, 63 };
        int[] profit = new int[] { 66, 20, 84, 81, 56, 40, 37, 82, 53, 45, 43, 96, 67, 27, 12, 54, 98, 19, 47, 77 };
        int[] worker = new int[] { 61, 33, 68, 38, 63, 45, 1, 10, 53, 23, 66, 70, 14, 51, 94, 18, 28, 78, 100, 16 };
        System.out.println(new Solution().maxProfitAssignment(difficulty, profit, worker));
    }
}
