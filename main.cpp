#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

const int PALETTE_SIZE = 4;
const int HEXADECIMAL = 16;
const string colorRed = "Red";
const string colorGreen = "Green";
const string colorBlue = "Blue";

string convertToHexCode(int, int, int);
bool hexCodeValidation (string);
bool intensitiesAreValid (int);
int hexCodeToRed (string);
int hexCodeToGreen (string);
int hexCodeToBlue (string);
double intensityToLuminance (int);
void adjustForRelativeLuminance (double&, string);
void checkTheGuidelines (ofstream&,double);

char intensityToHexComponent(int, string);

int main () {
    int userChoice;
    string hexCode;
    vector <string> hexCodePalette;
    ofstream resultOutput;
    resultOutput.open("Results.txt", ios::app);
// Lines 35-110 are the three options user(s) have for inputting a 4-Color color palette to 'hexCodePalette'
        do {
            cout << "Welcome weary traveller to the Illuminatory Enigma.\n";
            cout << "How woud you like to input your color palette today (Enter the number for your choice below)? \n";
            cout << "1.) Manual - RGB Value(s)\n";
            cout << "2.) Manual - Hex Code(s)\n";
            cout << "3.) Automatic - Hex Code(s)\n";
            cin >> userChoice;
            cin.ignore();
        } while (userChoice != 1 && userChoice != 2 && userChoice != 3);

        if (userChoice == 1) {
            cout << "You have chosen to manually enter your RGB value(s).\n";
            for (int paletteCount = 0; paletteCount < PALETTE_SIZE; paletteCount++) {
                int gammaRed1 = 0;
                int gammaGreen1 = 0;
                int gammaBlue1 = 0;
                bool invalidEntry = false;
                
                    do {
                        cout << "Please enter a set of RGB values for your palette.\n";
                        cout << "R: ";
                        cin >> gammaRed1;
                        cout << "G: ";
                        cin >> gammaGreen1;
                        cout << "B: ";
                        cin >> gammaBlue1;
                        if (intensitiesAreValid(gammaRed1) && intensitiesAreValid(gammaGreen1) && intensitiesAreValid(gammaBlue1)) {
                            invalidEntry = true;
                        }   
                        else {
                            cout << "One or more of your intensities are not within the range 0-255. Please try again.\n";
                        }
                        
                    } while (invalidEntry == false);
                    string hexCode = convertToHexCode (gammaRed1, gammaGreen1, gammaBlue1);
                    hexCodePalette.push_back(hexCode);
                }       
        } 
        else if (userChoice == 2) {
            string hexCode;
            cout << "You have chosen to manually input your hex code(s).\n";
                for (int paletteCount = 0; paletteCount < PALETTE_SIZE; paletteCount++) {
                    do {
                        cout << "Please enter a Hex Code for your color palette. (#000000-#FFFFFF)\n";
                        getline(cin,hexCode);
                            if (hexCodeValidation(hexCode)) {
                                hexCodePalette.push_back(hexCode);
                            }
                            else {
                                cout << "This Hex Code is not in the proper format. Please try again.\n";
                            }
                    } while (!hexCodeValidation(hexCode));
                }
        } 
        else if (userChoice == 3) {
            string fileHex;
            fstream paletteReader;
            paletteReader.open("HexCodePalette.txt", ios::in);
                if (paletteReader.is_open()) {
                    for (int filePalette = 0; filePalette < 4; filePalette++) {
                    paletteReader >> fileHex;
                        if (hexCodeValidation(fileHex)) {
                            hexCodePalette.push_back(fileHex);
                            
                        }
                        else {
                            cout << "One of your hex codes could not be validated. Entering default value (#000000), please check your syntax prior to continuing.\n";
                            hexCodePalette.push_back("#000000");
                        }
                    }
                    paletteReader.close();
                }
                else {
                    cout << "The inut file has failed to open.\n";
                }
        }
//This nested for loop performs all possible comparisons for a 4 color palette. (1-2, 1-3, 1-4, 2-3, 2-4, 3-4)
    for (int comparisonCount = 0; comparisonCount < 3; comparisonCount++) {
        string firstHex;
        string secondHex;
        int firstRed = 0;
        int firstGreen = 0;
        int firstBlue = 0;
        int secondRed = 0;
        int secondGreen = 0;
        int secondBlue = 0;
        double luminanceRed1 = 0.0;
        double luminanceGreen1 = 0.0;
        double luminanceBlue1 = 0.0;
        double luminanceRed2 = 0.0;
        double luminanceGreen2 = 0.0;
        double luminanceBlue2 = 0.0;
        double L1 = 0.0;
        double L2 = 0.0;
        double luminanceRatio = 0.0;
        if (comparisonCount == 0) {
            for (int index = 1; index < 4; index ++) {
                resultOutput << "Comparing color 1 ( " << hexCodePalette.at(0) << " ) & color " << index + 1 << " ( " << hexCodePalette.at(index) << " ) " << endl;
                firstHex = hexCodePalette.at(0);
                secondHex = hexCodePalette.at(index);
                firstRed = hexCodeToRed(firstHex);
                firstGreen = hexCodeToGreen(firstHex);
                firstBlue = hexCodeToBlue(firstHex);
                secondRed = hexCodeToRed(secondHex);
                secondGreen = hexCodeToGreen(secondHex);
                secondBlue = hexCodeToBlue(secondHex);
                luminanceRed1 = intensityToLuminance(firstRed);
                luminanceGreen1 = intensityToLuminance(firstGreen);
                luminanceBlue1 = intensityToLuminance(firstBlue);
                luminanceRed2 = intensityToLuminance(secondRed);
                luminanceGreen2 = intensityToLuminance(secondGreen);
                luminanceBlue2 = intensityToLuminance(secondBlue);
                luminanceRed1 = intensityToLuminance(firstRed);
                luminanceGreen1 = intensityToLuminance(firstGreen);
                luminanceBlue1 = intensityToLuminance(firstBlue);
                luminanceRed2 = intensityToLuminance(secondRed);
                luminanceGreen2 = intensityToLuminance(secondGreen);
                luminanceBlue2 = intensityToLuminance(secondBlue);

                adjustForRelativeLuminance(luminanceRed1, colorRed);
                adjustForRelativeLuminance(luminanceGreen1, colorGreen);
                adjustForRelativeLuminance(luminanceBlue1, colorBlue);
                adjustForRelativeLuminance(luminanceRed2, colorRed);
                adjustForRelativeLuminance(luminanceGreen2, colorGreen);
                adjustForRelativeLuminance(luminanceBlue2, colorBlue);

                L1 = luminanceRed1 + luminanceGreen1 + luminanceBlue1;
                L2 = luminanceRed2 + luminanceGreen2 + luminanceBlue2;
                
                if (L1 > L2) {
                    luminanceRatio = (L1 + 0.05) / (L2 + 0.05);
                } else {
                    luminanceRatio = (L2 + 0.05) / (L1 + 0.05);
                }
                checkTheGuidelines(resultOutput, luminanceRatio);
            }
        } 
        else if (comparisonCount == 1) {
            for (int index = 2; index < 4; index++) {
                resultOutput << "Comparing color 2 ( " << hexCodePalette.at(1) << " ) & color " << index + 1 << " ( " << hexCodePalette.at(index) << " ) " << endl;
                firstHex = hexCodePalette.at(1);
                secondHex = hexCodePalette.at(index);
                firstRed = hexCodeToRed(firstHex);
                firstGreen = hexCodeToGreen(firstHex);
                firstBlue = hexCodeToBlue(firstHex);
                secondRed = hexCodeToRed(secondHex);
                secondGreen = hexCodeToGreen(secondHex);
                secondBlue = hexCodeToBlue(secondHex);
                luminanceRed1 = intensityToLuminance(firstRed);
                luminanceGreen1 = intensityToLuminance(firstGreen);
                luminanceBlue1 = intensityToLuminance(firstBlue);
                luminanceRed2 = intensityToLuminance(secondRed);
                luminanceGreen2 = intensityToLuminance(secondGreen);
                luminanceBlue2 = intensityToLuminance(secondBlue);
                luminanceRed1 = intensityToLuminance(firstRed);
                luminanceGreen1 = intensityToLuminance(firstGreen);
                luminanceBlue1 = intensityToLuminance(firstBlue);
                luminanceRed2 = intensityToLuminance(secondRed);
                luminanceGreen2 = intensityToLuminance(secondGreen);
                luminanceBlue2 = intensityToLuminance(secondBlue);

                adjustForRelativeLuminance(luminanceRed1, colorRed);
                adjustForRelativeLuminance(luminanceGreen1, colorGreen);
                adjustForRelativeLuminance(luminanceBlue1, colorBlue);
                adjustForRelativeLuminance(luminanceRed2, colorRed);
                adjustForRelativeLuminance(luminanceGreen2, colorGreen);
                adjustForRelativeLuminance(luminanceBlue2, colorBlue);

                L1 = luminanceRed1 + luminanceGreen1 + luminanceBlue1;
                L2 = luminanceRed2 + luminanceGreen2 + luminanceBlue2;
                
                if (L1 > L2) {
                    luminanceRatio = (L1 + 0.05) / (L2 + 0.05);
                } else {
                    luminanceRatio = (L2 + 0.05) / (L1 + 0.05);
                }
                checkTheGuidelines(resultOutput, luminanceRatio);
            }
        } 
        else if (comparisonCount == 2) {
                resultOutput << "Comparing color 3 ( " << hexCodePalette.at(2) << " ) & color 4 ( " << hexCodePalette.at(3) << " ) " << endl;
                firstHex = hexCodePalette.at(2);
                secondHex = hexCodePalette.at(3);
                firstRed = hexCodeToRed(firstHex);
                firstGreen = hexCodeToGreen(firstHex);
                firstBlue = hexCodeToBlue(firstHex);
                secondRed = hexCodeToRed(secondHex);
                secondGreen = hexCodeToGreen(secondHex);
                secondBlue = hexCodeToBlue(secondHex);
                luminanceRed1 = intensityToLuminance(firstRed);
                luminanceGreen1 = intensityToLuminance(firstGreen);
                luminanceBlue1 = intensityToLuminance(firstBlue);
                luminanceRed2 = intensityToLuminance(secondRed);
                luminanceGreen2 = intensityToLuminance(secondGreen);
                luminanceBlue2 = intensityToLuminance(secondBlue);

                adjustForRelativeLuminance(luminanceRed1, colorRed);
                adjustForRelativeLuminance(luminanceGreen1, colorGreen);
                adjustForRelativeLuminance(luminanceBlue1, colorBlue);
                adjustForRelativeLuminance(luminanceRed2, colorRed);
                adjustForRelativeLuminance(luminanceGreen2, colorGreen);
                adjustForRelativeLuminance(luminanceBlue2, colorBlue);

                L1 = luminanceRed1 + luminanceGreen1 + luminanceBlue1;
                L2 = luminanceRed2 + luminanceGreen2 + luminanceBlue2;
                
                if (L1 > L2) {
                    luminanceRatio = (L1 + 0.05) / (L2 + 0.05);
                } else {
                    luminanceRatio = (L2 + 0.05) / (L1 + 0.05);
                }
                checkTheGuidelines(resultOutput, luminanceRatio);
        
        } 
        else {
            break;
        }
    }
        resultOutput.close();
        cout << "Head over to Results.txt for your results! Thanks for stopping by.\n";
    return 0;
}

