#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>

float countNu(int m, int n,std::string str, int x, int y, int x1, int y1)//передавать размер
{
    int ch;
    float ch1;

    /*std::stringstream str(argv[1]);
    std::stringstream str1(argv[2]);
    str >> m;
    str1 >> n;
    std::cout << m << std::endl;
    std::cout << n << std::endl;*/

    bool flag = false; // чтобы считать нужную информацию
    std::vector<float>arr;

    double lambda[11];
    lambda[0] = 0.0244;
    lambda[1] = 0.0251;
    lambda[2] = 0.0259;
    lambda[3] = 0.0267;
    lambda[4] = 0.0276;
    lambda[5] = 0.0283;
    lambda[6] = 0.029;
    lambda[7] = 0.0296;
    lambda[8] = 0.0305;
    lambda[9] = 0.0313;
    lambda[10] = 0.0321;

    double nu[11];
    nu[0] = 13.28 * pow(10, -6);
    nu[1] = 14.16 * pow(10, -6);
    nu[2] = 15.06 * pow(10, -6);
    nu[3] = 16 * pow(10, -6);
    nu[4] = 16.96 * pow(10, -6);
    nu[5] = 17.95 * pow(10, -6);
    nu[6] = 18.97 * pow(10, -6);
    nu[7] = 20.02 * pow(10, -6);
    nu[8] = 21.09 * pow(10, -6);
    nu[9] = 22.1 * pow(10, -6);
    nu[10] = 23.13 * pow(10, -6);

    double a_gas[11];
    a_gas[0] = 18.8 * pow(10, -6); //0
    a_gas[1] = 20 * pow(10, -6); //10 
    a_gas[2] = 21.4 * pow(10, -6);
    a_gas[3] = 22.9 * pow(10, -6);
    a_gas[4] = 24.3 * pow(10, -6);
    a_gas[5] = 25.7 * pow(10, -6);
    a_gas[6] = 27.2 * pow(10, -6);
    a_gas[7] = 28.6 * pow(10, -6);
    a_gas[8] = 30.2 * pow(10, -6);
    a_gas[9] = 31.9 * pow(10, -6);
    a_gas[10] = 33.6 * pow(10, -6);

    double betta[11];
    betta[0] = 0.36 * pow(10, -2); //0
    betta[1] = 0.35 * pow(10, -2); //10 
    betta[2] = 0.34 * pow(10, -2);
    betta[3] = 0.33 * pow(10, -2);
    betta[4] = 0.32 * pow(10, -2);
    betta[5] = 0.31 * pow(10, -2);
    betta[6] = 0.3 * pow(10, -2);
    betta[7] = 0.29 * pow(10, -2);
    betta[8] = 0.28 * pow(10, -2);
    betta[9] = 0.27 * pow(10, -2);
    betta[10] = 0.26 * pow(10, -2);
    int width_plate = m, lenght_plate = n;
    int k = 0, c, c1;
    double p, q, d, d1, T1, Qizl1, Qel1, Ra1, har_len = 0.022, Ra21, Qck1, Qck2, Qw1, Nu1, diameter = 1, Alpha1;
    double g = 9.8;
    double T0 = 273.15;
    double sigma = 5.67 * pow(10.0, -8);
    double epsilon_material = 0.19;
    double epsilon_kraska = 0.96;
    double c_p = 1005;
    double Pr = 0.7;
    double viscosity = 0.0259;
    std::ofstream MyFile("filename.txt");
    std::string word;
    
    
    double** table_in_begin_parametr = new double* [1];
    std::ifstream infile("C:\\Users\\Asus\\source\\repos\\GUI1\\GUI1\\Project\\table_in_c.txt");
    std::string line;

    
    int j = 0;
    char* tok = new char[13];
    const int strlen = 50;
    //double** table_in_begin_parametr = (double**)(malloc(sizeof(double*)));
    for (int i = 0; i < 10; i++)//initializing array
    {
        table_in_begin_parametr[i] = new double[15];
        if (getline(infile, line))
        {
            //const int strlen = line.length() + 1;
            char line1[strlen];
            strcpy(line1, line.c_str());
            tok = strtok(line1, " ");
            while (tok) {
                table_in_begin_parametr[i][0] = atof(tok);
                tok = std::strtok(nullptr, " ");
                table_in_begin_parametr[i][9] = atof(tok);
                tok = std::strtok(nullptr, " ");
                table_in_begin_parametr[i][4] = atof(tok);
                tok = std::strtok(nullptr, " ");
                
                table_in_begin_parametr[i][7] = atof(tok);
                tok = std::strtok(nullptr, " ");
                table_in_begin_parametr[i][12] = atof(tok);
                
                tok = std::strtok(nullptr, " ");
                table_in_begin_parametr[i][13] = atof(tok);

                tok = std::strtok(nullptr, " ");
                tok = std::strtok(nullptr, " ");
                tok = std::strtok(nullptr, " ");
                tok = std::strtok(nullptr, " ");
                table_in_begin_parametr[i][11] = atof(tok);
                tok = std::strtok(nullptr, " ");
                table_in_begin_parametr[i][10] = atof(tok);
            }

            
            

        }
        
    }
    std::ifstream in(str, std::ios::binary);
    while (in.read((char*)&ch, sizeof(int)))
    {
        if (ch == m)
        {
            in.read((char*)&ch, sizeof(int));
            if (ch ==n)
            {
                if (flag)
                {
                    for (int i = 0;i < n * m;i++)
                    {

                        in.read((char*)&ch1, sizeof(float));
                        arr.push_back(ch1);
                    }
                    break;
                }
                flag = true;
            }
        }
    }
    in.close();
    for (int j = 0;j < 1;j++)
    {
        for (int i = x+y*m;i < x1*n+y1;i++)
        {


            p = (i - table_in_begin_parametr[k][10]) * table_in_begin_parametr[k][14];

            /*for (int j = 0;j < 1;j++)
            {
                q = (j - table_in_begin_parametr[k][11]) * table_in_begin_parametr[k][14];
            }*/
            c = int((arr[i] - 1.0 / 3.0 * table_in_begin_parametr[k][9]) / 10.0); // коэффициенты меняются каждые десять градусов
            d = (arr[i] - 1.0 / 3.0 * table_in_begin_parametr[k][9]) / 10.0 - c;
            T1 = arr[i];
            Qizl1 = sigma * epsilon_kraska * (pow((T0 + arr[i]), 4) - pow((T0 + table_in_begin_parametr[k][9]), 4)) + sigma * epsilon_material * (pow((T0 + arr[i]), 4) - pow((T0 + table_in_begin_parametr[k][9]), 4));
            c1 = int((arr[i] - 1.0 / 3.0 * table_in_begin_parametr[k][9]) / 10.0);
            d1 = (arr[i] - 1.0 / 3.0 * table_in_begin_parametr[k][9]) / 10.0 - c;
            Qel1 = table_in_begin_parametr[k][7] / (width_plate * lenght_plate); // not weight!!1 
            //Ra1 = (betta[c] + (betta[c + 1] - betta[c]) * d) * g * Qel1 * pow(har_len, 4) / (lambda[c] + (lambda[c + 1] - lambda[c]) * d) / (nu[c] + (nu[c + 1] - nu[c]) * d) / (a_gas[c] + (a_gas[c + 1] - a_gas[c]) * d); // вместо 0.022 задавать характеристическую длину как параметр
            Ra1 = (2 * g * (arr[i] - table_in_begin_parametr[k][6]) * pow(har_len, 3)) / ((arr[i] - table_in_begin_parametr[k][6]) * (nu[c] + (nu[c + 1] - nu[c]) * d) * (a_gas[c] + (a_gas[c + 1] - a_gas[c]) * d));
            //Ra1 = (2*(betta[c] + (betta[c + 1] - betta[c]) * d) * g * Qel1 * pow(har_len, 4))/ ((arr[i] - table_in_begin_parametr[k][6]) * (nu[c] + (nu[c + 1] - nu[c]) * d) * (a_gas[c] + (a_gas[c + 1] - a_gas[c]) * d));
            Ra21 = Ra1;
            //Ra = 2.0 * g * (x[i][j] - table_in_begin_parametr[k][6]) * pow(0.022, 3) / (x[i][j] + table_in_begin_parametr[k][6] + 2.0 * T0) / (nu[c] + (nu[c + 1] - nu[c]) * d) / (a_gas[c] + (a_gas[c + 1] - a_gas[c]) * d); // nu - вязкость    
            //Ra2 = 2.0 * g * (x[i][j] - table_in_begin_parametr[k][6]) * pow(0.022, 3) / (x[i][j] + table_in_begin_parametr[k][6] + 2.0 * T0) / (nu[c1] + (nu[c1 + 1] - nu[c1]) * d1) / (a_gas[c1] + (a_gas[c1 + 1] - a_gas[c1]) * d1);
            Qck1 = 0.508 * (lambda[c] + (lambda[c + 1] - lambda[c]) * d) * (arr[i] - table_in_begin_parametr[k][9]) * pow((Ra1 * Pr / (0.952 + Pr)), 0.25) / har_len;
            Qck2 = 0.508 * (lambda[c1] + (lambda[c1 + 1] - lambda[c1]) * d1) * (arr[i] - table_in_begin_parametr[k][9]) * pow((Ra21 * Pr / (0.952 + Pr)), 0.25) / har_len;
            Qw1 = Qel1 - Qizl1 - Qck1 - Qck2;
            // Write to the file
            
            //std::cout << Qw1 << std::endl;
            if (Qw1 < 0) {
                Qw1 = 0;
            }
            Nu1 = diameter * (Qw1) / (T1 - table_in_begin_parametr[k][9]) / (lambda[c] + (lambda[c + 1] - lambda[c]) * d);
            MyFile << Nu1;
            MyFile << " ";
            Alpha1 = Qw1 / (T1 - table_in_begin_parametr[k][6]);


            
        }
        k++;
    }
    MyFile.close();
    return Qw1;
    //for (int i = 0;i < 10;i++)
      //  std::cout << arr[i] << std::endl;
}
