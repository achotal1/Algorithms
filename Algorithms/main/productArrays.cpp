/*
Implement a function, findProduct(int arr[], int size) which takes an array arr and its 
size as an input and returns an array so that each index has a product of all the numbers 
present in the array except the number stored at that index.
Sample Input
arr = [1,2,3,4]
Sample Output
arr = [24,12,8,6]
*/

int * findProduct(int arr[], int size)  { 
    int * product = new int[size]; 
      // Write your code here
      int zerobit(-1), prod(1);
      for(int i = 0; i<size; i++){
        if(arr[i] != 0){
          prod *= arr[i];
        }
        else{
          zerobit = i;
        }
      }
      int count = 0;
      for(int i = 0; i<size; i++){
        if(zerobit != -1){
          if(i == zerobit){
            product[count] = prod;
          }
          else{
            product[count] = 0;
          }
        }
        else{
          int temp = prod/arr[i];
          product[count] = temp;
        }
        count++;
      }
    return product; 
} 