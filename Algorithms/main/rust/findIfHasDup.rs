use std::collections::HashMap;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut map:HashMap<i32,i32> = HashMap::new();
        for i in nums.iter(){
            if let Occupied(val) = map.entry(*i){
                return true;
            }
            *map.entry(*i).or_insert(0) += 1;
            
        };
        false
    }
    pub fn contains_dup2(nums: Vec<i32>) -> bool {
        let mut map = HashSet::new();
        for &num in nums.iter(){
            if map.contains(&num){
                return true;
            }
            map.insert(num);
        };
        false
    }
}