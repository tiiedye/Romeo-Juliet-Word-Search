![made-with-VisualStudio](https://img.shields.io/badge/Made%20With-Visual%20Studio-ba88f3)  ![Using-CPlusPlus](https://img.shields.io/badge/Using-C%2B%2B-ff69b4)

# Romeo & Juliet Word Search
A simple program that allows you to search for words within the script of Romeo & Juliet. 
This program makes use of fstream to open, read, and close files, and iomanip to add some formatting to the CLI.

<img src="./assets/screenshot.png"
     alt="Img"
     style="margin-right: 10px; height: 400px;" />

### Instructions
Ask the user to enter a word
Process the Romeo and Juliet file and determine how many total words there are
and how many times the word the user entered appears as a substring of a word in the play.

For example.
If the user enters: love
Then the words love, lovely, and beloved will all be considered matches.
You decide whether you want to be case sensitive or not. My solution is case sensitive

Sample are some sample runs:

Enter the substring to search for: love
25919 words were searched...
The substring love was found 171 times

Enter the substring to search for: Romeo
25919 words were searched...
The substring Romeo was found 132 times

Enter the substring to search for: Juliet
25919 words were searched...
The substring Juliet was found 49 times

Enter the substring to search for: Frank
25919 words were searched...
The substring Frank was found 0 times

Have fun!