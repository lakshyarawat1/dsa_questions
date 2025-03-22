//  Problem Statement
// Determine if a 9 x 9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :

//     Each row must contain the digits 1 -
//     9 without repetition.Each column must contain the digits 1 - 9 without repetition.Each of the nine 3 x 3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.Note :

//     A Sudoku
//     board(partially filled) could be valid but is not necessarily solvable.Only the filled cells need to be validated according to the mentioned rules.Input : board =
//     [ [ "5", "3", ".", ".", "7", ".", ".", ".", "." ], [ "6", ".", ".", "1", "9", "5", ".", ".", "." ], [ ".", "9", "8", ".", ".", ".", ".", "6", "." ], [ "8", ".", ".", ".", "6", ".", ".", ".", "3" ], [ "4", ".", ".", "8", ".", "3", ".", ".", "1" ], [ "7", ".", ".", ".", "2", ".", ".", ".", "6" ], [ ".", "6", ".", ".", ".", ".", "2", "8", "." ], [ ".", ".", ".", "4", "1", "9", ".", ".", "5" ], [ ".", ".", ".", ".", "8", ".", ".", "7", "9" ] ] Output : true
// Explanation : We will use hastsets / unordered_sets to store the values of each row, column and box and check if the value is already present in the set or not.If it is present, we will return false, else we will insert the value in the set and continue the process.
// For grid, we will use the formula to get the box index : box_index = (row / 3) * 3 + col / 3 to get the box index.

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int N = 9;

        unordered_set<char> rows[N];
        unordered_set<char> cols[N];
        unordered_set<char> boxes[N];

        for (int r = 0; r < N; r++)
        {
            rows[r] = unordered_set<char>();
            cols[r] = unordered_set<char>();
            boxes[r] = unordered_set<char>();
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char val = board[i][j];

                if (val == '.')
                {
                    continue;
                }

                if (rows[i].find(val) != rows[i].end())
                {
                    return false;
                }
                rows[i].insert(val);

                if (cols[j].find(val) != cols[j].end())
                {
                    return false;
                }
                cols[j].insert(val);

                int idx = (i / 3) * 3 + j / 3;
                if (boxes[idx].find(val) != boxes[idx].end())
                {
                    return false;
                }
                boxes[idx].insert(val);
            }
        }
        return true;
    }
};