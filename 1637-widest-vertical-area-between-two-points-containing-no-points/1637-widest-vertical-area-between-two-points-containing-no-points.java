class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        final int[] max = {0};
        Arrays.stream(points).map(x -> x[0]).sorted().reduce((a, b) -> {
            max[0] = Math.max(max[0], b - a);
            return b;
        });
        return max[0];
    }
}