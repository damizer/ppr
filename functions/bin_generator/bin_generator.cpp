#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

struct RandomNumbers {
    int num1;
    int num2;
    int num3;
};

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Open a binary file for writing
    std::ofstream file("random_numbers.bin", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // Specify the number of records you want in the binary file
    int numRecords = 10; // You can change this number

    for (int i = 0; i < numRecords; ++i) {
        RandomNumbers randomData;
        randomData.num1 = std::rand() % 100;
        randomData.num2 = std::rand() % 100;
        randomData.num3 = std::rand() % 100;

        // Write the struct to the binary file
        file.write(reinterpret_cast<char*>(&randomData), sizeof(RandomNumbers));
    }

    // Close the file
    file.close();

    std::cout << "Binary file generated successfully!" << std::endl;

    return 0;
}

