#include <iostream>
#include <fstream>

struct RandomNumbers {
    int num1;
    int num2;
    int num3;
};

int main() {
    // Open the binary file for reading
    std::ifstream file("random_numbers.bin", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    // Read the data from the binary file
    RandomNumbers randomData;
    //int randomData[3];

    while (file.read(reinterpret_cast<char*>(&randomData), sizeof(RandomNumbers))){
        std::cout << "Number 1: " << randomData.num1 << std::endl;
        std::cout << "Number 2: " << randomData.num2<< std::endl;
        std::cout << "Number 3: " << randomData.num3<< std::endl;
        std::cout << "-------------------" << std::endl;
    }

    // Close the file
    file.close();

    return 0;
}

