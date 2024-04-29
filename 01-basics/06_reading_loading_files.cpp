#include <iostream>
#include <fstream>
#include <string>

#reading a text file and print it line by line 
void readFileLineByLine(const std::string& filename) {
    // Open a file for reading
    std::ifstream inputFile(filename);

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return; // Return without reading if there's an error
    }

    // Read and print the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();
}


// Reading text file and storing into a vector line by line 
std::vector<std::string> readTextFile(const std::string& filename) {
    std::vector<std::string> lines;

    std::ifstream inputFile(filename);
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return lines;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();
    return lines;
}

//data structure that mirrors the format of the binary data in the file
struct DataRecord {
    int id;
    double value;
};

// reading and loading a binary file
std::vector<DataRecord> readBinaryFile(const std::string& filename) {
    std::vector<DataRecord> records;

	//std::ios::binary: This mode is typically used when reading binary data from a file, 
	//as it ensures that the data is read as is without any interpretation.
    std::ifstream inputFile(filename, std::ios::binary);
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file: " << filename << std::endl;
        return records;
    }

    while (inputFile) {   
        DataRecord record;
		// read expects a pointer to char as its first argument.
		//By casting it to char*, you are telling the compiler to 
		//treat the memory of record as a sequence of bytes (char) rather than as a structured type. 
		// sizeof(DataRecord): This specifies the number of bytes to read from the file. 
		//It's the size of the DataRecord structure. The sizeof operator returns the size in bytes
		//of the specified type or object.  The reinterpret_cast is a C++ operator that allows you
		//to convert between different pointer types.
        inputFile.read(reinterpret_cast<char*>(&record), sizeof(DataRecord));

		// inputFile.gcount() : the num of characters read 
        if (inputFile.gcount() == sizeof(DataRecord)) {
            records.push_back(record);
        }
    }

    inputFile.close();
    return records;
}




int main() {

    // Call the function with the file name or path
    readFileLineByLine("example.txt");

	// Example of reading and loading a text file
    std::vector<std::string> textLines = readTextFile("textfile.txt");

    // Process the loaded data as needed
    for (const auto& line : textLines) {
        std::cout << line << std::endl;
    }
	
	
	// Example of reading and loading a binary file
    std::vector<DataRecord> binaryData = readBinaryFile("binaryfile.dat");

    // Process the loaded data as needed
    for (const auto& record : binaryData) {
        std::cout << "ID: " << record.id << ", Value: " << record.value << std::endl;
    }

    return 0;
}






std::ifstream inputFile(filename, std::ios::binary); 
(inputFile.gcount() == sizeof(DataRecord)) {
            records.push_back(record);
        }

