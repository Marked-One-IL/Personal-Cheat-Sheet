#include <fstream>
#include <string>
#include <vector>
#include <cassert>

static std::string read_file(const char *path) 
{
    std::ifstream file(path); assert(file);

    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    if (size < 0) {
        return std::string();
    }
    file.seekg(0, std::ios::beg);

    std::string data(static_cast<size_t>(size), '\0');
    file.read(&data[0], size);
    return data;
}
static std::vector<char> read_file_binary(const char *path)
{
    std::ifstream file(path, std::ios::binary); assert(file);

    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    if (size < 0) {
        return std::vector<char>();
    }
    file.seekg(0, std::ios::beg);

    std::vector<char> data(static_cast<size_t>(size), '\0');
    file.read(&data[0], size);
    return data;
}

int main()
{
    auto i = read_file_binary("1.png");
    std::ofstream o("2.png", std::ios::binary | std::ios::trunc);
    
    o.write(&i[0], i.size());

    return 0;
}