string convertToHexCode(int r, int g, int b){
    char poundSign = '#';
    string higherOrder = "Higher";
    string lowerOrder = "Lower";
    char Red = intensityToHexComponent (r, higherOrder);
    char red = intensityToHexComponent (r, lowerOrder);
    char Green = intensityToHexComponent (g, higherOrder);
    char green = intensityToHexComponent (g, lowerOrder);
    char Blue = intensityToHexComponent (b, higherOrder);
    char blue = intensityToHexComponent (b, lowerOrder);
    string Rr = {Red,red};
    string Gg = {Green,green};
    string Bb = {Blue,blue};
    string hexCoded = poundSign + Rr + Gg + Bb;
    
    return hexCoded;
}

bool hexCodeValidation (string userEntry) {
    if (userEntry.size() != 7 || userEntry.at(0) != '#') {
    return false;
    }
    for (size_t hexCharacter = 1; hexCharacter < userEntry.size(); hexCharacter++) {
        if ( !isxdigit(userEntry.at(hexCharacter))) {
            return false;
        }
    }
    return true;
}

bool intensitiesAreValid (int userIntensity){
    if (userIntensity < 0 || userIntensity > 255) {
        return false;
    }
    return true;
}

int hexCodeToRed (string colorCodeR){
  string redHexa = colorCodeR.substr(1, 2);
  int red = stoi(redHexa, nullptr, HEXADECIMAL);

  return red;
}

