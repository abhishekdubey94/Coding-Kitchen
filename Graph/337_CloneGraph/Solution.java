class Solution {
    class Node {
        public int val;
        public List<Node> neighbors;
        public Node() {
            val = 0;
            neighbors = new ArrayList<Node>();
        }
        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<Node>();
        }
        public Node(int _val, ArrayList<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    }
    public Node cloneGraph(Node node) {
        if(node==null){
            return node;
        }
        Map<Integer,Node> map = new HashMap<>();
        map.put(node.val,new Node(node.val));
        dfs(node,map);
        return map.get(node.val);
    }
    
    public void dfs(Node node,Map<Integer,Node> map){
        Node clonedNode = map.get(node.val);
        for(Node neighbor : node.neighbors){
            if(map.get(neighbor.val)==null){
                Node newNode = new Node(neighbor.val);
                map.put(neighbor.val,newNode);
                clonedNode.neighbors.add(newNode);
                dfs(neighbor,map);
            }else{
                Node existingNode = map.get(neighbor.val);
                clonedNode.neighbors.add(existingNode);
            }
        }       
        
    }
}
