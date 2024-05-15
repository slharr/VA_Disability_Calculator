C++ code that accepts user input of a (disability) name and (percentage) decimal integer and then places each input into an array.
Prompts user to type x when done (not case sensitive).
Program then takes all numbers and sorts them highest to lowest value in array, keeping names sorted with corresponding number.
Goes through the sorted array number by number.
FinalValue becomes the first number. A remainder value is then taken by subtracting the first number from 100.
The next number becomes a percentage and is multiplied by the remainder and that value is stored as the new finalValue.
Each number is repeated in the same manner. Example: input of 30, 20, 20 would make finalValue = 55.
The program will then print out every name and number of the array in two columns.
Then give the finalValue as cout << "Final Percentage : " << finalValue;
The function calculateFinalValue is used to do the calculation.
