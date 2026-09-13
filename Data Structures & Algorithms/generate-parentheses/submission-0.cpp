class Solution {
public:

vector<string>res;

    void dfs(string curr,int open,int close,int n){
        if(curr.size()==2*n){
            res.push_back(curr);
            return;
        }

        if(open < n){
            curr.push_back('(');
            dfs(curr,open+1,close,n);
            curr.pop_back();
        }

        if(close<open){
            curr.push_back(')');
            dfs(curr,open,close+1,n);
            curr.pop_back();
        }



    }
    vector<string> generateParenthesis(int n) {
    string curr;
    dfs(curr,0,0,n);
    return res;        
    }


};
