#include <bits/stdc++.h>
#define ReadFile freopen("test.inp","r",stdin)
#define WriteFile freopen("test.out","w",stdout)
#define Fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

using namespace std;

bool Checkinput()
{
    // Number: ['A'..'Z'] or ['a'..'z'] or ['0'..'9']
    // Operator: + - * / ^
    // Input is always true
    return true;
}

int GetPriority(char ch)
{
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return -1;
}

string solve(string str){
    stack<char> st;
    string result;
    for(int i=0;i<str.length();i++)
    {
        char c = str[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result+=c;
        else
        {
            if(c == '(')
                st.push('(');
            else{
                if(c == ')')
                {
                    for(;st.top() != '(';st.pop())
                        result += st.top();
                    st.pop();
                }else{
                    for(;st.size() && GetPriority(c) <= GetPriority(st.top());st.pop())
                        result += st.top();
                    st.push(c);
                }
            }
        }
    }
    for(;st.size();st.pop())
        result += st.top();
    return result;
}

int main()
{
    Fast;
    ReadFile;
    WriteFile;
    string str;
    cin >> str;
    if(Checkinput() == false)
    {
        cout << "Error Input";
        return 0;
    }
    cout << solve(str);
    return 0;
}
