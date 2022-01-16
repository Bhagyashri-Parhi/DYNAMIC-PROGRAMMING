Given a string 'str' of size ‘n’. The task is to remove or delete the minimum number of characters from the string so that the resultant string is a palindrome. Find the minimum numbers of characters we need to remove.
Note: The order of characters should be maintained.

Example 1:

Input: n = 7, str = "aebcbda"

Output: 2
Explanation: We'll remove 'e' and
'd' and the string become "abcba".
â€‹Example 2:

Input: n = 3, str = "aba"
Output: 0
Explanation: We don't remove any
character.

int dp[1001][1001];
int minDeletions(string a, int n) { 
    //complete the function here 
    string b=string(a.rbegin(),a.rend());
    int m=n;
    int i,j;
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
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][m];
} 