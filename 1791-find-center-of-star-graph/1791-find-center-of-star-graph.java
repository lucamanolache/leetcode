class Solution {
    public int findCenter(int[][] edges) {
        // we can do this in constant time
        int c1 = edges[0][0];
        int c2 = edges[0][1];
        int c3 = edges[1][0];
        int c4 = edges[1][1];
        if (c1 == c3) {
            return c1;
        } else if (c1 == c4) {
            return c1;
        } else {
            return c2;
        }
    }
}