/*
 Sam Sytsma
 C++ Fall 2022
 Due: Oct. 14, 2022
 Lab 4 Temperature Output
 This Lab is a demo of my ability to .
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

string inputFile = "/Users/samsytsma/Documents/Lab4/Lab4/TempInput.dat";
//Precondition:     None
//Postcondition:    Output header to screen
void Header();

//Precondition:     Include libraries fstrem, string, iomanip, and iostream. Pos and Neg must be called
//Postcondition:    Gets called to main
void BarGraph();

//Precondition:     File Input must be called
//Postcondition:    s
void StarCalc();

//Precondition:     File Input must be called
//Postcondition:    s
void StarCalcNeg();

//Precondition:     Include library iostream, iomanip. FileInput, Pos, and StarCalc must be called. Have values stored in temp.
//Postcondition:    Sets width at 0 and outputs |.
void Output();

//Precondition:     Include library iostream, iomanip. FileInput, Neg, and StarCalcNeg must be called. Have values stored in temp.
//Postcondition:    Sets width at 0 and outputs |.
void OutputNeg();

//Precondition:     Include library iostream, iomanip. FileInput, Pos, StarCalc, and Output must be called. Have values stored in temp.
//Postcondition:    Outputs * to the right of |.
void StarOutput();

//Precondition:     Include library iostream, iomanip. FileInput, Neg, StarCalcNeg, and OutputNeg must be called. Have values stored in temp.
//Postcondition:    Outputs * to the left of |.
void StarOutputNeg();

//Precondition:     File Input must be called
//Postcondition:    s
void Pos();
//Precondition:     File Input must be called
//Postcondition:    s
void Neg();
int temp;
int star;

int main() {
    Header();
    BarGraph();
    
    return 0;
}
void BarGraph(){
    ifstream infile;
    infile.open(inputFile);
    
    if(!infile)
        cout << "\nCan't find file\n";
    
    string readin;
    while (!infile.eof())
    {
        infile >> temp;
        Pos();
        Neg();
    }
    cout << endl;

    infile.close();
}
void StarCalc(){
    int starR;
    star = temp / 3;
    starR = temp % 3;
    if (starR == 2)
        star = star + 1;
}
void StarCalcNeg(){
    int starR;
    star = -temp / 3;
    starR = -temp % 3;
    if (starR == 2)
        star = star + 1;
}
void Header(){
    cout << "                        Temperature" << endl;
    cout << setw(10) << "-30" << setw(10) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120";
}
void Output(){
    if (temp < 100 && temp > 9)
        cout << setw(18) << "|";
    if (temp < 10 && temp > 0)
        cout << setw(19) << "|";
    if (temp < 121 && temp > 99)
        cout << setw(17) << "|";
}
void OutputNeg(){
    if (temp <= -10 && temp >= -30){
        cout << setw(17-star);
    }
    if (temp < 0 && temp >= -9){
        cout << setw(18-star);
    }
}
void StarOutput(){
    int i;
    for (int i = 1; i <= star; i++)
        cout << "*";
}
void StarOutputNeg(){
    int i;
    for (int i = 1; i <= star; i++)
        cout << "*";
}
void Pos(){
    if (temp >= 0 && temp <= 120)
    {
        cout << endl << temp;
        StarCalc();
        Output();
        StarOutput();
    }
}
void Neg(){
    if (temp >= -30 && temp <= -1){
        cout << endl << temp;
        StarCalcNeg();
        OutputNeg();
        StarOutputNeg();
        cout << "|";
    }
}
