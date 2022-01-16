class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int count = 0;
        for(int i =0; i < nums.size() ; i++)
        {
            sum = sum + nums[i];
            if(nums[i] == 0)
            {
                count++;
            }
        }
        if(target > sum || (sum+target)%2 != 0 || target < (-1)*sum)
        {
            return 0;
        }
        else
        {
            int newtarget = (sum + target)/2;
            int answer[nums.size() + 1][newtarget+1];
            for(int i =0; i < nums.size() + 1; i++)
            {
                answer[i][0] = 1;
            }
            for(int j = 1; j < newtarget +1 ; j++)
            {
                answer[0][j] = 0;
            }
            for(int i =1;i < nums.size() + 1; i++)
            {
                for(int j =1; j <newtarget+1; j++)
                {
                    if(nums[i-1] > j || nums[i-1] == 0)
                    {
                        answer[i][j] = answer[i-1][j];
                    }
                    else
                    {
                        answer[i][j] = answer[i-1][j] + answer[i-1][j-nums[i-1]];
                    }
                }
            }
            return pow(2,count)*answer[nums.size()][newtarget];
        }
        
    
    }
};