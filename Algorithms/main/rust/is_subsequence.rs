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
    
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut ind = 0;
        let mut tvec = t.chars().collect::<Vec<_>>();
        let mut svec = s.chars().collect::<Vec<_>>();
        if s.len() == 0{
            return true;
        }
        for (i, &val) in tvec.iter().enumerate(){
            if val == svec[ind]{
                ind += 1;
                if(ind == s.len()){
                    return true;
                }
            }
        }
        false
    }
}
}