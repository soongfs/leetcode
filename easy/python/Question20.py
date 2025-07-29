class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if ch == "(" or ch == "[" or ch == "{":
                stack.append(ch)
            elif ch == ")" or ch == "]" or ch == "}":
                if len(stack) == 0:
                    return False
                else:
                    if stack[-1] == "(" and ch == ")":
                        stack.pop()
                    elif stack[-1] == "[" and ch == "]":
                        stack.pop()
                    elif stack[-1] == "{" and ch == "}":
                        stack.pop()
                    else:
                        return False
            else:
                return False
        if len(stack) == 0:
            return True
        else:
            return False


if __name__ == "__main__":
    print(Solution().isValid("([])[{}]{}(())"))
