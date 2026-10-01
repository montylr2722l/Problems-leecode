class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n){
        // check for column
        for(int i = 0; i<row; i++){
            if(board[i][col] =='Q')
            return false;
        }

        // check for left diagonal
        
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q')
            return false;
        }

        // check for right diagonal

        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] =='Q')
            return false;
        }
        return true;
    }

    void Solve(int row , vector<string>& board, vector<vector<string>>& ans, int n){
        if(row ==n){
        ans.push_back(board);
        return;
    }
    for(int col=0; col<n; col++){
        if(isSafe(board ,row, col, n )){
            board[row][col] ='Q';
            Solve(row+1, board, ans, n);
            board[row][col]='.';
            
        }
    }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n,'.'));
        Solve(0, board, ans, n);
        return ans;
        
    }
};