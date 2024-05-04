class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int cnt = 0, left = 0, right = people.length - 1;
        while (left <= right) {
            if (people[left] + people[right] > limit) {
                cnt++;
                right--;
            } else if (people[left] + people[right] <= limit) {
                cnt++;
                left++;
                right--;
            }
        }
        return cnt;
    }
}
