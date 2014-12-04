#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



/* 2.2 - Q-1:
 * ===========
 * 
 * You can force programmers using the sample class to not initialise
 * empty sample objects by deleting the default constructor. 
 * 
 * As there is another constructor with an existing argument, the 
 * compiler will no longer synthesize a default constructor since 
 * responsbility for constructing objects of the sample class now lies 
 * with the programmer. 
 * 
 * This means other programmers are forced to provide an argument (in this
 * case a vector of doubles) to initialise an object of the sample class.
 * 
 * */

/* 2.2 - Q-14: 
 * ============
 * 
 * The output is not correct with the given input as each value of the numbers are
 * the maximum number that the data type 'double' can hold. The values being 
 * returned for most functions are 'inf', meaning infinity - this is because the
 * number calculated is beyond the limit of the double data type. 
 * 
 * This can be fixed by ensuring a different data type is chosen, one that allocates
 * more memory to each variable. Since a double is 64 bit, choosing a long double 
 * which is 80-bit may be a better option. However, this would require strong
 system architecture.
 * 
 * */



 /**fraction begins here*/

int gcd(int n, int m){
  if(m == 0){
    return abs(n);
  }
  
  else{
    return gcd(m, n%m);
  }
}

int lcm(int n, int m){
  return abs(m*(n/gcd(n,m)));
}

class fraction{
public:
  fraction(): top(0), bottom(1){}
  
  fraction(int n): top(n), bottom(1){}

  fraction(int n, int m): top(n), bottom(m){
    if(m == 0){
      top = 0;
    }
    
    else{
      simplify(n, m);
    }
  }
  
  int numerator() const{
    return top;
  }
  int denominator() const{
    return bottom;
  }
  
  void simplify(int n, int m){
    top = n/gcd(n, m);
    bottom = m/gcd(n, m);
  }
  
  operator double() const{
    return numerator()/static_cast<double>(denominator());
  }

  bool operator==(const fraction &o);
  bool operator!=(const fraction &o);
  bool operator<(const fraction &o);
  bool operator>(const fraction &o);
  bool operator<=(const fraction &o);
  bool operator>=(const fraction &o);
  
  fraction &operator+=(const fraction &o);
  fraction &operator-=(const fraction &o);
  fraction &operator*=(const fraction &o);
  fraction &operator/=(const fraction &o);

private:
  int top;
  int bottom;
};

ostream & operator<<( ostream &os, const fraction &f){
  
  if(f.denominator() == 1){
    os << f.numerator();
  }
  
  else if(f.denominator() == 0){
    os << "NaN";	// not a number
  }
  
  else{
    os << f.numerator() << "/" << f.denominator();
  }
  return os;
}

istream & operator>>( istream &is, fraction &f){
  int n, m;
  char c1;
  
  if (is >> n){
    if(is >> c1 >> m && c1 == '/' && m != 0){
	f = fraction(n, m);
    }
    else{
    is.setstate(ios::badbit);
    }
  }
  
  else{
    is.setstate(ios::badbit);
  }
  return is;
}

fraction operator+(fraction a, fraction b){
  return a+=b;
}
fraction operator+(int a, fraction b){
  fraction f1(a, 1);
  return f1+=b;
}
fraction operator+(fraction a, int b){
  fraction f1(b, 1);
  return a+=f1;
}

fraction operator-(fraction a, fraction b){
  return a-=b;
}
fraction operator-(int a, fraction b){
  fraction f1(a, 1);
  return f1-=b;
}
fraction operator-(fraction a, int b){
  fraction f1(b, 1);
  return a-=f1;
}

fraction operator*(fraction a, fraction b){
  return a*=b;
}
fraction operator*(int a, fraction b){
  fraction f1(a, 1);
  return f1*=b;
}
fraction operator*(fraction a, int b){
  fraction f1(b, 1);
  return a*=f1;
}

fraction operator/(fraction a, fraction b){
  return a/=b;
}
fraction operator/(int a, fraction b){
  fraction f1(a, 1);
  return f1/=b;
}
fraction operator/(fraction a, int b){
  fraction f1(b, 1);
  return a/=f1;
}

