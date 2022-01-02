class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        int t[N+1][sum+1];
        int i,j;
        for(i=0;i<=N;i++){
            for(j=0;j<=sum;j++)
            {
                if(i==0)
                t[i][j]=false;
                 if(j==0)
                t[i][j]=true;
            }
        }
            for(i=1;i<=N;i++){
                for(j=1;j<=sum;j++){
                    if(arr[i-1]<=j){
                        t[i][j]=(t[i-1][j-arr[i-1]] || t[i-1][j]);
                    }
                    else
                        t[i][j]=t[i-1][j];
                }
            }
            return t[N][sum];
        }
    
};
