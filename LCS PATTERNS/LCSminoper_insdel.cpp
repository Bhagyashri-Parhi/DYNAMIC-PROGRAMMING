Q.Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Example 1:

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.

Example 2:

Input : str1 = "geeksforgeeks"
str2 = "geeks"
Output: 8
Explanation: 8 deletions

int minOperations(string str1, string str2) 
	{ 
	    int i,j;
	    int n=str1.size();
	    int m=str2.size();
	    for(i=0;i<n+1;i++)
	    {
	        for(j=0;j<m+1;j++)
	        {
	            if(i==0 || j==0)
	            {
	                L[i][j]=0;
	            }
	        }
	    }
	     for(i=1;i<n+1;i++)
	    {
	        for(j=1;j<m+1;j++)
	        {
	            if(str1[i-1]== str2[j-1])
	                L[i][j]=1+L[i-1][j-1];
	            else 
	                L[i][j]=max(L[i-1][j],L[i][j-1]);
	        }
	    }
	    return n+m-L[n][m]*2;
	} 