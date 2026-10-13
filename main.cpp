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

    std::string data_group[5];

    std::string::size_type start = 0;

    for (int i = 0; i < 4; i++)
    {
        std::string::size_type comma = line.find(',', start);
        
        if (comma == std::string::npos)
            {
                std::cout << "Invalid line in file.\n";
                return 1;
            }
        
        data_group[i] = line.substr(start, comma - start);
        start = comma + 1;
    }

    data_group[4] = line.substr(start);
        
    }

    return 0;
    
}
