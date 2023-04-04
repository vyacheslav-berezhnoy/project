#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>

int main()
{
    int x,n,m;
    m = 640;
    n = 480;
    bool k = false;
    std::vector<int>mass;
    mass.clear();
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

                        in.read((char*)&x, sizeof(int));
                        mass.push_back(x);
                    }
                    break;
                }
                k = true;
            }
        }
        
    }
    in.close();
    for (int i = 0;i < 10;i++)
        std::cout << mass[i]<<std::endl;
    return 0;
}