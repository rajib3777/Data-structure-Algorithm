#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool areSame(stack<int> S, queue<int> Q) {
    queue<int> tempQ = Q; // Create a temporary queue to avoid modifying the original queue

    while (!S.empty()) {
        if (S.top() != tempQ.front()) {
            return false;
        }
        S.pop();
        tempQ.pop();
    }

    return S.empty() && tempQ.empty();
}

int main() {
    int N, M;
    cin >> N >> M;

    stack<int> S;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        S.push(value);
    }

    queue<int> Q;
    for (int i = 0; i < M; ++i) {
        int value;
        cin >> value;
        Q.push(value);
    }

    if (areSame(S, Q)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}