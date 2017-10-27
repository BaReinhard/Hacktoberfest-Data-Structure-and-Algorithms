#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX = (1<<30)-1;

template <typename T>
class stack
{ 
    public:
    T st[100];
    int poz;

    stack()
    {
        this->poz = 0;
    }

    void push(T c)
    {
        poz++;
        st[poz]=c;
    }

    void pop()
    {
        poz --;
    }

    T top()
    {
        return st[poz];
    }

    int isEmpty()
    {
        return !poz;
    }
};

long long putere(long long b,int p)
{
    if(b>MAX)
        return b;
    if(p==0)
        return 1;
    if(b==1)
        return 1;
    if(b==0)
        return 0;
    if(p==1)
        return b;
    if(p%2==0)
        return putere(b*b,p/2);
    else
        return b*putere(b*b,(p-1)/2);
}

int char_to_int(char *s)
{
    int ret=0;

    while(isdigit(*s))
        ret=ret*10+*(s++)-'0';

    return ret;
}

int main()
{
    stack <char> st;
   
    ifstream in("gorzko.in");
    ofstream out("gorzko.out");

    char c;
    int cf=1;
    
    cout<<"Forma poloneza inversa:\n";
    
    while(in>>c)
    {
        if( '0' <= c && c <= '9' )
        {
            if(cf == 0)   
            { 
                out<<" "<<c;
                cout<<" "<<c;
            }
            
            else
            {
                out<<c;
                cout<<c;
            }
            
            cf=1;
        }
        else
        {
            cf=0;
            if(c == '(')
            
                st.push(c);
            else
                if(c == ')')
                {
                    while(st.top() != '(' && !st.isEmpty())
                    {
                        out<<" "<<st.top();
                        cout<<" "<<st.top();
                        st.pop();
                    }
                    if(st.top() != '(')
                    {
                        cout<<"Parantezare gresita! CUMPLIT!!!"<<"\n";
                        return 0;
                    }
                    else
                        st.pop();//scot si ( 
                }
                else
                    if(c == '+' || c == '-')
                    {
                        while(st.top() != '(' && !st.isEmpty())
                        {
                            out<<" "<<st.top();
                            cout<<" "<<st.top(); 
                            st.pop();
                        }
                        st.push(c);
                    }
                    else
                        if(c == '*' || c == '/')
                        {
                            while(st.top() != '(' && !st.isEmpty() && st.top() != '+' && st.top() != '-')
                            {
                                out<<" "<<st.top();
                                cout<<" "<<st.top();
                                st.pop();
                            }
                            st.push(c);
                        }
                    else
                        st.push(c);
        }
    }

    while(!st.isEmpty())
    {
        out<<" "<<st.top();
        cout<<" "<<st.top();
        if(st.top() == '(')
        {
            cout<<"Parantezare gresita!! CUMPLIT!! ~ final"<<"\n";
            return 0;
        }
        st.pop();
    }


    cout<<"\n";
    
    in.close();
    out.close();

    freopen("gorzko.out","r",stdin);

    char s[100];
    cin.getline(s,100);
    
    stack <long long> st2;

    long long a,b;
    char op;

    char *p;
    p = strtok(s," ");
    while(p != NULL)
    {
        if('0' <= p[0] && p[0] <= '9')
            st2.push(char_to_int(p));
        else
        {
            if(st2.isEmpty())
            {
                cout<<"Forma postfixata nu e corecta\n";
                return 0;
            }
            a = st2.top();
            st2.pop();

            if(st2.isEmpty())
            {
                cout<<"Forma postfixata nu e corecta\n";
                return 0;
            }
            b = st2.top();
            st2.pop();
            
            op = p[0];
            long long rez;
            if(op == '+')
                rez=b+a;
            else
                if(op == '-')
                    rez=b-a;
                else
                    if(op == '*')
                        rez=a*b;
                    else
                        if(op == '/')
                            rez=b/a;
                        else
                            if(op == '^')
                                rez=putere(b,a);
            st2.push(rez);
        }

        p = strtok(NULL," ");
    }
    
    cout<<st2.top()<<"\n";
    st2.pop();
    if(!st2.isEmpty())
        cout<<"Forma postfixata nu e corecta ~ final\n";

    return 0;
}
