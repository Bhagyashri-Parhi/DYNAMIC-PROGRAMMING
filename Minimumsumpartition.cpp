int minDifference(int arr[], int n)  { 
	    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0&&j==0){
                t[i][j]=1;
            }
            else if(i==0){
                t[i][j]=0;
            }
            else if(j==0){
                t[i][j]=1;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    vector<int> v;
    for(int j=0;j<=(sum)/2;j++){
        if(t[n][j]==1)
        v.push_back(j);
    }
    int min=100000000;
    for(int i=0;i<v.size();i++){
        int x = sum-(2*v[i]);
        if(x<min)
        min=x;
    }
    return min;
	} 