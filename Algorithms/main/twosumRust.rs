use std::convert::TryInto;
use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::new();
        for i in 0..nums.len(){
            let complement = target - nums[i];
            if let Some(&j) = map.get(&complement){
                return vec![j as i32, i as i32];
            }
            else{
                map.insert(nums[i], i as i32);
            }
        }
        unreachable!();
    }
}