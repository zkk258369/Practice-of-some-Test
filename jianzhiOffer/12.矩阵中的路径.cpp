#include<bits/stdc++.h>
using namespace std;

class Solution1  //遍历  加了visit表
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        row = board.size();
        col = board[0].size();
        
        bool res = false;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool>> vis(row, vector<bool>(col, false));
                    res = dfs(board, vis, word, 0, i, j);
                    if(res) return res;
                }
            }
        }
        return res;
    }
private:
    int row; int col;
    bool dfs(const vector<vector<char>>& board, 
            vector<vector<bool>>& vis, 
            const string& word, int index, int x, int y)
    {
        vis[x][y] = true;
        if(index == word.size()-1)
        {
            if(word[index] == board[x][y]) return true;
            else return false;
        }
        
        //up
        if(x-1 >= 0 && x-1 < row && vis[x-1][y] == false)
        {
            if(board[x-1][y] == word[index+1])
            {
                bool res = dfs(board, vis, word, index+1, x-1, y);
                if(res) return res;
                vis[x-1][y] = false;
            }
        }
        //down
        if(x+1 >= 0 && x+1 < row && vis[x+1][y] == false)
        {
            if(board[x+1][y] == word[index+1])
            {
                bool res = dfs(board, vis, word, index+1, x+1, y);
                if(res) return res;
                vis[x+1][y] = false;
            }
        }
        //left
        if(y-1 >= 0 && y-1 < col && vis[x][y-1] == false)
        {
            if(board[x][y-1] == word[index+1])
            {
                bool res = dfs(board, vis, word, index+1, x, y-1);
                if(res) return res;
                vis[x][y-1] = false;
            }
        }
        //right
        if(y+1 >= 0 && y+1 < col && vis[x][y+1] == false)
        {
            if(board[x][y+1] == word[index+1])
            {
                bool res = dfs(board, vis, word, index+1, x, y+1);
                if(res) return res;
                vis[x][y+1] = false; 
            }
        }
        return false;
    }
};

class Solution2
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        row = board.size();
        col = board[0].size();
        bool res = false;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(board[i][j] == word[0])
                {
                    res = dfs(board, word, 0, i, j);
                    if(res) return res;
                }
            }
        }
        return res;
    }
private:
    int row;
    int col;
    bool dfs(vector<vector<char>>& board, 
            string& word, int index, int x, int y)
    {
        if(x >= row || x < 0 ||
            y >= col || y < 0 ||
            board[x][y] != word[index]) return false;

        if(index == word.size()-1) return true;
        char tmp = board[x][y];
        board[x][y] = '/';
        bool res = dfs(board, word, index+1, x+1, y) || dfs(board, word, index+1, x-1, y) ||
                    dfs(board, word, index+1, x, y+1) || dfs(board, word, index+1, x, y-1);
        board[x][y] = tmp;
        return res;
    }
};