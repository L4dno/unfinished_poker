#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>
//#include <doctest/doctest.h>
#include <utility>
#include "card.hpp"

void GenSubSet(int digits_left, int ones_left, 
               std::vector<std::vector<int>>& masks) {
    static std::vector<int> prefix;
    if (digits_left < ones_left) {
        return;
    }
    if (digits_left == 0) {
        masks.push_back(prefix);
        return;
    }
    prefix.push_back(0);
    GenSubSet(digits_left - 1, ones_left, masks);
    prefix.pop_back();
    if (ones_left > 0) {
        prefix.push_back(1);
        GenSubSet(digits_left - 1, ones_left - 1, masks);
        prefix.pop_back();
    }
}

std::pair<Comb, int> StrongestValue(const std::vector<Card>& hand) {
    //����������
    int unique_ranks = 0;
    long long ranks_count = 0;
    const int kFourBitMask = 15;
    const long long kRankSectorSize = 4;
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
    //���� �� � ������� �����, ������������ � ����? 
    bool straight_cond_two = unique_ranks == 0x403c;

    int res_ind = ranks_count % 15 - ((straight_cond_one ||
        straight_cond_two) ? 3 : 1);

    if (0 != hasFlush) {
        //����������, ����� ������ ���������� - ��������
        res_ind -= ((unique_ranks == 0x7c00) ? -5 : 1);
    }

    return std::make_pair(static_cast<Comb>(res_ind), ranks_count);
}

bool CompareHands(const std::vector<Card>& lhs, 
                    const std::vector<Card>& rhs) {
    
}

