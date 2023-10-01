use std::cmp;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut i, mut j) = (0, height.len() - 1);
        let mut max = 0;
        
        while i != j {
            let diff = (j - i) as i32;
            let area = diff * cmp::min(height[i], height[j]);
            max = cmp::max(max, area);
            
            if height[i] < height[j] {
                i += 1;
            } else {
                j -= 1;
            }
        }
        max
    }
}