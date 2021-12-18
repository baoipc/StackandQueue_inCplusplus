#include <iostream>
#include <stack>
#define ReadFile freopen("test.inp","r",stdin)
#define WriteFile freopen("test.out","w",stdout)

using namespace std;

inline bool CheckInput(int number, int base)
{
    // number want to convert
    // type of number you want to convert
    return true;
}

char Display(int number, int base)
{
    if(base == 2 || base == 8)
        return (number+'0');
    // base  = 16
    if(number < 10)
        return (number+'0');
    else{
        switch(number)
        {
            case 10: 
                return 'A';
                break;
            case 11:
                return 'B';
                break;
            case 12:
                return 'C';
                break;
            case 13:
                return 'D';
                break;
            case 14:
                return 'E';
                break;
            // 15
            default: 
                return 'F';
                break;
        }

    }
}

void Solve(int n, int base)
{
    stack<int> st;
    for(;n>0;n/=base)
        st.push(n%base);
    for(;st.size();st.pop())
        cout << Display(st.top(),base);
}

int main()
{
    ReadFile;
    WriteFile;
    int number;
    int base;
    cin >> number >> base;
    if(CheckInput(number,base) == false)
        return 0;
    Solve(number,base);
    return 0;
}