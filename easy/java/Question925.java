package leetcode.easy;

public class Question925 {
    public static void main(String[] args) {
        class Solution {
            public boolean isLongPressedName(String name, String typed) {
                int i = 0, j = 0;
                while (j < typed.length()) {
                    if (i < name.length() && name.charAt(i) == typed.charAt(j)) {
                        i++;
                        j++;
                    } else if (j > 0 && typed.charAt(j - 1) == typed.charAt(j)) {
                        j++;
                    } else {
                        return false;
                    }
                }
                return i == name.length();
            }
        }

        System.out.println(new Solution().isLongPressedName("saeed", "ssaaedd"));
    }
}
