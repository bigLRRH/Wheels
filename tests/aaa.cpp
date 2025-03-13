#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}

void solve()
{
    string s;
    cin >> s;
    string t = "";
    int p = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            // s[i] is a digit
            int x = s[i] - '0';
            if (p == 0)
            {
                p = x;
            }
            else
            {
                p *= 10;
                p += x;
            }
        }
        else
        {
            // 将字符串t左移p位
            if (t.length() != 0)
            {
                p %= t.length();
                string temp = t.substr(p) + t.substr(0, p);
                t = temp;
            }
            p = 0;
            if (t[i] == 'R')
            {
                // 反转字符串
                reverse(t.begin(), t.end());
            }
            else
            {
                // 直接添加到字符串末尾
                t = t + s[i];
            }
        }
    }
    cout << t << endl;
}