#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    int x, n, m;
    float y;
    
    std::stringstream str(argv[1]);
    std::stringstream str1(argv[2]);
    str >> m;
    str1 >> n;
    std::cout << m << std::endl;
    std::cout << n << std::endl;
    bool k = false; // чтобы считать нужную информацию
    std::vector<float>arr;
    std::ifstream in("IR004872.bmt", std::ios::binary);
    while (in.read((char*)&x, sizeof(int)))
    {
        if (x == m)
        {
            in.read((char*)&x, sizeof(int));
            if (x == n)
            {
                if (k)
                {
                    for (int i = 0;i < n * m;i++)
                    {

                        in.read((char*)&y, sizeof(float));
                        arr.push_back(y);
                    }
                    break;
                }
                k = true;
            }
        }

    }
    in.close();
    for (int i = 0;i < 10;i++)
        std::cout << arr[i] << std::endl;
    return 0;
}
