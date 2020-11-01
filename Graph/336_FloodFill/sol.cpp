// https://leetcode.com/problems/flood-fill/


// **************RECURSIVE APPROACH************************

// class Solution {
//     public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
//         if(image[sr][sc]==newColor){
//             return image;
//         }
//         fillPixel(image,sr,sc,image[sr][sc],newColor);
//         return image;
//     }
    
//     public void fillPixel(int[][] image, int sr, int sc, int color,int newColor){
//         if(sr<0 || sc <0 || sr>=image.length || sc>= image[sr].length ||  image[sr][sc]!=color ){
//             return;
//         }
//         image[sr][sc] = newColor;
//         fillPixel(image,sr+1,sc,color,newColor);
//         fillPixel(image,sr-1,sc,color,newColor);
//         fillPixel(image,sr,sc+1,color,newColor);
//         fillPixel(image,sr,sc-1,color,newColor);
//     }
// }



//***************BFS APPROACH**************************
// class Solution {
//     class Pixel{
//         int x,y;
//         Pixel(int x,int y){
//             this.x = x;
//             this.y = y;
//         }
//     }
    
//     public boolean isInside(int x,int y,int m,int n){
//         if(x>=0 && x<m && y>=0 && y<n) return true;
//         return false;
//     }
//     public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
//         int m = image.length;
//         int n = image[0].length;
        
        
//         Queue<Pixel> q = new LinkedList<>();
//         boolean visited[][] = new boolean[m][n];
        
//         Pixel p = new Pixel(sr,sc);
//         q.add(p);
//         int originalColor = image[sr][sc];
//         visited[sr][sc] = true;
        
//         while(!q.isEmpty()){
//             Pixel l = q.poll();
//             image[l.x][l.y] = newColor;
            
//             if(isInside(l.x+1,l.y,m,n) && !visited[l.x+1][l.y] && image[l.x+1][l.y]==originalColor){
//                 q.add(new Pixel(l.x+1,l.y));
//                 visited[l.x+1][l.y] = true;
//             }
//             if(isInside(l.x-1,l.y,m,n) && !visited[l.x-1][l.y] && image[l.x-1][l.y]==originalColor){
//                 q.add(new Pixel(l.x-1,l.y));
//                 visited[l.x-1][l.y]=true;
//             }
//             if(isInside(l.x,l.y+1,m,n) && !visited[l.x][l.y+1] && image[l.x][l.y+1]==originalColor){
//                 q.add(new Pixel(l.x,l.y+1));
//                 visited[l.x][l.y+1]=true;
//             }
//             if(isInside(l.x,l.y-1,m,n) && !visited[l.x][l.y-1] && image[l.x][l.y-1]==originalColor){
//                 q.add(new Pixel(l.x,l.y-1));
//                 visited[l.x][l.y-1]=true;
//             }
//         }
        
        
        
//         return image;
//     }
// }





// Can also be solved using DFS
