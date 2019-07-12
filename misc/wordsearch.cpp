#include "../head.h"

bool searchNext(vector<vector<char>> &marks, vector<vector<char>> &board, string word, int y, int x, int pos)
{
    if (pos >= word.size())
    {
        return true;
    }

    if (y > 0 && 0 != marks[y - 1][x] && board[y - 1][x] == word[pos])
    {
        marks[y - 1][x] = 0;
        bool find = searchNext(marks, board, word, y - 1, x, pos + 1);
        if (find)
        {
            return true;
        }
        else
        {
            marks[y - 1][x] = 1;
        }
    }
    if (y < board.size() - 1 && 0 != marks[y + 1][x] && board[y + 1][x] == word[pos])
    {
        marks[y + 1][x] = 0;
        bool find = searchNext(marks, board, word, y + 1, x, pos + 1);
        if (find)
        {
            return true;
        }
        else
        {
            marks[y + 1][x] = 1;
        }
    }
    if (x > 0 && 0 != marks[y][x - 1] && board[y][x - 1] == word[pos])
    {
        marks[y][x - 1] = 0;
        bool find = searchNext(marks, board, word, y, x - 1, pos + 1);
        if (find)
        {
            return true;
        }
        else
        {
            marks[y][x - 1] = 1;
        }
    }
    if (x < board[y].size() - 1 && 0 != marks[y][x + 1] && board[y][x + 1] == word[pos])
    {
        marks[y][x + 1] = 0;
        bool find = searchNext(marks, board, word, y, x + 1, pos + 1);
        if (find)
        {
            return true;
        }
        else
        {
            marks[y][x + 1] = 1;
        }
    }

    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (word.size() <= 0)
    {
        return false;
    }
    int i, j;
    vector<vector<char>> marks = board;
    for (i = 0; i < board.size(); ++i)
    {
        for (j = 0; j < board[i].size(); ++j)
        {
            if (word[0] == board[i][j])
            {
                marks[i][j] = 0;
                bool res = searchNext(marks, board, word, i, j, 1);
                if (res)
                {
                    return res;
                }
                else
                {
                    marks[i][j] = 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    cout << exist(board, "ABCB") << endl;
    return 0;
}