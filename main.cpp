#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "pixel.h"

// step 4 first function
void average_colors(std::vector<Pixel> &pixel_list)
{
    double total_r = 0;
    double total_g = 0;
    double total_b = 0;
    
    for (const Pixel& pixel : pixel_list)
    {
        total_r += pixel.r;
        total_g += pixel.g;
        total_b += pixel.b;
    }

    std::cout << "average reds: " << total_r / pixel_list.size() << "\n";
    std::cout << "average greens: " << total_g / pixel_list.size() << "\n";
    std::cout << "average blues: " << total_b / pixel_list.size() << "\n";
}

// step 4 second function 
void flip_vertically(std::vector<Pixel> &pixel_list)
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height / 2; y++)
        {
            int first = x * height + y;
            int opposite = x * height + (height - 1 - y);

            float temp = pixel_list[first].r;
            pixel_list[first].r = pixel_list[opposite].r;
            pixel_list[opposite].r = temp;

            temp = pixel_list[first].g;
            pixel_list[first].g = pixel_list[opposite].g;
            pixel_list[opposite].g = temp;

            temp = pixel_list[first].b;
            pixel_list[first].b = pixel_list[opposite].b;
            pixel_list[opposite].b = temp;
        }
    }
}

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