fraction & fraction::operator+=(const fraction &o){
    top = (numerator()*o.denominator())+(denominator()*o.numerator());
    bottom = denominator()*o.denominator();
    simplify(top, bottom);
    return *this;
  }
  
fraction & fraction::operator-=(const fraction &o){
    int tempTop; 
    top = numerator()*o.denominator();
    tempTop = denominator()*o.numerator();
    bottom = denominator()*o.denominator();
    top = top - tempTop;
    simplify(top, bottom);
    return *this;
  }
  
fraction & fraction::operator*=(const fraction &o){
    top = numerator()*o.numerator();
    bottom = denominator()*o.denominator();
    simplify(top, bottom);
    return *this;
  }
  
fraction & fraction::operator/=(const fraction &o){
    top = numerator()*o.denominator();
    bottom = denominator()*o.numerator();
    simplify(top, bottom);
    return *this;
  }

bool fraction::operator==(const fraction&o){
  return numerator()*o.denominator() == denominator()*o.numerator();
}
bool fraction::operator!=(const fraction &o){
  return !(numerator()*o.denominator() == denominator()*o.numerator());
}
bool fraction::operator<(const fraction &o){
  return (numerator()/denominator()) < (o.numerator()/o.denominator());
}
bool fraction::operator>(const fraction &o){
  return (numerator()/denominator()) > (o.numerator()/o.denominator());
}
bool fraction::operator<=(const fraction &o){
  return !(numerator()/denominator()) > (o.numerator()/o.denominator());
}
bool fraction::operator>=(const fraction &o){
  return !(numerator()/denominator()) < (o.numerator()/o.denominator());
}


/**sample begins here*/
class sample{
public:
  sample(){}
  
  sample(vector<double> d): data(d){
    is_vector_present = true;
    sort(data.begin(), data.end());
  }
  
  const vector<double> &get_data() const{
    return data;
  }
  
  int get_size() const{
    return data.size();
  }
  
  void set_data(const vector<double> &v){
    data = v;
    is_vector_present = true;
    sort(data.begin(), data.end());
  }
  
  void set_is_vector_present(const bool status){
    is_vector_present = status;
  }
  
  void printStats(){
    if(is_vector_present){
      cout << "Minimum: " << minimum() << endl
           << "Maximum: " << maximum() << endl
           << "Range: " << range() << endl
           << "Midrange: " << midrange() << endl
           << "Median: " << median() << endl
           << "Mean: " << mean() << endl
           << "Variance: " << variance() << endl
           << "Standard Deviation: " << std_deviation() << endl << endl;
    }
  }
  
  double minimum(){
    vector<double>::iterator min = min_element(data.begin(), data.end());
    return *min;
  }
  
  double maximum(){
    vector<double>::iterator max = max_element(data.begin(), data.end()); 
    return *max;
  }
  
  double range(){
    return maximum() - minimum();
  }
  
  double midrange(){
    return (maximum()+minimum())/2;
  }
  
  double mean(){
    double sum = 0;
    
    for(int i = 0; i < get_size(); i++){
      sum += data[i];
    }
    return sum/get_size();
  }
  
  double variance(){
    double var;
    
    for (int i = 0; i < get_size(); i++){
      var += pow((data[i] - mean()), 2);
    }
    return var/get_size();
  }
  
  double std_deviation(){
    return sqrt(variance());
  }
  
  double median(){
    bool n_is_odd = get_size()%2;
    int mid = get_size()/2;
    
    if(n_is_odd == 1){
      return data[mid];
    }
    
    else{
      return (data[mid-1] + data[mid])/2;
    }
  }
  
private:
  vector<double> data;
  bool is_vector_present;
};

ostream & operator<<(ostream &os, sample &s){
    os << '<' << ' ' << s.get_size() << ':';
    for(int i = 0; i < s.get_size(); i++){
      os << ' ' << s.get_data()[i];
    }
    os << ' ' << '>' << endl;
    return os;
}

istream & operator>>(istream &is, sample &s){
  int nMax;
  char lessThan, moreThan, colon;
  bool checkFull = false;
  vector<double> newData;
  
  if(is >> lessThan && lessThan == '<'){
    if(is >> nMax >> colon && colon == ':'){
    
      for(int i = 0; i < nMax; i++){
  double num;
  if(is >> num){
    newData.push_back(num);
  }
      }
      
      int size = newData.size();      
      if(is >> moreThan && moreThan == '>' && size == nMax){
        s.set_data(newData);
        checkFull = true;
      }
    }
  }
  
  if(!checkFull){
    is.setstate(ios::badbit); 
    s.set_is_vector_present(false);
  }
  return is; 
}





