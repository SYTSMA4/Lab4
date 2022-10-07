/*
 Sam Sytsma
 C++ Fall 2022
 Due: Oct. 14, 2022
 Lab 4 Temperature Output
 This Lab is a demo of my ability to .
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

string inputFile = "/Users/samsytsma/Documents/Lab4/Lab4/TempInput.dat";
//Precondition:     None
//Postcondition:
//Note:             s
void Header();
//Precondition:     None
//Postcondition:
//Note:             s
float FileInput();
//Precondition:     File Input must be called
//Postcondition:    s
//Note:             s
float StarCalc();
//Precondition:     File Input must be called
//Postcondition:    s
//Note:             s
float StarCalcNeg();
//Precondition:     File Input must be called
//Postcondition:    s
//Note:             s
float Output();
//Precondition:     File Input must be called
//Postcondition:    s
//Note:             s
float OutputNeg();
//Precondition:     File Input must be called
//Postcondition:    s
//Note:             s
float StarOutput();
//Precondition:     File Input must be called
//Postcondition:    s
//Note:             s
float StarOutputNeg();
int InTemp;
int temp;
int star;
int starR;
int i;

int main() {
    Header();
    FileInput();
    
    
    return 0;
}
float FileInput(){
    ifstream infile;
    infile.open(inputFile);
    
    if(!infile)
        cout << "\nCan't find file\n";
    
    string readin;
    while (!infile.eof())
    {
        infile >> temp;
        
        if (temp >= 0 && temp <= 120)
        {
            cout << endl << temp;
            StarCalc();
            Output();
            StarOutput();
        }
        if (temp >= -30 && temp <= -1){
            cout << endl << temp;
            StarCalcNeg();
            OutputNeg();
            StarOutputNeg();
            cout << "|";
        }
    }
    cout << endl;
    return 0;
}
float StarCalc(){
    star = temp / 3;
    starR = temp % 3;
    if (starR == 2)
        star = star + 1;
    
    return 0;
}
float StarCalcNeg(){
    star = -temp / 3;
    starR = -temp % 3;
    if (starR == 2)
        star = star + 1;
    
    return 0;
}
void Header(){
    cout << "                        Temperature" << endl;
    cout << setw(10) << "-30" << setw(10) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120";
}
float Output(){
    if (temp < 100 && temp > 9)
        cout << setw(18) << "|";
    if (temp < 10 && temp > 0)
        cout << setw(19) << "|";
    if (temp < 121 && temp > 99)
        cout << setw(17) << "|";
    
    return 0;
}
float OutputNeg(){
    if (temp <= -10 && temp >= -30){
        cout << setw(17-star);
    }
    if (temp < 0 && temp >= -9){
        cout << setw(18-star);
    }
    return 0;
}
float StarOutput(){
    for (int i = 1; i <= star; i++)
        cout << "*";
    
    return 0;
}
float StarOutputNeg(){
    for (int i = 1; i <= star; i++)
        cout << "*";
    
    return 0;
}
