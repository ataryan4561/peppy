#include<bits/stdc++.h>
#include<string>
using namespace std;
int getnum(string s,unordered_map<char,int> &umap)
{
    string num="";
    for(int i=0; i<s.length(); i++)
    {
        num+=umap.at(s[i]);
    }
    return stoi(num);
}
void solution(string uni,int idx,unordered_map<char,int> &umap,vector<bool> &ans,string s1,string s2,string s3)
{
    if(idx==uni.length())
    {
        int num1=getnum(s1,umap);
        int num2=getnum(s2,umap);
        int num3=getnum(s3,umap);
        if(num1+num2==num3)
        {
            for(int i=0; i<26; i++)
            {
                char ch1=(char)('a'+i);
                if(umap.find(ch1)!=umap.end())
                {
                    cout<<ch1<<" - "<<umap.at(ch1)<<endl;
                }
            }
        }
    }
    char ch=uni[idx];
    for(int num=0; num<10; num++)
    {
        if(!ans[idx])
        {
            umap[ch]=num;
            ans[idx]=true;
            solution(uni,idx+1,umap,ans,s1,s2,s3);
            ans[idx]=false;
            umap[ch]=-1;
        }
    }
}
int main()
{
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    unordered_map<char,int> umap;
    string uni="";
    for(int i=0; i<s1.length(); i++)
    {
        if(umap.find(s1[i])==umap.end())
        {
            umap[s1[i]]=-1;
            // umap.insert({s1[i],-1});
            uni=uni+s1[i];
        }
    }
    for(int i=0; i<s2.length(); i++)
    {
        if(umap.find(s2[i])==umap.end())
        {
            umap[s2[i]]=-1;
            // umap.insert({s2[i],-1});
            uni=uni+s2[i];
        }
    }
    for(int i=0; i<s3.length(); i++)
    {
        if(umap.find(s3[i])==umap.end())
        {
            umap[s3[i]]=-1;
            // umap.insert({s3[i],-1});
            uni=uni+s3[i];
        }
    }
    vector<bool> ans(10,false);
    solution(uni,0,umap,ans,s1,s2,s3);
}