class Solution {
    private int[] fib;

    public int tribonacci(int n) {
        if (fib == null) {
            fib = new int[n + 1];
        }
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 1;
        }
        if (fib[n] == 0) {
            fib[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        }

        return fib[n];

    }
}