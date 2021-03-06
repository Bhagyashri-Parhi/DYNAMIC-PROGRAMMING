Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string. The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.

Example 1:

Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
Example 2:

Input:
str = "aab"
Output: 1
Explanation: 
The longest reapting subsequenece is "a".

int LongestRepeatingSubsequence(string a){
int m=a.size();
		    int n=a.size();
		    string b=a;
		    int i,j;
		    for(i=0;i<m;i++)
		    {
		        for(j=0;j<n;j++)
		        {
		            if(i==0 || j==0)
		            return 0;
		        }
		    }
		    for(i=1;i<m;i++)
		    {
		        for(j=1;j<n;j++)
		        {
		            if(a[i-1]==b[j-1]   &&  i!=j)
		            {
		                dp[i][j]=1+dp[i][j];
		            }
		            else
		            {
		                dp[i][j]=max(dp[i][j-1],dp[j-1][i]);
		            }
		        }
		        
		    }
		    return dp[m][n];
		}