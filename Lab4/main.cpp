/*
 Sam Sytsma
 C++ Fall 2022
 Due: Oct. 14, 2022
 Lab 4 Temperature Output
 This Lab is a demo of my ability to .
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

string inputFile = "/Users/samsytsma/Documents/Lab4/Lab4/TempInput.dat";
//Precondition:     Include librabries iostream and iomanip.
//Postcondition:    Output title and header to screen
void Header();

//Precondition:     Include libraries fstream and iostream.
//Postcondition:    Stores value in temp from input file.
void BarGraph(int star, int temp, int i);

//Precondition:     Stored value in temp from BarGraph
//Postcondition:    Stroes clculated value of star.  Claculates StarR.
void StarCalc(int temp, int& star);

//Precondition:     Stored value in temp from BarGraph
//Postcondition:    Stroes clculated value of star.  Claculates StarR.
void StarCalcNeg(int temp, int& star);

//Precondition:     Include libraries iostream and iomanip. Stored value in temp from BarGraph.
//Postcondition:    Sets width at 0 and outputs |.
void Output(int temp);

//Precondition:     Include libraries iostream and iomanip. Stored value in temp from BarGraph and star from StarCalc.
//Postcondition:    Sets width at 0 and outputs |.
void OutputNeg(int temp, int star);

//Precondition:     Include library iostream. Stored value in star from StarCalc.
//Postcondition:    Outputs * to the right of |.
void StarOutput(int star, int i);

//Precondition:     Include library iostream. Stored value in star from StarCalcNeg.
//Postcondition:    Outputs * to the left of |.
void StarOutputNeg(int star, int i);

//Precondition:     Include libraries iostream and iomanip. Stored value in temp from BarGraph
//Postcondition:    Outputs positive side of line on graph
void Pos(int temp, int star, int i);
//Precondition:     Include libraries iostream and iomanip. Stored value in temp from BarGraph
//Postcondition:    Outputs negative side of line on graph
void Neg(int temp, int star, int i);

int main() {
    int temp;
    int star;
    int i;
    temp = 0;
    star = 0;
    i = 0;
    Header();
    BarGraph(temp, star, i);
    
    return 0;
}
void Header(){
    cout << "                        Temperature" << endl;
    cout << setw(10) << "-30" << setw(10) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120";
}
void BarGraph(int star, int temp, int i){
    ifstream infile;
    infile.open(inputFile);
    
    if(!infile)
        cout << "\nCan't find file\n";
    
    string readin;
    while (!infile.eof())    // Reads in temp value from file until there are no values left to read
    {
        infile >> temp;
        Pos(temp, star, i);
        Neg(temp, star, i);
    }
    cout << endl;

    infile.close();
}
void Pos(int temp, int star, int i){
    if (temp >= 0 && temp <= 120) // Vets out numbers not in the positive range
    {
        cout << endl << temp;
        StarCalc(temp, star);
        Output(temp);
        StarOutput(star, i);
    }
}
void Neg(int temp, int star, int i){
    if (temp >= -30 && temp <= -1){ // Vets out numbers not in negative range
        cout << endl << temp;
        StarCalcNeg(temp, star);
        OutputNeg(temp, star);
        StarOutputNeg(star, i);
        cout << "|";
    }
}
void StarCalc(int temp, int& star){
    int starR;
    star = temp / 3;
    starR = temp % 3;
    if (starR == 2)
        star = star + 1;
}
void StarCalcNeg(int temp, int& star){
    int starR;
    star = -temp / 3;
    starR = -temp % 3;
    if (starR == 2)
        star = star + 1;
}
void Output(int temp){ // outputs line under 0
    if (temp < 100 && temp > 9)
        cout << setw(18) << "|";
    if (temp < 10 && temp >= 0)
        cout << setw(19) << "|";
    if (temp < 121 && temp > 99)
        cout << setw(17) << "|";
}
void OutputNeg(int temp, int star){ // out puts line under 0 while leaving character spaces for stars
    if (temp <= -10 && temp >= -30){
        cout << setw(17-star);
    }
    if (temp < 0 && temp >= -9){
        cout << setw(18-star);
    }
}
void StarOutput(int star, int i){ // outputs a star for every value saved in star variable
    for (int i = 1; i <= star; i++)
        cout << "*";
}
void StarOutputNeg(int star, int i){ // outputs a star for every value saved in star variable
    for (int i = 1; i <= star; i++)
        cout << "*";
}

