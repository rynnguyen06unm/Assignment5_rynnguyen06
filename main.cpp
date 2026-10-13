#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "pixel.h"

int main(int argc, char* argv[]) // step 3 cmd line argument 
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

    // step 3 parseing lines
    while (std::getline(input_file, line))
    {
        if (line.empty())
        {
            continue;
        }

    std::string data_group[5];

    std::string::size_type start = 0;

    // step 3 grabbing values between commas
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

    // step 3 loading every pixel into object
    Pixel pixel;
    pixel.x = std::stoi(data_group[0]);
    pixel.y = std::stoi(data_group[1]);
    pixel.r = std::stof(data_group[2]);
    pixel.g = std::stof(data_group[3]);
    pixel.b = std::stof(data_group[4]);
    pixel_list.push_back(pixel);
        
    }

    input_file.close();
    std::cout << "pixels loaded: " << pixel_list.size() << "\n";
    
    return 0;
    
}
