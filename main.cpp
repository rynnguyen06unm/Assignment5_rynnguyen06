#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "pixel.h"

int main(int argc, char* argv[])
{
    std::vector<Pixel> pixel_list; // step 2 

    std::string filename = argv[1];
    std::ifstream input_file(filename);
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
