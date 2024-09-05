// Copyright (C) 2024 Anirudh Mathur

#include "utils.hpp"

#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

std::optional<std::string> read_file(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open file!" << std::endl;
        return {};
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}
