#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{

    std::vector<float> f2Vec(150,0);

    std::ifstream in{};
    std::ofstream out{};
    std::string str{};
    std::string openf{};

    out.open("atlag.txt");

    float value {};
    int pos{0};


    for (int i = 0; i < 1000; ++i)
    {
        openf = "./eredmenyek/" + std::to_string(i) + "e.txt";
        in.open(openf);

        if (!out) 
            std::cout << "Nem jó";
        if (!in)
        {
            std::cout << "Nem jó";
        }
        else
        {
            while(std::getline(in, str))
            {
                value = atof(str.c_str());
                f2Vec.at(pos) += value; 
                pos++;
            }
        }

        pos = 0;
        in.close();
    }

    for (auto var : f2Vec)
    {
        out << var / 1000 << "\n";
    }    

    out.close();

    std::cin.get();
    return 0;
}