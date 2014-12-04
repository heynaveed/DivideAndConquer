#include "cwk.cc"

// Code testing the sample class.
int main() {
  
  sample s1;
  
  
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

