/*
Created by Stephen Harr 5-15-2024
C++ code that accepts user input of a (disability) name and (percentage) decimal integer and then places each input into an array.
Prompts user to type x when done (not case sensitive).
Program then takes all numbers and sorts them highest to lowest value in array, keeping names sorted with corresponding number.
Goes through the sorted array number by number.
finalValue becomes the first number. A remainder value is taken by subtracting the first number from 100.
The next number becomes a percentage and is multiplied by the remainder and that value is stored as the new finalValue.
Each number is repeated in the same manner. Example: input of 30, 20, 20 would make finalValue = 55.
The program will then print out every name and number of the array in two columns.
Then give the finalValue as cout << "Final Percentage : " << finalValue;
The function calculateFinalValue is used to do the calculation.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;
// Custom data structure to store name and percentage
struct Disability {
    string name;
    double percentage;
};

// Function to calculate the final value
double calculateFinalValue(const vector<Disability>& sortedDisabilities) {
    if (sortedDisabilities.empty()) {
        cerr << "Error: Input is empty." << endl;
        return 0.0; // Return a default value (adjust as needed)
    }
    double finalValue = sortedDisabilities[0].percentage;
    double remainder = 100.0 - finalValue;
    for (size_t i = 1; i < sortedDisabilities.size(); ++i) {
        double percentage = sortedDisabilities[i].percentage / 100.0;
        finalValue += percentage * remainder;
        remainder = 100.0 - finalValue;
    }
    return finalValue;
}

int main() {
    vector<Disability> disabilities;
    string name;
    double percentage;

    // Input loop
    while (true) {
        cout << "Enter the disability name (or 'x' to finish): ";
        getline(cin, name);

        // Convert input to lowercase for case-insensitive comparison
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if (name.empty()) { // Check if the name is empty
            cout << "Please enter a valid disability description." << endl;
            continue; // Skip the rest of the loop iteration
        }
        if (name == "x") {
            break;
        }
        cout << "Enter the percentage (decimal allowed): ";
        cin >> percentage;
        cin.ignore();

        disabilities.push_back({ name, percentage });
    }

    // Sort the disabilities by percentage in descending order
    // Use square brackets [] to define a lambda function that compares two Disability objects based on their percentages.
    std::sort(disabilities.begin(), disabilities.end(),
        [](const Disability& a, const Disability& b) { return a.percentage < b.percentage; });
    
    // Calculate the final value, by passing to formula
    double finalValue = calculateFinalValue(disabilities);

    // Print names and percentages
    std::cout << std::setw(10)<< "Disability\tPercentage" << std::endl;
    for (const auto& disability : disabilities) {
        std::cout << std::setw(10) << disability.name << "\t" << disability.percentage << std::endl;
    } // use of #include <iomanip> and std::setw(10) , sets width to size for each column
    
    // Print the final value
    std::cout << "Final VA Disability Percentage (unrounded): " << finalValue << std::endl;
    
    return 0;
}
