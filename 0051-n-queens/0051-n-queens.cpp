class Solution {
public:
    bool isValid(int i,int j,vector<string>& ds,int n) {
        //Check Col
        int ti = i,tj = j;
        while(ti >= 0) {
            if(ds[ti][tj] == 'Q') {
                return false;
            }
            ti--;
        }

        //Check left Di
        ti = i,tj = j;
        while(ti >= 0 && tj >= 0) {
            if(ds[ti][tj] == 'Q') {
                return false;
            }
            ti--;
            tj--;
        }

        //check right Di
        ti = i,tj = j;
        while(ti >= 0 && tj <= n-1) {
            if(ds[ti][tj] == 'Q') {
                return false;
            }
            ti--;
            tj++;
        }

        return true;
    }
    void Solve(int row,vector<vector<string>>& ds,vector<string>& A,int n) {
        //base case
        if(row == n) {
            ds.push_back(A);
            return;
        }

        //check the each row
        for(int col = 0;col < n;col++) {
            if(isValid(row,col,A,n)) {
                A[row][col] = 'Q';
                Solve(row+1,ds,A,n);
                A[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ds;
        vector<string> A;
        for(int i = 0;i < n;i++) {
            string s;
            for(int j = 0;j < n;j++) {
                s.push_back('.');
            }
            A.push_back(s);
        }

        Solve(0,ds,A,n);
        return ds;
        
    }
};