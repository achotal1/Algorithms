use std::collections::HashMap;
use std::cmp;
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut freq: HashMap<char,i32> = HashMap::new();
        let mut str:Vec<char> = s.chars().collect();
        let mut maxlen = 0;
        let mut windowStart:usize = 0;
        for windowEnd in 0..str.len(){
            if freq.contains_key(&str[windowEnd]){
                windowStart = cmp::max(windowStart, (freq[&str[windowEnd]] + 1)as usize);
                freq.remove(&str[windowEnd]);
            }
            else{
                maxlen = cmp::max(maxlen, (windowEnd - windowStart + 1) as i32);
            }
            freq.insert(str[windowEnd], windowEnd as i32);
        }
        maxlen
    }
}