/**samplet begins here*/
/* 2.3 - Q-15:
 * ============
 * 
 * It is essential that most member functions are of type T (template) because then it
 * would allow the class to be generic. Double is no longer a good choice for them 
 * because if we want it to be generic, then returning a double would make no sense
 * unless they have entered a vector of doubles. The generic class should be able to
 * return types of any data type such as int, double, float and possibly long - in
 * this case we have a constructor data type fraction. 
 * 
 * There is one exception to the return type of the member functions which is the 
 * standard deviation method. This is because it requires a square root, usually
 * any number that is not a square number but is square rooted returns an irrational
 * number - to present this in fraction form would result in a loss of precision. 
 * Therefore, a double return type is used for the std_deviation() method. 
 * */

template <class T>
class samplet{
public:
  samplet(){}
  
  samplet(vector<T> d): data(d){
    is_vector_present = true;
    sort(data.begin(), data.end());
  }
  
  const vector<T> &get_data() const{
    return data;
  }
  
  int get_size() const{
    return data.size();
  }
  
  void set_data(const vector<T> &v){
    data = v;
    is_vector_present = true;
    sort(data.begin(), data.end());
  }
  
  void set_is_vector_present(const bool status){
    is_vector_present = status;
  }
  
  void printStats(){
    if(is_vector_present){
      cout << endl << "Minimum: " << minimum() << endl
           << "Maximum: " << maximum() << endl
           << "Range: " << range() << endl
           << "Midrange: " << midrange() << endl
           << "Median: " << median() << endl
           << "Mean: " << mean() << endl
           << "Variance: " << variance() << endl
           << "Standard Deviation: " << std_deviation() << endl << endl;
    }
  }
  
  T minimum(){
    return data[0];
  }
  
  T maximum(){
    return data[get_size()-1];
  }
  
  T range(){
    return maximum() - minimum();
  }
  
  T midrange(){
    return (maximum()+minimum())/2;
  }
  
  T mean(){
    T sum = 0;
    
    for(int i = 0; i < get_size(); i++){
      sum += data[i];
    }
    return sum/get_size();
  }
  
  T variance(){
    T var;
    
    for (int i = 0; i < get_size(); i++){
      var += (data[i] - mean())*(data[i] - mean());
    }
    return var/get_size();
  }
  
  double std_deviation(){
    return sqrt(variance());
  }
  
  T median(){
    bool n_is_odd = get_size()%2;
    int mid = get_size()/2;
    
    if(n_is_odd == 1){
      return data[mid];
    }
    
    else{
      return (data[mid-1] + data[mid])/2;
    }
  }
  
private:
  vector<T> data;
  bool is_vector_present;
};

ostream & operator<<(ostream &os, samplet<fraction> &s){
    os << endl << '<' << ' ' << s.get_size() << ':';
    for(int i = 0; i < s.get_size(); i++){
      os << ' ' << s.get_data()[i];
    }
    os << ' ' << '>';
    return os;
}

istream & operator>>(istream &is, samplet<fraction> &s){
  int nMax, n, m;
  char c1;
  char lessThan, moreThan, colon;
  bool checkFull = false;
  vector<fraction> newData;
  
  if(is >> lessThan && lessThan == '<'){
    if(is >> nMax >> colon && colon == ':'){
      
      for(int i = 0; i < nMax; i++){
  
        if (is >> n){
          if(is >> c1 >> m && c1 == '/' && m != 0){
            fraction f(n, m);
            newData.push_back(f); 
          }
        }
      }
      
      int size = newData.size();      
      if(is >> moreThan && moreThan == '>' && size == nMax){
        s.set_data(newData);
        checkFull = true;
      }
      else if(!checkFull){
        is.setstate(ios::badbit); 
        s.set_is_vector_present(false);
      }
    }
  }
  
  else{
    s.set_is_vector_present(false);
    is.setstate(ios::badbit); 
  }
  return is;
}
