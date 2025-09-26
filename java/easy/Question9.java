package leetcode.easy;

public class Question9 {
    public static void main(String[] args) {
        class Solution {
            public boolean isPalindrome(int x) {
                if (x < 0) {
                    return false;
                }
                int reverse = 0, temp = x;
                while (x > 0) {
                    reverse *= 10;
                    reverse += x % 10;
                    x /= 10;
                }
                if (reverse == temp) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        System.out.println(new Solution().isPalindrome(1121));
    }
}