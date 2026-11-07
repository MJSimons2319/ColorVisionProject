# The Illuminatory Enigma

## Description

**version 1.0**

This program takes two sets of user provided RGB values, and converts them to their respective 
relative luminance values prior to comparing them. It then relays the information to the user via which threshold, if any, 
the ratio exceeds per Web Content Accessibility Requirements.

**version 2.0**

This updated program now includes the ability for users to upload 4 colors manually via RGB or Hex Codes as well as 
automatically from a .txt file of hex codes. It will then compare and compute the relative luminance ratio for each possible 
combination and inform the user of what guidelines are met. The issue of true black "#000000" or 000-000-000 no longer causes the program
to crash now after further review of the calculation process.

## Michael J. Simons

## Example
ENSURE YOU INLCUDE YOUR TEXT FILE PRE-FILLED WITH HEXCODES OF THE FORM #000000-#FFFFFF prior to selecting option 3.

To run the program, give the following commands:

g++ main.cpp

./a.out

Here is an example of the program running:

How woud you like to input your color palette today (Enter the number for your choice below)? 
1.) Manual - RGB Value(s)
2.) Manual - Hex Code(s)
3.) Automatic - Hex Code(s)

Comparing color 1 ( #000000 ) & color 2 ( #AAAAAA ) 
The contrast between these two colors is greater than or equal to 7:1 which is the requirement for Enhanced Accessibilty per Web Content Accessibility Guidelines.
Comparing color 1 ( #000000 ) & color 3 ( #999999 ) 
The contrast between these two colors is greater than or equal to 7:1 which is the requirement for Enhanced Accessibilty per Web Content Accessibility Guidelines.
Comparing color 1 ( #000000 ) & color 4 ( #FFFFFF ) 
The contrast between these two colors is greater than or equal to 7:1 which is the requirement for Enhanced Accessibilty per Web Content Accessibility Guidelines.
Comparing color 2 ( #AAAAAA ) & color 3 ( #999999 ) 
The contrast between these two colors is not high enough. You may need to go back to the drawing board.
Comparing color 2 ( #AAAAAA ) & color 4 ( #FFFFFF ) 
The contrast between these two colors is not high enough. You may need to go back to the drawing board.
Comparing color 3 ( #999999 ) & color 4 ( #FFFFFF ) 
The contrast between these two colors is not high enough. You may need to go back to the drawing board.




