use std::collections::HashMap;
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut map: HashMap<char, i32> = HashMap::new();
        let mut map2: HashMap<char, i32> = HashMap::new();
        if s.len() != t.len(){
            return false;
        };
        for (a,b) in s.chars().zip(t.chars()){
            *map.entry(a).or_default() += 1;
            *map.entry(b).or_default() -= 1;
        }
        map.into_values().all(|cnt| cnt == 0)
    }
}