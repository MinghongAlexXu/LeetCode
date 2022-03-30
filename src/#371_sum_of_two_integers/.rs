impl Solution {
    pub fn get_sum(mut a: i32, mut b: i32) -> i32 {
        while b != 0 {
            (a, b) = ((a ^ b), (a & b) << 1);
        }
        a
    }
}

pub struct Solution;

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example_1() {
        assert_eq!(Solution::get_sum(1, 2), 3);
    }

    #[test]
    fn example_2() {
        assert_eq!(Solution::get_sum(2, 3), 5);
    }
}
