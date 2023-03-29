class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int first = 0;
        //int second = 1;
        int third = 2;
        int count = 0;
        if(flowerbed.size() == 1){
            if(flowerbed[0]==0){
                return true;
            }
            else if(flowerbed[0] == 1 & n == 0){
                return true;
            }
                
            return false;
        }
        for(int i = 0; i<flowerbed.size(); i++){
            if(i == 0 || i == (flowerbed.size()-1)){
                if(i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    count++;
                }
                else if(i == (flowerbed.size()-1) && flowerbed[i] == 0 && flowerbed[i-1] == 0){
                    flowerbed[i] = 1;
                    count++;
                }
            }else{
                first = i-1;
                third = i+1;
                if(flowerbed[i] == 0 && flowerbed[first] == 0 && flowerbed[third] == 0){
                    flowerbed[i] = 1;
                    count++;
                }
                    
            }
        }
        if(count >= n){
            return true;
        }
        else{
            return false;
        }
    }
};