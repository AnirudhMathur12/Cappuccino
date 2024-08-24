// Copyright (C) 2024 Anirudh Mathur

#include "utils.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::string read_file(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file!" << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}
