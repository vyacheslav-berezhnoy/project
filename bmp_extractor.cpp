#include <iostream>
#include <fstream>

int main() {
    std::ifstream in;
    std::ofstream out;
    in.open("heatmap.bmt", std::ios::binary);
    out.open("image.bmp", std::ios::binary);
    char buffer[4];
    in.read(buffer, 2);
    out.write(buffer, 2);
    in.read(buffer, 4);
    out.write(buffer, 4);
    size_t size;
    size = *(reinterpret_cast<size_t*>(buffer));
    char buff[1];
    for (int i = 0; i < size; i++) {
        in.read(buff, sizeof buff);
        out.write(buff, sizeof buff);
    }
    return 0;
}
