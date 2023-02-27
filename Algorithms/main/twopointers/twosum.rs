use std::convert::TryInto;
impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let (mut a, mut b):(usize,usize) = (0, (numbers.len() - 1).try_into().unwrap());
        for i in 0..numbers.len()-1{
            if(numbers[a] + numbers[b] == target){
                return vec![a as i32+1,b as i32+1];
            }
            else if(numbers[a] + numbers[b] < target){
                a += 1;
            }
            else{
                b -= 1;
            }
        }
        vec![a as i32+1,b as i32+1]
    }
}