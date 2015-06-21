  //
 // Quadratic Equation - C++ Implementation
//

#include <iostream>
#include <tuple>
#include <iomanip>
#include <windows.h>
using namespace std;

class QuadEq {
public:

  bool FailCheck() {
    if (cin.fail()) { cout<<"\nInvalid entry. Please try again."<<endl; exit(1); }
  }

   tuple<double, double, double> get_coefficients() {
	double a, b, c;

	cout << "\n a: ";
	cin >> a;
  
	if (a == 0) { // not a true quadratic
	    cout<<"\nInvalid entry (<a> cannot be equal to zero). Please try again."<<endl;
	    exit(1); }

	FailCheck();

	cout << "\n";

	cout << " b: ";
	cin >> b;
	FailCheck();
	cout << "\n";

	cout << " c: ";
	cin >> c;
	FailCheck();
	cout << "\n";
	   
	return make_tuple(a, b, c);
}

    void find_value(double a, double b, double c) {
	  double value1, value2, D, DS;

          D = (pow(b, 2) - 4 * a * c);

	  if (D > 0)
	  {
          DS = sqrt(D);

	  value1 = (-b - DS) / (2 * a);
	  value2 = (-b + DS) / (2 * a);

	  cout << " REAL ROOTS: " << setprecision(2) <<"{"<< (value1) << ", " << (value2) <<"}"<< endl;
	  }

	  else if (D == 0) {

	  double dp_value = (-b) / (2 * a);
	  cout << " DUPLICATE ROOT: " << setprecision(2) << dp_value << endl;

          }
	   else
	  {
	    DS = sqrt(-D);
	     cout << " COMPLEX CONJUGATE ROOTS: " << (-b / (2 * a)) << "+/-" << DS / (2 * a) << "i" << endl;
	  }
     }
};

int main() {

	QuadEq prob;

	double a, b, c;

        HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );

        cout<<" \n Enter the numerical coefficient of each term in the quadratic expression:"<<endl; 
        SetConsoleTextAttribute( hstdout, 0x0C );

        tie(a, b, c) = prob.get_coefficients();
        SetConsoleTextAttribute(hstdout, 0x0F);

	prob.find_value(a, b, c);
	cout << "\n";

	return 0;
}
