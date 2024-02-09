impl Solution {
    pub fn valid_palindrome(s: String) -> bool {
        let mut la = s.len() - 1;
        let mut st = 0;
        let mut mistake = 1;
        let mut s1 = s.chars().collect::<Vec<_>>();
        while(st < la){
            if s1[st] != s1[la]{
                if(st != s1.len() - 1 && s1[st+1] == s1[la] && mistake == 1){
                    st += 1;
                    mistake = 0;
                }
                else if(la != 0  && s1[la-1] == s1[st] && mistake == 1){
                    la -= 1;
                    mistake = 0;
                }else{
                    return false;
                }
            }else{
                la -= 1;
                st += 1;
            }
            
        }
        true
    }
}