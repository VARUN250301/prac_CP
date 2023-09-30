//top down memoization solution
int rec(vector<vector<int>> &points, int last, int ind, vector<vector<int>> &dp){
    if(ind == 0){
        int k = 0;
        for(int j = 0; j < 3; j++){
            if(j != last){
                k = max(k, points[ind][j]);
            }
        }
        return dp[ind][last] = k;
    }
    if(dp[ind][last] != -1) return dp[ind][last];
    int maxi = 0;
    for(int i = 0; i < 3; i++){
        if(i != last){
            int val = points[ind][i] + rec(points, i, ind - 1, dp);
            maxi = max(maxi, val);
        }
    }
    return dp[ind][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int ans = rec(points, 3, n - 1, dp);
    return ans;
}