class Solution {
public:
    int count = 0;
    bitset<30> cl, d1,d2;
    void Solve(int row,vector<string>& a,int n) {
        if(row == n) {
            count++;
            return;
        }

        for(int col = 0;col < n;col++) {
            if(!cl[col] && !d1[row+col] && !d2[row - col + n - 1]) {
                a[row][col] = 'Q';
                cl[col] = d1[row+col] = d2[row - col + n - 1] = 1;
                Solve(row+1,a,n);
                cl[col] = d1[row+col] = d2[row - col + n - 1] = 0;
                a[row][col] = '.';
            }
        } 
    }
    int totalNQueens(int n) {
        // vector<vector<string>> ans;
        // int count;
        vector<string> a(n, string(n, '.'));

        Solve(0, a,n);
        return count;
    }
};