use std::cmp;

impl Solution {
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mut max = 0;
        for i in &candies {
            max = cmp::max(*i, max);
        }
        return candies.iter().map(|i| {
            i + extra_candies >= max
        }).collect::<Vec<bool>>();
    }
}