class Solution
{
    // return an array containing the zig zag level order traversal of the given tree
	ArrayList<Integer> zigZagTraversal(Node root)
	{
	   ArrayList<Integer> ans = new ArrayList<>();
	   Queue<Node> q = new LinkedList<>();
	   ArrayList<Integer> temp = new ArrayList<>();
	   q.add(root);
	   boolean order = true;
	   
	   while(!q.isEmpty()){
	       int size = q.size();
	       for(int i=0;i<size;i++){
	           Node n = q.poll();
	           temp.add(n.data);
	           if(n.left!=null) q.add(n.left);
	           if(n.right!=null) q.add(n.right);
	           
	       }
	       
	       if(order){
	               order = false;
	               ans.addAll(temp);
	           }else{
	               order = true;
	               int p = temp.size()-1;
	               for(int i=p ; i>=0 ; i--){
	                   ans.add(temp.get(i));
	               }
	           }
	       
	       temp.clear();
	   }
	   
	   return ans;
	}
}