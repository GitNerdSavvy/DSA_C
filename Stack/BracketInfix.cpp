#include <bits/stdc++.h>
using namespace std;

int pr(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int solve(int a, int b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    return 0;
}

int calculate(string s)
{
    stack<int> val;
    stack<char> op;

    for (int i = 0; i < s.length(); i++)
    {
        // if (isdigit(s[i])) {
        //     val.push(s[i] - '0');
        // }
        if (isspace(s[i]))
            continue;

        if (isdigit(s[i]))
        {
            int num = 0;
            while (i < s.length() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            val.push(num);
            i--;
        }
        else if (s[i] == '(')
        {
            op.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                int b = val.top();
                val.pop();
                int a = val.top();
                val.pop();
                char ch = op.top();
                op.pop();
                val.push(solve(a, b, ch));
            }
            if (!op.empty() && op.top() == '(')
                op.pop();
        }
        else
        {
            while (!op.empty() && pr(op.top()) >= pr(s[i]))
            {
                int b = val.top();
                val.pop();
                int a = val.top();
                val.pop();
                char ch = op.top();
                op.pop();
                val.push(solve(a, b, ch));
            }
            op.push(s[i]);
        }
    }

    while (!op.empty())
    {
        int b = val.top();
        val.pop();
        int a = val.top();
        val.pop();
        char ch = op.top();
        op.pop();
        val.push(solve(a, b, ch));
    }

    return val.top();
}

int main()
{
    string s = "1+(4*5/2-3)+6+8";
    cout << calculate(s) << endl;

    cout << (1 + (4 * 5 / 2 - 3) + 6 + 8) << endl;
}
