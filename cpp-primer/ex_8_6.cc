#include "ex_7_12.h"
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file1>" << std::endl;
        return -1;
    }
    Sales_data total; 
    Sales_data trans; 
    std::ifstream inputFile(argv[1]);

    read(inputFile, total);
    while (read(inputFile, trans))
    {
        if (total.isbn() == trans.isbn())
        {
            total.combine(trans);
        }
        else 
        { 
            print(cout, total) << endl;
            total = trans;
        }
    }
    print(cout, total) << endl;
    return 0;
}
