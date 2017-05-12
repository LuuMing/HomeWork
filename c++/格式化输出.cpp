
// bases.cpp

#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#include<ios>
#include <iomanip>

#include <cmath>


// function to convert a decimal number to a binary number
int convertBinary( int x )
{
   int power, result = 0;
   
   for ( power = 0; x >= pow( 2, power ); power++ ) ;

   for ( ; power >= 0; power-- ) {
      result *= 10;

      if ( x / pow( 2, power ) >= 1 ) {
         result++;
         x -= pow( 2, power );
      }
   }

   return result;
}

void printTable( int a[], const int size )
{
   cout << "\nTable with the numbers in various bases\n";



   cout<<std::left<<std::setw(8)<<"bin"<<std::setw(8)<<"oct"<<std::setw(8)<<"dec"<<std::setw(8)<<"hex"<<endl;
 
   for ( int i = 0; i < size; i++ )
      {
      	cout<<std::left<<std::dec<<setw(8)<<	convertBinary(a[i]);
      	cout<<std::left<<std::oct<<setw(8) << a[i];
      	cout<<std::left<<std::dec<<setw(8)<<a[i];
      	cout<<std::left<<std::hex<<setw(8)<<a[i];

      	cout<<endl;
}
   cout << "\nTable of formatted and unformatted "
        << "floating points\n";
   
   for ( int j = 0; j < size; j++ ) {
      double x = static_cast< double > ( a[ j ] );
  
         cout.unsetf(ios::showpos);
         cout<<setw(12)<<dec<<a[j];
         cout.setf(ios::showpos);
         cout.setf(ios::scientific);
		 cout<<setprecision(2)<<x;
		 cout<<endl;
   }
}

int main()
{
   int x[ 5 ] = { 0 };

   for ( int counter = 0; counter < 5; counter++ ) {
      cout << "enter number " << counter + 1 << ": ";
      cin >> x[ counter ];
	  if (cin.rdstate()!=std::ios::goodbit)
	  {
	  	cin.clear();
		cin.ignore();
		cout << "That is an invalid number, enter another number:";
		cin >> x[counter]; 
	   }
   }

   printTable( x, 5 );

   return 0;
}


/**************************************************************************
 * (C) Copyright 2002 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/


