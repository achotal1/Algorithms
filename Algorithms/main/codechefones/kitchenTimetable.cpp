/*
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the number of students.

The second line contains N space-separated integers A1, A2, ..., AN denoting the moments of time by when the corresponding student should finish cooking.

The third line contains N space-separated integers B1, B2, ..., BN denoting the time required for each of the students to cook.

Output out how many students can complete their in their time
*/


#include <iostream>
#include <unordered_map>
using namespace std;
class TimeTable{
  public:
  static void violate(){
      //return accepted;
  }
};
int main() {
	int T(0);
	cin>>T;
	for(int i = 0; i< T; i++){
	    unordered_map<int,int> times;
	    unordered_map<int,int> pancakeTime;
	    int number = 0; int tm = 0; int accepted = 0;
	    cin>>number;
	    for(int i = 0; i<number; i++){
	        cin>>tm;
	        times[i] = tm;
	    }
	    for(int i = 0; i<number; i++){
	        cin>>tm;
	        pancakeTime[i] = tm;
	    }
	    int j = 0;
	    for(int i = 0; i<number; i++){
	        int temp = times[i];
	        times[i] = times[i] - j;
	        times[i] = times[i] - pancakeTime[i];
	        j = temp;
	    }
	    for(int i = 0; i<number; i++){
	        if(times[i] >= 0){
	            accepted++;
	        }
	    }
	    cout<<accepted<<'\n';
	}
	return 0;
}
