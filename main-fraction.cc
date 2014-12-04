#include "cwk.cc"

// Code testing fractions
int main() {
  fraction f1;
  fraction f2(5);
  fraction f3(2, 6);
  fraction f4;
  
  while(cin >> f4){
    cout << "PLUS" << endl
	 << f2 << " + " << f4 << " = " << (f2+f4) << endl
	 << 6 << " + " << f4 << " = " << (6+f4) << endl
	 << f4 << " + " << 7 << " = " << (f4+7) << endl;
    
    cout << "MINUS" << endl
	 << f2 << " - " << f4 << " = " << (f2-f4) << endl
	 << 6 << " - " << f4 << " = " << (6-f4) << endl
	 << f4 << " - " << 7 << " = " << (f4-7) << endl;
    
    cout << "MULTIPLY" << endl
	 << f2 << " * " << f4 << " = " << (f2*f4) << endl
	 << 6 << " * " << f4 << " = " << (6*f4) << endl
	 << f4 << " * " << 7 << " = " << (f4*7) << endl;
    
    cout << "DIVISION" << endl
	 << f2 << " / " << f4 << " = " << (f2/f4) << endl 
	 << 6 << " / " << f4 << " = " << (6/f4) << endl
	 << f4 << " / " << 7 << " = " << (f4/7) << endl;
	 
//	 break;	
  } 
  
  if(cin.bad()){
    cerr << "\nBad Input\n\n";
  }
  
  return 0;
	
}
