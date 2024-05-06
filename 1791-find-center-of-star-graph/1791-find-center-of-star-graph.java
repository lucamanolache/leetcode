class Solution {
    public int findCenter(int[][] edges) {
        // we can do this in constant time
        int c1 = edges[0][0];
        
        if (c1 == edges[1][0] || c1 == edges[1][1]) {
            return c1;
        } else {
            return edges[0][1];
        }
    }
}