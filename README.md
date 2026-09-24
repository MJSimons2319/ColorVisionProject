# The Illuminatory Enigma

## Description

**version 1.0**

This program takes two sets of user provided RGB values, and converts them to their respective 
relative luminance values prior to comparing them. It then relays the information to the user via which threshold, if any, 
the ratio exceeds per Web Content Accessibility Requirements.

## Michael J. Simons

## Example

To run the program, give the following commands:

g++ main.cpp

./a.out

Here is an example of the program running:

Please enter the RGB values for the first color in your palette.
R: 67
G: 260
B: 58
Your entry isn't a valid intensity, please double check and re-enter.
Please enter the RGB values for the first color in your palette.
R: 67
G: 250
B: 58
The values look good, so lets get down to the math.
Your relative luminance for your first color palette is: 0.6987
Please enter the RGB values for the next color in your palette.
R: 102
G: 289
B: 45
Your entry isn't a valid intensity, please double check and re-enter.
Please enter the RGB values for the next color in your palette.
R: 102
G: 189
B: 45
The values look good, so lets get down to the math.
The contrast between these two colors is not high enough. You may need to go back to the drawing board.
Would you like to compare a new color to your base color?
Y-Yes
N-No
N




