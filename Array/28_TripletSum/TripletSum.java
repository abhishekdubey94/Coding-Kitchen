class TripletSum
{
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    public static boolean find3Numbers(int A[], int n, int X) { 
    
       Arrays.sort(A);
       
       for(int i=0;i<n-2;i++){
           int j = i+1;
           int k = n-1;
           while(j<n && k>=0 && j<k){
                   int sum = A[i] + A[j] + A[k];
                   if(sum==X){
                       return true;
                   }
                   else if(sum>X){
                       k--;
                   }else{
                       j++;
                   }
           }
       }
        return false;
    }
}