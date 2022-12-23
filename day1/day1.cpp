#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// parser for input
int parser(std::string input_file)
{
    std::ifstream fs{input_file};
    int most_calories{0};
    int accumulated_calories{0};

    while (fs)
    {
        std::string line;
        std::getline(fs, line);
        
        if(line.empty())
        {
            if(accumulated_calories  > most_calories)
            {
                most_calories = accumulated_calories;
            }
            accumulated_calories = 0;
            continue;
        }
        accumulated_calories += std::stoi(line);
    }
    return most_calories;
}


int main(int argc, char const *argv[])
{
    std::string input{"/home/lukas/Documents/prog/aoc_2022/day1/input"};
    std::cout << input << '\n';
    std::cout << "most calories: " << parser(input) << '\n';

    return 0;
}