int hexCodeToGreen (string colorCodeG){
  string greenHexa = colorCodeG.substr(3, 2);
  int green = stoi(greenHexa, nullptr, HEXADECIMAL);

  return green;
}

int hexCodeToBlue (string colorCodeB){
  string blueHexa = colorCodeB.substr(5, 2);
  int blue = stoi(blueHexa, nullptr, HEXADECIMAL);

  return blue;
}
double intensityToLuminance (int intensities){
    double formerIntensity = 0.0;
    formerIntensity = (intensities) / 255.0;
        if ( formerIntensity <= 0.04045) {
                formerIntensity = formerIntensity / 12.92;
        } else {
                formerIntensity = ((formerIntensity + 0.055) / 1.055);
                formerIntensity = pow( formerIntensity, 2.4 );
        }

    return formerIntensity;
}
void adjustForRelativeLuminance (double &luminanceRGB, string colorChoice){
    if (colorChoice == "Red") {
        luminanceRGB = luminanceRGB * 0.2126;
    } 
    else if (colorChoice == "Green") {
        luminanceRGB = luminanceRGB * 0.7152;
    } 
    else if (colorChoice == "Blue") {
        luminanceRGB = luminanceRGB * 0.0722;
    }
}

void checkTheGuidelines (ofstream& results, double ratioValue){
    if ( ratioValue >= 7.0 ) {
        results << "The contrast between these two colors is greater than or equal to 7:1 which is the requirement for Enhanced Accessibilty per Web Content Accessibility Guidelines.\n";
    } else if ( ratioValue >= 4.5 ) {
        results << "The contrast between these two colors is greater than or equal to 4.5:1 which is the minimum recommended level for Digital Content per Web Content Accessibility Guidelines.\n";
    } else if ( ratioValue >= 3.0 ) {
        results << "The contrast between these two colors is greater than or equal to 3.0:1 which is the minimum requirement for large text Digital Content per Web Content Accessibility Guidelines.\n";
    } else {
        results << "The contrast between these two colors is not high enough. You may need to go back to the drawing board.\n";
    }
}

