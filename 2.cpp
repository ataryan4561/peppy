#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<bool>> &board,int row,vector<bool> &cols,vector<bool> &ndiag,vector<bool> &rdiag,string asf)
{
    if(row==board.size())
    {
        cout<<asf<<"\n";
        return ;
    }
    for(int col=0; col<board[0].size(); col++)
    {
        if(cols[col]==false && ndiag[row+col]==false && rdiag[row -col + board.size()-1]==false)
        {
            board[row][col]=true;
            cols[col]=true;
            ndiag[row+col]=true;
            rdiag[row-col+board.size()-1]=true;
            solve(board,row+1,cols,ndiag,rdiag,asf+to_string(row)+"_"+to_string(col)+" ");
            board[row][col]=false;
            cols[col]=false;
            ndiag[row+col]=false;
            rdiag[row-col+board.size()-1]=false;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<bool>> board(n,vector<bool> (n,false));
    vector<bool> cols(n,false);
    vector<bool> ndiag(2*n-1,false);
    vector<bool> rdiag(2*n-1,false);
    solve(board,0,cols,ndiag,rdiag,"");
}