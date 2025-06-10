#include <bits/stdc++.h>
using namespace std;

int func(string str, int k) {
    unordered_map<char, int> freq;
    for (char ch : str) freq[ch]++;

    priority_queue<int> pq;
    for (auto &entry : freq) pq.push(entry.second);

    while (k-- && !pq.empty()) {
        int top = pq.top();
        pq.pop();
        if (top > 1) pq.push(top - 1);
    }

    int sum = 0;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        sum += x * x;
    }

    return sum;
}

int main() {
    string str;
    cin >> str;
    int k;
    cin >> k;
    cout << func(str, k);
}
