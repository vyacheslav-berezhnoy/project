#pragma once
#include <iostream>
#include <fstream>

void Bmtextractor(std::string str) {
    std::ifstream in;
    std::ofstream out;
    in.open(str, std::ios::binary);
    out.open("image.bmp", std::ios::binary);
    char buffer[4];
    in.read(buffer, 2);
    out.write(buffer, 2);
    in.read(buffer, 4);
    out.write(buffer, 4);
    uint32_t size = *(reinterpret_cast<uint32_t*>(buffer));
    char* buff = new char[size];
    in.read(buff, size);
    out.write(buff, size);
    in.close();
    out.close();
    delete [] buff;
    //return 0;
}