char intensityToHexComponent(int RGB, string order) {
    char componentHex = '0';
    int hexComponent = RGB%16;
        if (order == "Higher") {
            hexComponent = RGB/16;
        }
            switch (hexComponent) {
                case 0:
                    componentHex = '0';
                    return componentHex;
                case 1:
                    componentHex = '1';
                    return componentHex;
                case 2:
                    componentHex = '2';
                    return componentHex;
                case 3:
                    componentHex = '3';
                    return componentHex;
                case 4:
                    componentHex = '4';
                    return componentHex;
                case 5:
                    componentHex = '5';
                    return componentHex;
                case 6:
                    componentHex = '6';
                    return componentHex;
                case 7:
                    componentHex = '7';
                    return componentHex;
                case 8:
                    componentHex = '8';
                    return componentHex;
                case 9:
                    componentHex = '9';
                    return componentHex;
                case 10:
                    componentHex = 'A';
                    return componentHex;
                case 11:
                    componentHex = 'B';
                    return componentHex;
                case 12:
                    componentHex = 'C';
                    return componentHex;
                case 13:
                    componentHex = 'D';
                    return componentHex;
                case 14:
                    componentHex = 'E';
                    return componentHex;
                case 15:
                    componentHex = 'F';
                    return componentHex;
            }

    return componentHex;
}
