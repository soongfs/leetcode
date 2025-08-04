#include <string>
#include <vector>

using namespace std;

class BrowserHistory {
    vector<string> history;
    int cur = 0;

public:
    BrowserHistory(string homepage) : history{homepage} {}

    void visit(string url) {
        cur++;
        history.resize(cur);
        history.push_back(url);
        return;
    }

    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }

    string forward(int steps) {
        cur = min((int)history.size() - 1, cur + steps);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */