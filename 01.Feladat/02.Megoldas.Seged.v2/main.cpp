#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <math.h>

int main()
{
    std::vector<int> eselyVector(1000,0);
    std::map<int, int> eloszlasMap{};

    std::ifstream inAdatok{};
    
    std::ofstream outEsely{"./outEsely.txt"};
    std::ofstream outEloszlas{"./outEloszlas.txt"};

    std::string inputs{};
    std::string tmp{};

    int count{};
    int neighbour{};
    int count2{};

    for (int i = 0; i < 100; ++i)
    {
        inputs = "./results/res_" + std::to_string(i) + ".txt";
        inAdatok.open(inputs);

        if (!inAdatok)
        {
            std::cout << "Nem jó";
        }
        else
        {
            perror("Opening input file");

            while(std::getline(inAdatok, tmp))
            {
                neighbour = atoi(tmp.c_str());
                eloszlasMap[neighbour]++;
                eselyVector.at(count2) += neighbour;
                ++count2;
            }

            count2 = 0;
        }

        inAdatok.close();
    }

    for (auto var : eloszlasMap)
    {
        /*if (logf(var.first) == -INFINITY)
            outEloszlas << 0 << "\t";
        else*/ 
            outEloszlas << /*logf(*/var.first/*) */<< "\t";

        /*if (logf(var.second / 100) == -INFINITY)
            outEloszlas << 0 << "\n";
        else*/
            outEloszlas << /*logf(*/(float)var.second / 100  << "\n";
    }

    for (auto var : eselyVector)
    {
        /*if (logf(var.first) == -INFINITY)
            outEloszlas << 0 << "\t";
        else*/ 
            outEsely << logf((float)count) << "\t";

        /*if (logf(var.second / 100) == -INFINITY)
            outEloszlas << 0 << "\n";
        else*/
            outEsely << logf(((float)var / 100) / 1000 * 100) << "\n";

            ++count;
    }

    outEsely.close();
    outEloszlas.close();

    std::cin.get();
    return 0;
}