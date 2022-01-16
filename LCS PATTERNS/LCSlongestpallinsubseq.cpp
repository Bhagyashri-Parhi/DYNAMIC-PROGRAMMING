Given a String, find the longest palindromic subsequence.


Example 1:

Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.
Example 2:

Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.

int longestPalinSubseq(string a) {
        //code here
        int i,j;
        string b=string(a.rbegin(),a.rend());
        int dp[a.length()+1][a.length()+1];
        for(i=0;i<a.length()+1;i++)
        {
            dp[i][0]=0;
        }
        for(i=0;i<a.length()+1;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<a.length()+1;i++)
        {
            for(j=1;j<a.length()+1;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    return dp[a.length()][a.length()];
    }