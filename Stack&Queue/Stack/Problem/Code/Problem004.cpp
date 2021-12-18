#include <iostream>
#include <stack>
#define ReadFile freopen("test.inp","r",stdin)
#define WriteFile freopen("test.out","w",stdout)

const int oo = 1e9;
using namespace std;

stack<int> st1,st2,st3;

inline void down()
{
    cout << '\n';
}

int Pop1()
{
    if(st1.empty())
        return oo;
    int value = st1.top();
    st1.pop();
    return value;
}

int Pop2()
{
    if(st2.empty())
        return oo;
    int value = st2.top();
    st2.pop();
    return value;
}

int Pop3()
{
    if(st3.empty())
        return oo;
    int value = st3.top();
    st3.pop();
    return value;
}

int TopOfStack()
{
    if(st1.size() && st1.top() == 1)
        return 1;
    else
    {
        if(st2.size() && st2.top() == 1)
            return 2;
        else
        {
            if(st3.size() && st3.top() == 1)
                return 3;
        }
    }
}

void Display()
{
    stack<int> st(st1);
    cout << "Tower1-> " << "\t";
    for(;st.size();st.pop())
        cout << st.top() << "\t";
    down();
    // --------
    stack<int> St(st2);
    cout << "Tower2-> " << "\t";
    for(;St.size();St.pop())
        cout << St.top() << "\t";
    down();
    // --------
    stack<int> ST(st3);
    cout << "Tower3-> " << "\t";
    for(;ST.size();ST.pop())
        cout << ST.top() << "\t";
    down();
    down();
}

void Solve(int Step)
{
    for(int step = 0; step < Step; ++step)
    {
        // Print step by step
        Display();
        // the position of disk 1
        int PosOfDisk1 = TopOfStack(); 
        if(step%2 == 0)
        { // Move 1 Disk
            if(PosOfDisk1 ==  1)
            {
                st3.push(Pop1());
            }else
            {
                if(PosOfDisk1 == 2)
                {
                    st1.push(Pop2());
                }else
                {
                    if(PosOfDisk1 == 3)
                        st2.push(Pop3());
                }
            }
        }else
        { 
            if(PosOfDisk1 == 1)
            {
                int CurrDisk1 = Pop2();
                int CurrDisk2 = Pop3();
                if(CurrDisk1 < CurrDisk2 && CurrDisk2 != oo)
                {
                    st3.push(CurrDisk2);
                    st3.push(CurrDisk1);
                }else
                {
                    if(CurrDisk1 > CurrDisk2 && CurrDisk1 != oo)
                    {
                        st2.push(CurrDisk1);
                        st2.push(CurrDisk2);
                    }else
                    {
                        if(CurrDisk1 == oo)
                            st2.push(CurrDisk2);
                        else
                        {
                            if(CurrDisk2 == oo)
                                st3.push(CurrDisk1);
                        }
                    }
                }
            }else
            {
                if(PosOfDisk1 == 2)
                {
                    int CurrDisk1 = Pop1();
                    int CurrDisk2 = Pop3();
                    if(CurrDisk1<CurrDisk2 && CurrDisk2 != oo)
                    {
                        st3.push(CurrDisk2);
                        st3.push(CurrDisk1);
                    }else
                    {
                        if(CurrDisk1>CurrDisk2 && CurrDisk1 != oo)
                        {
                            st1.push(CurrDisk1);
                            st1.push(CurrDisk2);
                        }else
                        {
                            if(CurrDisk1 == oo)
                                st1.push(CurrDisk2);
                            else
                            {
                                if(CurrDisk2 == oo)
                                    st3.push(CurrDisk1);
                            }
                        }
                    }
                }else
                {
                    if(PosOfDisk1 == 3)
                    {
                        int CurrDisk1 = Pop1();
                        int CurrDisk2 = Pop2();
                        if(CurrDisk1<CurrDisk2 && CurrDisk2!=oo)
                        {
                            st2.push(CurrDisk2);
                            st2.push(CurrDisk1);
                        }else
                        {
                            if(CurrDisk1>CurrDisk2 && CurrDisk1!=oo)
                            {
                                st1.push(CurrDisk1);
                                st1.push(CurrDisk2);
                            }else
                            {
                                if(CurrDisk1 == oo)
                                    st1.push(CurrDisk2);
                                else
                                {
                                    if(CurrDisk2 == oo)
                                        st2.push(CurrDisk1);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    ReadFile;
    WriteFile;
    int n; // Count of Disk
    cin >> n;
    for(int i=0;i<n;++i)
        st1.push(n-i);
    int step = 2 << (n-1); // Step to Solve this Problem
    Solve(step);
	return 0;
}
