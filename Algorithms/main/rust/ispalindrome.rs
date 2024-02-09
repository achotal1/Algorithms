impl Solution {
    pub fn is_palindrome(s: String) -> bool{
        let mut s1: Vec<char> = s.chars().filter(|x|x.is_alphanumeric())
                                .map(|c| c.to_lowercase().next().unwrap()).collect();
        let mut i = s1.len() - 1;
        for (start, val) in s1.iter().enumerate(){
            if s1[i] != s1[start]{
                return false;
            }
            i -= 1;
        }

        true
    }
}
