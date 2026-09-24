#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int gammaRed1;
    int gammaGreen1;
    int gammaBlue1;
    bool invalidEntry1 = true;
    double redsRGB1;
    double greensRGB1;
    double bluesRGB1;
    double linearsRgb1;
    double linearsrGb1;
    double linearsrgB1;
    double y1;
   
    int gammaRed2;
    int gammaGreen2;
    int gammaBlue2;
    bool invalidEntry2 = true;
    double redsRGB2;
    double greensRGB2;
    double bluesRGB2;
    double linearsRgb2;
    double linearsrGb2;
    double linearsrgB2;
    double y2;

    double yRatio;

    char userContinue;
    bool checklistComplete;
    
    do {
        cout << "Please enter the RGB values for the first color in your palette.\n";
        cout << "R: ";
        cin >> gammaRed1;
        cout << "G: ";
        cin >> gammaGreen1;
        cout << "B: ";
        cin >> gammaBlue1;
        if ( gammaRed1 < 0 || gammaRed1 > 255 ) {
            cout << "Your entry isn't a valid intensity, please double check and re-enter.\n";
            invalidEntry1 = false;
            } else if ( gammaGreen1 < 0 || gammaGreen1 > 255 ) {
            cout << "Your entry isn't a valid intensity, please double check and re-enter.\n";
            invalidEntry1 = false;
            } else if ( gammaBlue1 < 0 || gammaBlue1 > 255 ) {
            cout << "Your entry isn't a valid intensity, please double check and re-enter.\n";
            invalidEntry1 = false;
            } else {
            cout << "The values look good, so lets get down to the math.\n";
            invalidEntry1 = true;
            }
        } while (invalidEntry1 == false);
    
    redsRGB1 = gammaRed1 / 255.0;
    greensRGB1 = gammaGreen1 / 255.0;
    bluesRGB1 = gammaBlue1 /255.0;
        if ( redsRGB1 <= 0.03928) {
            linearsRgb1 = redsRGB1 / 12.92;
        } else {
            linearsRgb1 = ((redsRGB1 + 0.055) / 1.055);
            linearsRgb1 = pow( linearsRgb1, 2.4 );
         }
        if ( greensRGB1 <= 0.03928) {
            linearsrGb1 = greensRGB1 / 12.92;
         } else {
            linearsrGb1 = ((greensRGB1 + 0.055) / 1.055);
            linearsrGb1 = pow( linearsrGb1, 2.4);
         }
        if ( bluesRGB1 <= 0.03928) {
            linearsrgB1 = bluesRGB1 / 12.92;
         } else {
            linearsrgB1 = ((bluesRGB1 + 0.055) / 1.055);
            linearsrgB1 = pow( linearsrgB1, 2.4 );
         }
    
    y1 = (0.2126 * linearsRgb1) + (0.7152 * linearsrGb1) + (0.0722 * linearsrgB1);

    cout << "Your relative luminance for your first color palette is: " << y1 << endl;
    /*---------------------------------------------------------------------------------------------------------------------------*/
    do {
        do {
        cout << "Please enter the RGB values for the next color in your palette.\n";
        cout << "R: ";
        cin >> gammaRed2;
        cout << "G: ";
        cin >> gammaGreen2;
        cout << "B: ";
        cin >> gammaBlue2;
        if ( gammaRed2 < 0 || gammaRed2 > 255 ) {
            cout << "Your entry isn't a valid intensity, please double check and re-enter.\n";
            invalidEntry2 = false;
            } else if ( gammaGreen2 < 0 || gammaGreen2 > 255 ) {
            cout << "Your entry isn't a valid intensity, please double check and re-enter.\n";
            invalidEntry2 = false;
            } else if ( gammaBlue2 < 0 || gammaBlue2 > 255 ) {
            cout << "Your entry isn't a valid intensity, please double check and re-enter.\n";
            invalidEntry2 = false;
            } else {
            cout << "The values look good, so lets get down to the math.\n";
            invalidEntry2 = true;
            }
        } while (invalidEntry2 == false);
    
    redsRGB2 = gammaRed2 / 255.0;
    greensRGB2 = gammaGreen2 / 255.0;
    bluesRGB2 = gammaBlue2 /255.0;
        if ( redsRGB1 <= 0.03928) {
            linearsRgb2 = redsRGB2 / 12.92;
        } else {
            linearsRgb2 = ((redsRGB2 + 0.055) / 1.055);
            linearsRgb2 = pow( linearsRgb2, 2.4 );
         }
        if ( greensRGB2 <= 0.03928) {
            linearsrGb2 = greensRGB2 / 12.92;
         } else {
            linearsrGb2 = ((greensRGB2 + 0.055) / 1.055);
            linearsrGb2 = pow( linearsrGb2, 2.4);
         }
        if ( bluesRGB2 <= 0.03928) {
            linearsrgB2 = bluesRGB2 / 12.92;
         } else {
            linearsrgB2 = ((bluesRGB2 + 0.055) / 1.055);
            linearsrgB2 = pow( linearsrgB2, 2.4 );
         }
    
    y2 = (0.2126 * linearsRgb2) + (0.7152 * linearsrGb2) + (0.0722 * linearsrgB2);

    if ( y1 >= y2) {
        yRatio = y1 /y2;
    } else{
        yRatio = y2/y1;
    }
    if ( yRatio >= 7.0 ) {
        cout << "The contrast between these two colors is greater than or equal to 7:1 which is the requirement for Enhanced Accessibilty per Web Content Accessibility Guidelines.\n";
    } else if ( yRatio >= 4.5 ) {
        cout << "The contrast between these two colors is greater than or equal to 4.5:1 which is the minimum recommended level for Digital Content per Web Content Accessibility Guidelines.\n";
    } else if ( yRatio >= 3.0 ) {
        cout << "The contrast between these two colors is greater than or equal to 3.0:1 which is the minimum requirement for large text Digital Content per Web Content Accessibility Guidelines.\n";
    } else {
        cout << "The contrast between these two colors is not high enough. You may need to go back to the drawing board.\n";
    }
    
    cout << "Would you like to compare a new color to your base color?\n";
    cout << "Y-Yes\n";
    cout << "N-No\n";
    cin >> userContinue;

    if ( userContinue == 'Y' ) {
        checklistComplete = false;
    }
    else {
        checklistComplete = true;
    }
    } while (checklistComplete == false);

     
   
    /*  
        https://www.w3.org/WAI/GL/wiki/Relative_luminance
    */    

  return 0;
}
