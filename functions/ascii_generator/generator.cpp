#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Open a CSV file for writing
    std::ofstream file("random_numbers.csv");

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // Specify the number of rows you want in the CSV file
    int numRows = 5000; // You can change this number
    int rank = 1000;
    int r;
    for (int i = 0; i < numRows; ++i) {
        // Generate three random numbers
        for (int j = 0; j < rank-1; j++){
            r = std::rand() % 100;
            file << r << ",";
        }
        file << std::rand() % 100 << "\n";
        
    }

    // Close the file
    file.close();

    std::cout << "CSV file generated successfully!" << std::endl;

    return 0;
}

