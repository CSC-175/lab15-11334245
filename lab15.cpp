#include<iostream>
using namespace std;

// Function prototypes
void getInfo(int&, int&);
double computeWays(int, int);
double factorial(int);

/*******************************************************************
* getLotteryInfo                                                   *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
********************************************************************/

  void getInfo (int&pickFrom, int&numPicks) {
  do {
    cout << "How many balls (1-12) are in the pool to pick from? ";
    cin >> pickFrom;
    if (pickFrom < 1 || pickFrom > 12) {
      cout << "Input Error! There must be between 1 and 12 balls." << endl;
    }
  } while (pickFrom > 1 || pickFrom < 12);
  do {
    cout << "How many balls (1-" << pickFrom << ") will be drawn? ";
    cin >> numPicks;
    if (numPicks < 1 || numPicks > pickFrom) {
      cout << "Input Error!" << endl;
    }
  } while (numPicks < 1 || numPicks > pickFrom);
    }



/*******************************************************************
* computeWays                                                      *
* Computes and returns the number of different possible sets       *
* of k numbers that can be chosen from a set of n numbers.         *
* The formula for this is     k!(n- k)!                            *
*                             --------                             *
*                                 n!                               *
* Note that the computation is done in a way that does not require *
* multiplying two factorials together. This is done to prevent any *
* intermediate result becoming so large that it causes overflow.   *
********************************************************************/
double computeWays(int pickFrom, int numPicks) {
  return double(factorial(pickFrom) / (factorial(numPicks) * factorial(pickFrom-numPicks)));
}
  /*******************************************************************
  * factorial                                                        *
  * This function computes factorials recursively.                   *
  *******************************************************************/
  double factorial(int num) {
    if (num <=1)
      return 1;
    return num * factorial(num - 1);
  }


