#include<bits/stdc++.h>
using namespace std;
int solution(vector<string> &words,vector<int> &frew,vector<int> &freq,int idx)
{
    if(idx==words.size())
    {
        return 0;
    }
    int sno = solution(words,frew,freq,idx+1);
    int swod=0;
    string word = words[idx];
    bool flag=true;
    for(int i=0; i<word.length(); i++)
    {
        char ch=word[i];
        if(frew[ch-'a']==0)
        {
            flag=false;
            break;
        }
        frew[ch-'a']--;
        swod+=freq[ch-'a'];
    }
    int syes=0;
    if(flag)
    {
        syes=swod+solution(words,frew,freq,idx+1);
    }
    for(int i=0; i<word.length(); i++)
    {
        char ch=word[i];
        frew[ch-'a']++;
    }
    return max(syes,sno);
}
int main()
{
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0; i<n; i++)
    {
        cin>>words[i];
    }
    int fu;
    cin>>fu;
    vector<char> ff(fu);
    vector<int> frew(26);
    for(int i=0; i<fu; i++)
    {
        cin>>ff[i];
    }
    for(auto e: ff)
    {
        frew[e-'a']++;
    }
    vector<int> freq(26,0);
    for(int i=0; i<26; i++)
    {
        cin>>freq[i];
    }
    cout<<solution(words,frew,freq,0);
}