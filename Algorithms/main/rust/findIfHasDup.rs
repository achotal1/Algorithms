use std::collections::HashMap;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut map:HashMap<i32,i32> = HashMap::new();
        for i in 0..nums.len(){
            *map.entry(nums[i]).or_insert(0) += 1;
            println!("{}",map.get(&nums[i]).unwrap());
            if map.get(&nums[i]).unwrap() > &1{
                return true;
            }
        }
        false
    }
}