// LeetCode 37 - Sudoku Solver
// Topic: Backtracking

class Solution {
public:
    bool isSafe(int row, int col, char target ,vector<vector<char>>& board){
        for(int i=0; i<9; i++){
          
            if(board[row][i] == target) return false;

            if(board[i][col] == target) return false;

            // 3x3 box check
            int stRow = 3*(row/3) + i/3;
            int stCol = 3*(col/3) + i%3;

            if(board[stRow][stCol] == target) return false;
        }
        return true;
    }

    bool backtracking(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){

                    for(char k='1'; k<='9'; k++){
                        if(isSafe(i, j, k, board)){
                            board[i][j] = k;

                            if(backtracking(board))
                                return true;

                            board[i][j] = '.';
                        }
                    }

                    return false; // important for backtracking
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
