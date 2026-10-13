#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "pixel.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "missing input filename" << "\n";
        return 1;
    }
    
    std::vector<Pixel> pixel_list; // step 2 
    std::string filename = argv[1];
    std::ifstream input_file(filename);

    if (!input_file.is_open())
    {
        std::cout << "error opening file" << "\n";
        return 1;
    }
    std::string line;
    
    while (std::getline(input_file, line))
    {
        if (line.empty())
        {
            continue;
        }
    }
    
    std::string data_group[5];

        
    return 0;
}
