#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

int main()
{
    //std::vector<float> f2Vec(10000,0);
    std::map<float, int> f2Map{};
    std::vector<int> esely(1000, 0);

    for (int i{0}; i < 1000; ++i)
        f2Map[i] = 0;

    std::ifstream in{};
    std::ofstream out{};
    std::ofstream out2{};
    std::string str{};
    std::string openf{};

    out.open("./esely.txt");
    out2.open("./eloszlas.txt");

    float value {};
    int pos{0};

    if (!out) 
            std::cout << "Nem jó";
        else
            perror("Creating output file");

     if (!out2) 
            std::cout << "Nem jó";
        else
            perror("Creating output2 file");


    for (int i = 0; i < 100; ++i)
    {
        openf = "./results/res_" + std::to_string(i) + ".txt";
        in.open(openf);

        if (!in)
        {
            std::cout << "Nem jó";
        }
        else
        {
            perror("Opening input file");

            while(std::getline(in, str))
            {
                value = atoi(str.c_str());
                esely.at(pos) += value;
                f2Map[value]++;
                pos++;
            }
        }

        pos = 0;
        in.close();
    }

    int db{0};
    for (auto var : esely)
    {
        out << db << "\t" << ((float)var / 100) / 1000 * 100 << std::endl;
        ++db;
    }

    for (auto var : f2Map)
    {
        if (logf(var.first) == -INFINITY)
            out2 << 0 << "\t";
        else 
            out2 << logf(var.first) << "\t";

        if (logf(var.second / 100) == -INFINITY)
            out2 << 0 << "\n";
        else
            out2 << logf(var.second / 100 ) << "\n";
    }

    perror("Write the avg + sum values in the output file");

    out.close();
    out2.close();

    std::cout << "A program lefutott";
    std::cin.get();
    return 0;
}