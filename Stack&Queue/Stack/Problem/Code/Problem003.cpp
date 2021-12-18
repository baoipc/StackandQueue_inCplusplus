#include <iostream>
#include <stack>
#define ReadFile freopen("test.inp","r",stdin)
#define WriteFile freopen("test.out","w",stdout)

using namespace std;

bool CheckInput(string Input)
{
    // operator: + - * /
    // Input is a always true
    return true;
}

int calculate(int a,int b,char op)
{
    switch(op)
    {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}

int Priority(char op)
{
    if(op == '+' || op =='-')
        return 1;
    if(op =='*' || op == '/')
        return 2;
    return 0;
}

int Solve(string Input)
{
    stack<char> Operators;
    stack<int> values;
    for(int i=0;i<Input.length();++i)
    {
        if(Input[i] == ' ')
            continue;
        else if(Input[i] == '(')
            Operators.push(Input[i]);
        else{
            if(isdigit(Input[i]))
            {
                int value = 0;
                for(;i<Input.length() && isdigit(Input[i]);i++)
                    value=value*10+(Input[i]-'0');
                values.push(value);
                i--;
            }else{
                if(Input[i] == ')')
                {
                    for(int a,b;Operators.top() != '(' && Operators.size();Operators.pop())
                    {

                        b = values.top();
                        values.pop();

                        a = values.top();
                        values.pop();

                        values.push(calculate(a,b,Operators.top()));
                    }
                    if(Operators.size())
                        Operators.pop();
                }else{ // Operator: + - * /
                    while(Operators.size() && Priority(Operators.top()) >= Priority(Input[i]))
                    {
                        int b = values.top();
                        values.pop();

                        int a = values.top();
                        values.pop();

                        values.push(calculate(a,b,Operators.top()));
                        Operators.pop();
                    }
                    Operators.push(Input[i]);
                }
            }
        }
    }

    for(int a,b;Operators.size();Operators.pop())
    {
        b = values.top();
        values.pop();

        a = values.top();
        values.pop();

        values.push(calculate(a,b,Operators.top()));
    }
    return values.top();
}

int main()
{
    ReadFile;
    WriteFile;
    string str;
    getline(cin,str);
    if(CheckInput(str) == false)
        return 0;
    cout << Solve(str);
    return 0;
}
