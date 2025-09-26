#include <bits/stdc++.h>

int main() {
    int p = 2;
    std::cout << &p << std::endl;
}

void func(int *p) {
    int q = *p;
}

int func_2(int &p) {
    int q = p;
}
