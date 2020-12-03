class Solution
{
public:
    int setBits(int N)
    {
        int count = 0;
        for(int i=N;i>0;i=i>>1){
            if((i&1)==1)
                count++;
        }
        return count;
    }
};