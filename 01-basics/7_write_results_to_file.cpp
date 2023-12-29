#include <iostream>
#include <fstream>
#include <vector>

// Sample function to generate results
std::vector<double> calculateResults() {
    // Replace this with your actual logic to calculate results
    return {1.2, 3.4, 5.6, 7.8};
}

// Function to write results to a file
void writeResultsToFile(const std::string& filename, const std::vector<double>& results) {
    // Open the file for writing
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return;
    }

    // Write results to the file
    for (const double& result : results) {
        outputFile << result << " ";
    }

    // Close the file
    outputFile.close();

    std::cout << "Results written to file: " << filename << std::endl;
}

int main() {
    // Call the function to calculate results
    std::vector<double> results = calculateResults();

    // Specify the filename where you want to save the results
    std::string filename = "output.txt";

    // Call the function to write results to the file
    writeResultsToFile(filename, results);

    return 0;
}
