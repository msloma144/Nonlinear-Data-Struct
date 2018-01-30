#include <iostream>
#include <tuple>
#include <cmath>
#include <iomanip>

using namespace std;

tuple<double, double, int> getInput(){
    double upperLimit;
    double lowerLimit;
    int numOfIntervals;

    cout << "Please enter lower limit: ";
    cin >> lowerLimit;

    cout << "Please enter upper limit: ";
    cin >> upperLimit;

    cout << "Please enter number of intervals: ";
    cin >> numOfIntervals;

    return {lowerLimit, upperLimit, numOfIntervals};
}

double evalFunction(double val){
    return sin(val); //Sin function
}
void printStep(double startVal, double endVal, double evalStart, double evalThird,
               double eval2Third, double evalEnd, double integral){
    printf("%.5f %.5f %.5f    %.5f      %.5f     %.5f %.5f\n",
           startVal, endVal, evalStart, evalThird, eval2Third, evalEnd, integral);
}

double calcIntegralStep(double startVal, double endVal){
    double coff = (endVal - startVal)/8;
    double evalStart = evalFunction(startVal);
    double evalThird = evalFunction((2 * startVal + endVal) / 3);
    double eval2Third = evalFunction((startVal + 2 * endVal) / 3);
    double evalEnd = evalFunction(endVal);

    double integral = coff * (evalStart + 3 * evalThird + 3 * eval2Third + evalEnd);

    printStep(startVal, endVal, evalStart, evalThird, eval2Third, evalEnd, integral);
    return integral;
}

void simpsons(){
    tuple<double, double, int> inputs = getInput();

    double lowerLimit = get<0>(inputs);
    double upperLimit = get<1>(inputs);
    int numOfIntervals = get<2>(inputs);
    double stepAmount = (upperLimit - lowerLimit) / numOfIntervals;
    double sum = 0;

    printf("%4s %8s %7s %15s %12s %7s %7s\n",
           "a", "b", "f(a)", "f((2a+ b)/3)", "f((a+ 2b)/3)", "f(b)", "value");

    double startVal = lowerLimit;
    double endVal = startVal + stepAmount;

    for(int i = 0; i < numOfIntervals; i++){
        sum += calcIntegralStep(startVal, endVal);
        startVal += stepAmount;
        endVal += stepAmount;
    }

    cout << "Sum: " << fixed << setprecision(5) << sum;
}
int main() {
    simpsons();
    return 0;
}