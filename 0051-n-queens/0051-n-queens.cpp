class Solution {
public:
    // bool isValid(int i,int j,vector<string>& ds,int n) {
    //     //Check Col
    //     int ti = i,tj = j;
    //     while(ti >= 0) {
    //         if(ds[ti][tj] == 'Q') {
    //             return false;
    //         }
    //         ti--;
    //     }

    //     //Check left Di
    //     ti = i,tj = j;
    //     while(ti >= 0 && tj >= 0) {
    //         if(ds[ti][tj] == 'Q') {
    //             return false;
    //         }
    //         ti--;
    //         tj--;
    //     }

    //     //check right Di
    //     ti = i,tj = j;
    //     while(ti >= 0 && tj <= n-1) {
    //         if(ds[ti][tj] == 'Q') {
    //             return false;
    //         }
    //         ti--;
    //         tj++;
    //     }

    //     return true;
    // }

    //BitSet
    bitset<30> cl,d1,d2;
    void Solve(int row,vector<vector<string>>& ds,vector<string>& A,int n) {
        //base case
        if(row == n) {
            ds.push_back(A);
            return;
        }

        //check the each row
        for(int col = 0;col < n;col++) {
            if(!cl[col] && !d1[row + col] && !d2[row - col + n + 1]) {
                A[row][col] = 'Q';
                cl[col] = d1[row+col] = d2[row-col+n+1] = 1;
                Solve(row+1,ds,A,n);
                cl[col] = d1[row+col] = d2[row-col+n+1] = 0;
                A[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ds;
        vector<string> A(n , string(n,'.'));
        // for(int i = 0;i < n;i++) {
        //     string s;
        //     for(int j = 0;j < n;j++) {
        //         s.push_back('.');
        //     }
        //     A.push_back(s);
        // }

        Solve(0,ds,A,n);
        return ds;
        
    }
};