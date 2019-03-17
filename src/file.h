#include <vector>
#include <fstream>
#include <filesystem>

#ifndef FILE_H
#define FILE_H

namespace lak
{
    std::vector<uint8_t> LoadFile(
        const std::filesystem::path &path
    );

    bool SaveFile(
        const std::filesystem::path &path,
        const std::vector<uint8_t> &data,
        const std::ios_base::openmode flags = std::ios::trunc
    );
}

#endif // FILE_H