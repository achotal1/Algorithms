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
    pub fn is_subsequence2(s: String, t: String) -> bool {
        let mut s_char = s.chars().collect::<Vec<char>>();
        let mut t_char = t.chars().collect::<Vec<_>>();
        let mut ind = 0;
        for (i, val) in t.chars().enumerate(){
            if s_char[ind] == t_char[i]{
                ind += 1;
                if ind == s_char.len(){
                    return true;
                }
            }
        }
        false
    }
}