class LeafLevel {
    int leafLevel;

    boolean check(Node root) {
        int level = 0;
        return checkUtil(root, level);
    }

    boolean checkUtil(Node root, int level) {
        if (root == null) {
            return true;
        }

        if (root.left == null && root.right == null) {
            if (leafLevel == 0) {
                leafLevel = level;
                return true;
            }
            return leafLevel == level;
        }

        return checkUtil(root.left, level + 1) && checkUtil(root.right, level + 1);
    }
}