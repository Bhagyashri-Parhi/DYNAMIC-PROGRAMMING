Find the longest subsequence X of a string A which is a substring Y of a string B.

Input:
A = "ABCD" , B = "BACDBDCD"
Output:
3
Explanation:
The answer would be 3 as because "ACD"
is the longest subsequence of A which
is also a substring of B.
Example 2:

Input:
A = "A" , B = "A"
Output:
1
Explanation:
The answer would be 1 as because "A"
is the longest subsequence of A which
is also a substring of B. 

int getLongestSubsequence(string A, string B) {
        int m=A.size() ,n=B.size();
        int i,j;
        int dp[m+1][n+1];
        for(i=0;i<m+1;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        int mx=0;
        for(i=1;i<m+1;i++)
        {
            for(j=1;j<n+1;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    mx=max(mx,dp[i][j]);
                }
                else{
                dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return mx;
    }
};