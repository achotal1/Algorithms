impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let s_iter:Vec<char> = s.chars().collect();
        let mut save: i32 = 0;
        for (i,v) in s_iter.iter().enumerate(){
            if i != s_iter.len() - 1{
                if *v == ' ' && s_iter[i+1] != ' '{
                   save = (i+1) as i32;
                }
            }
            
        }
        let mut char_count = 0;
        let len:i32 = s_iter.len() as i32;
        for i in save..len{
            if s_iter[i as usize] == ' '{
                break;
            }
            char_count += 1;
        }
        char_count
	  // One liner
	  // s.split_whitespace().next_back().unwrap().len() as i32

    }
}