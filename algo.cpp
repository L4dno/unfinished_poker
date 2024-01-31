#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "card.hpp"
#include <bitset>

Comb StrongestValueStrong(std::vector<Card>& hand) {
    //исключения
    int unique_ranks = 0;
    long long ranks_count = 0;
    const int kFourBitMask = 15;
    const int kRankSectorSize = 4;
    long long tmp = 0;
    int hasFlush = (1 << 30) - 1;

    for (int i = 0; i < hand.size(); ++i) {
        unique_ranks |= (1 << hand[i].rank);

        tmp = ranks_count;
        tmp >>= hand[i].rank * kRankSectorSize;
        tmp &= kFourBitMask;
        tmp += 1;
        ranks_count |= (tmp << (hand[i].rank * 4));

        hasFlush &= static_cast<int>(hand[i].suit);
    }

    bool straight_cond_one = unique_ranks / 
        (unique_ranks & (-unique_ranks)) == 31;
    //есть ли в холдеме стрит, начинающийся с туза? 
    bool straight_cond_two = unique_ranks == 0x403c;

    int res_ind = ranks_count % 15 - ((straight_cond_one ||
        straight_cond_two) ? 3 : 1);

    if (0 != hasFlush) {
        //исключение, когда всесто стритфлеша - роялфлеш
        res_ind -= ((unique_ranks == 0x7c00) ? -5 : 1);
    }

    return static_cast<Comb>(res_ind);
}



int main()
{
 
    /*std::string file = "input.txt";
    std::ifstream inp(file.c_str());*/
    std::string line = "";
    std::stringstream istr;
    //std::ofstream outp("output.txt");

    while (std::getline(std::cin, line)) {
        istr.clear();
        istr << line;
        std::vector<Card> hand(5);
        for (int i = 0; i < 5; ++i) {
            istr >> hand[i];
        }
        std::cout << static_cast<int>(StrongestValueStrong(hand))
            << std::endl;
    }

    return 0;
}