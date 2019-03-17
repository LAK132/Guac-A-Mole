#include "file.h"

namespace lak
{
    std::vector<uint8_t> LoadFile(const std::filesystem::path &path)
    {
        std::ifstream file(path, std::ios::binary | std::ios::ate);

        if (!file.is_open())
            return {};

        std::vector<uint8_t> result;
        result.resize((size_t)file.tellg());

        file.seekg(0);
        file.read(reinterpret_cast<char*>(&(result[0])), result.size());
        file.close();

        return result;
    }

    bool SaveFile(const std::filesystem::path &path, const std::vector<uint8_t> &data, const std::ios_base::openmode flags)
    {
        std::ofstream file(path, std::ios::binary | std::ios::out | flags);

        if (!file.is_open())
            return false;

        file.write(reinterpret_cast<const char*>(&(data[0])), data.size());
        file.close();

        return true;
    }
}