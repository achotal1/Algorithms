#include<vector>

bool isValidWalk(std::vector<char> walk) {
  //your code here
  int northsouth = 0;
  int eastwest = 0;
  for(int i = 0; i<walk.size(); i++){
    if(walk[i] == 'n'){
      northsouth++;
    }else if(walk[i] == 's'){
      northsouth--;
    }else if(walk[i] == 'w'){
      eastwest++;
    }else if(walk[i] == 'e'){
      eastwest--;
    }
  }
  return walk.size() == 10 && eastwest == 0 && northsouth == 0;
}