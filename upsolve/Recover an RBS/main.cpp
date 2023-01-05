#include <bits/stdc++.h>
using namespace std;


int main() {
int t;
cin >> t;

while(t--)

{
    string s;
    cin >> s;

    s[0]='(';
    s[s.size()-1]=')';
    vector<int> ques;
    string right,left;
    int open=0;
    for(int i=0;i<s.size();i++)
    {
        left+='?';
        right+='?';
    }

    for(int i=0;i<s.size();i++)
    {left[i]=s[i];
        if(s[i]=='(')
        {
            open++;

        }
        else if(s[i]==')')
        {
            if(open>0)
                open--;
            else if(open ==0)
            {       left[ques[0]]='(';
                    ques.erase(ques.begin());

            }

        }
        else
            ques.push_back(i);
    }
    if(open>0)
    {
        while(open--)
        {
            left[ques[ques.size()-1]]=')';
            ques.pop_back();
        }
    }
    for(int i=0;i<ques.size();i++)
    {
        if(i%2)
            left[ques[i]]=')';
        else
            left[ques[i]]='(';
    }
    ques.clear();
    open=0;
    for(int i=s.size()-1;i>=0;i--)
    {        right[i]=s[i];
        if(s[i]==')')
            open++;
        else if(s[i]=='(')
        {
            if(open>0)
                open--;
            else if(open ==0)
            {if(ques.size())
                {
                    right[ques[0]]=')';
                    ques.erase(ques.begin());
                }
            }
        }
        if(s[i]=='?')
            ques.push_back(i);
    }if(open>0)
    {
        while(open--)
        {
            right[ques[0]]='(';
            ques.erase(ques.begin());
        }
    }
//cout << ques.size()<<endl;
    for(int i=0;i<ques.size()/2;i++)
    {
       right[ques[ques.size()-1-i]]='(';
    //   cout << right<<endl;
       right[ques[i]]=')';
    }


    if(left==right)
        cout <<"YES"<<endl;
    else cout <<"NO"<<endl;

}

    return 0;
}
