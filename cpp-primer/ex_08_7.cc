#include "ex_07_12_Sales_data.h"
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <file1> <file2>" << std::endl;
        return -1;
    }
    Sales_data total; 
    Sales_data trans; 
    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2], std::ofstream::app);

    read(inputFile, total);
    while (read(inputFile, trans))
    {
        if (total.isbn() == trans.isbn())
        {
            total.combine(trans);
        }
        else 
        { 
            print(outputFile, total) << endl;
            total = trans;
        }
    }
    print(outputFile, total) << endl;
    return 0;
}
