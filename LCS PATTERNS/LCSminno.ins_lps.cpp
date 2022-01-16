Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd


Example 1:

Input: str = "abcd"
Output: 3
Explanation: Inserted character marked
with bold characters in dcbabcd
Example 2:

Input: str = "aa"
Output: 0
Explanation:"aa" is already a palindrome.

int dp[1001][1001];
class Solution{
  public:
    int countMin(string a){
    string b=string(a.rbegin(),a.rend());
    int m=a.size();
    int n=a.size();
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
};