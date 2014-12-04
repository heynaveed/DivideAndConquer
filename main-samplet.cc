#include "cwk.cc"

// Code testing the samplet class.
int main() {
samplet<fraction> s1;
  
  
  while(cin >> s1){
    cout << s1;
    s1.printStats();
    
    //break;  
  }
  
  if(cin.bad()){
    cerr << "\nBad Input\n\n";
  }
	return 0;
}

