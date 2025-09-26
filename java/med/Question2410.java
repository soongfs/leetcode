package leetcode.med;

import java.util.Arrays;

public class Question2410 {
    public static void main(String[] args) {
        class Solution {
            public int matchPlayersAndTrainers(int[] players, int[] trainers) {
                Arrays.sort(players);
                Arrays.sort(trainers);
                int i = 0, j = 0, ans = 0;
                while (i < players.length && j < trainers.length) {
                    if (players[i] <= trainers[j]) {
                        ans++;
                        i++;
                        j++;
                    } else {
                        j++;
                    }
                }
                return ans;
            }
        }

        System.out.println(new Solution().matchPlayersAndTrainers(new int[] { 1, 1, 1 }, new int[] { 10 }));
    }
}