class Solution {
public:
    vector<int>arr;
    vector<vector<string>>ans;
    void helper(int row, int n) {
        if(row==n){
            vector<string>temp(n,string(n, '.')); 
            for(int i=0;i<n;i++) {
                temp[i][arr[i]]='Q'; 
            }
            ans.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            if(issafe(row,col,n)){
                arr[row]=col;
                helper(row+1,n);
            }
        }
    }

    bool issafe(int row,int col,int n) {
        for(int i=0;i<row;i++) {
            if(arr[i]==col||abs(row-i)==abs(col-arr[i]))
                return false;
        }
        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        arr=vector<int>(n,-1);
        ans=vector<vector<string>>();
        helper(0,n);
        return ans;
    }
};
