impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        for r in 0..3 {
            for c in 0..3 {
                if !Solution::check3x3(&board, r * 3, c * 3) {
                    return false;
                }
            }
        }
        for row in board.iter() {
            if !Solution::check_row(row) {
                return false;
            }
        }
        for col in 0..9 {
            if !Solution::check_col(&board, col) {
                return false;
            }
        }
        return true;
    }
    
    fn check3x3(board: &Vec<Vec<char>>, s_r: usize, s_c: usize) -> bool {
        let mut check: u16 = 0;
        for r in s_r..(s_r+3) {
            for c in s_c..(s_c+3) {
                let v = board[r][c].to_digit(10);
                if let Some(v) = v {
                    if check & (1 << v) == (1 << v) {
                        return false;
                    }
                    check |= 1 << v;
                }
            }
        }
        true
    }
    
    fn check_row(row: &Vec<char>) -> bool {
        let mut check: u16 = 0;
        for c in 0..9 {
            let v = row[c].to_digit(10);
            if let Some(v) = v {
                if check & (1 << v) == (1 << v) {
                    return false;
                }
                check |= 1 << v;
            }
        }
        true
    }
    
    fn check_col(board: &Vec<Vec<char>>, col: usize) -> bool {
        let mut check: u16 = 0;
        for r in 0..9 {
            let v = board[r][col].to_digit(10);
            if let Some(v) = v {
                if check & (1 << v) == (1 << v) {
                    return false;
                }
                check |= 1 << v;
            }
        }
        true
    }
}