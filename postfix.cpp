#include <iostream>
#include <string>
using namespace std;

class stack
{
    char stk[50];
    int t;

public:
    stack()
    {
        t = -1;
    }
    int priority(char c)
    {
        if (c == '^')
        {
            return 3;
        }
        else if (c == '*' || c == '/')
        {
            return 2;
        }
        else if (c == '+' || c == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    void push(char c)
    {
        t++;
        stk[t] = c;
    }
    void pop(char c)
    {
        c = stk[t];
        t--;
    }
    void infix_to_postfix(string s)
    {
        int i;
        string r;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9))
            {
                r += c;
            }
            else if (c == '(')
            {
                push(c);
            }
            else if (c == ')')
            {
                while (t != '(')
                {
                    r += stk[t];
                    pop(c);
                    break;
                }
                pop(c);
            }
            else
            {
                while (t != -1 && priority(s[i]) <= priority(stk[t]))
                {
                    r += stk[t];
                    pop(c);
                }
                push(c);
            }
        }

        for (int i = t; i != -1; i--)
        {
            char c = s[i];
            r += stk[i];
            pop(c);
        }
        cout << "Postfix expression is : \n";
        cout << r;
    }
};

int main()
{
    stack S;

    string s;
    cout << "Enter your expression : \n";
    cin >> s;

    S.infix_to_postfix(s);

    return 0;
}

//Enter your expression : 
// (a+b)*(c-d)
// Postfix expression is : 
// abcd-+