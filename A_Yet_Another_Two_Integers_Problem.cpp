#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int t=0;t<test;t++)
    {
        int a, b;
        cin>>a>>b;
        if(a == b)
        {
            cout<<"0"<<endl;
        }
        else
        {
            int temp = abs(a-b);
            if(temp%10 == 0)
            {
                temp = temp/10;
            }
            else
            {
                temp = (temp/10) + 1;
            }
            cout<<temp<<endl;
        }
    }
}
