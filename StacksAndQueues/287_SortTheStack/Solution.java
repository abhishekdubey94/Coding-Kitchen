class Solution{
	public Stack<Integer> sort(Stack<Integer> s)
	{
		int arr[] = new int[s.size()];
		int i=0;
		while(!s.isEmpty()){
		    arr[i++] = s.pop(); 
		}
		
		for (i = 0; i < arr.length-1; i++) 
            for (int j = 0; j < arr.length-1-i; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
		
	    for(i=0;i<arr.length;i++){
	        s.push(arr[i]);
	    }
	    
	    return s;
	}
}