class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int i,j;
        int t[x+1][y+1];
        for(i=0;i<=x;i++){
            for(j=0;j<=y;j++)
            {
                if(i==0 || j==0)
                t[i][j]=0;  
            else{
       
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                    
                }
            }
        }
    }
        return t[x][y];
    }
};
