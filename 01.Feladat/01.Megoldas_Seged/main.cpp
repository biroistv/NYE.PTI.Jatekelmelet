#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

/*
    Automatikusan megszámlálja az egyes értékek előfordulását és fájlba írja.
*/
int main()
{
    std::ifstream in{};
    std::ofstream out{};
    std::string str{};
    std::vector<std::string> strVector{};
    std::map<std::string, int> uniqMap{};

    in.open("./szamok.txt");    //Ide kell a bejövő txt
    out.open("./jo_szamok.txt");    //Ide a kiemeneti txt

    if (!out) 
        std::cout << "Nem jó";
    if (!in)
    {
        std::cout << "Nem jo\n";
    }
    else
    {
        while(std::getline(in, str))
        {
            strVector.push_back(str);
        }
    }

    for(auto var : strVector)
    {
        uniqMap[var]++;
    }

    for(auto var : uniqMap)
    {   
        out << var.first<< "\t" << var.second << "\n";
    }

    in.close();
    out.close();

    //std::cin.get();
    return 0;
}