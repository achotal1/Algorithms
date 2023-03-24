impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut t_iter = t.chars();
        for i in s.chars(){
            match t_iter.find(|&x| x == i){
                Some(_) => (),
                None => return false
            }
        }
        true

    }
}