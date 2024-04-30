class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        int[] x = new int[points.length];
        for (int i = 0; i < points.length; i++)
            x[i] = points[i][0];
        Arrays.sort(x);
        int max = 0;
        int last = x[0];
        for (int i = 1; i < points.length; i++) {
            int diff = x[i] - last;
            last = x[i];
            if (diff > max) {
                max = diff;
            }
        }
        return max;
    }
}