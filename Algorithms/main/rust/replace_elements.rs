/*
Given an array arr, replace every element in that array with the greatest element 
among the elements to its right, and replace the last element with -1.

After doing so, return the array.

*/
impl Solution {
    pub fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
        let mut mx = -1;
        let mut res: Vec<i32> = vec![-1; arr.len()];
        for i in (0..arr.len()).rev(){
            res[i] = mx;
            mx = std::cmp::max(mx, arr[i]);
        }
        res
    }
}