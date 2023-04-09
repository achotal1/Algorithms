fn filter_out_emails(s: String) -> String{
        let v:Vec<&str> = s.split('@').collect();
        let local:String  = v[0].chars().take_while(|&x| x != '+').
                filter(|&x| x != '.').collect();
        [local, v[1].to_string()].join("@")

}
impl Solution {
    
    pub fn num_unique_emails(emails: Vec<String>) -> i32 {
       emails.into_iter().map(filter_out_emails).
              collect::<std::collections::HashSet<_>>().len() as i32
    }
}