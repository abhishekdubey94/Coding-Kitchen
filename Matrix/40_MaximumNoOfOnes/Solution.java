lass Solution {
    
    static int first(int arr[], int low, int high) 
    { 
        if (high >= low) { 
            // Get the middle index 
            int mid = low + (high - low) / 2; 
  
            // Check if the element at middle index is first 1 
            if ((mid == 0 || (arr[mid - 1] == 0)) && arr[mid] == 1) 
                return mid; 
  
            // If the element is 0, recur for right side 
            else if (arr[mid] == 0) 
                return first(arr, (mid + 1), high); 
                  
            // If element is not first 1, recur for left side 
            else 
                return first(arr, low, (mid - 1)); 
        } 
        return -1; 
    }
    int rowWithMax1s(int mat[][], int n, int m) {
        int max_row_index = 0; 
  
    // The function first() returns index of first 1 in row 0. 
    // Use this index to initialize the index of leftmost 1 seen so far 
    int j = first(mat[0], 0, m-1); 
    if (j == -1) // if 1 is not present in first row 
      j = m - 1; 
  
    for (int i = 1; i < n; i++) 
    { 
        // Move left until a 0 is found 
        while (j >= 0 && mat[i][j] == 1) 
        { 
           j = j-1;  // Update the index of leftmost 1 seen so far 
           max_row_index = i;  // Update max_row_index 
        } 
    } 
    return max_row_index; 
    }
}