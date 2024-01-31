#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "card.hpp"

Comb StrongestValueNaive(std::vector<Card>& hand) {
    sort(hand.rbegin(), hand.rend());
    std::map<int, int> rankToCount;

    bool hasFlush = true;
    bool hasStraight = true;
    Card previous = hand[0];
    rankToCount[previous.rank] += 1;

    for (int i = 1; i < 5; ++i) {
        if (hand[i].suit != previous.suit) {
            hasFlush = false;
        }
        if (hand[i].rank + 1 != previous.rank) {
            hasStraight = false;
        }
        rankToCount[hand[i].rank] += 1;
        previous = hand[i];
    }

    if (hasFlush && hasStraight) {
        if (hand[0].rank == 14) {
            return Comb::kRoyalFlush;
        }
        else {
            return Comb::kStraightFlush;
        }
    }
    else if (hasFlush) {
        return Comb::kFlush;
    }
    else if (hasStraight) {
        return Comb::kStraight;
    }
    else if (rankToCount.size() == 2) {
        if (rankToCount.begin()->second == 4 ||
            rankToCount.begin()->second == 1) {
            return Comb::kFourKind;
        }
        else {
            return Comb::kFullHouse;
        }
    }
    else if (rankToCount.size() == 3) {
        if (rankToCount.begin()->second == 2 ||
            (++rankToCount.begin())->second == 2) {
            return Comb::kTwoPair;
        }
        else {
            return Comb::kThreeKind;
        }
    }
    else if (rankToCount.size() == 4) {
        return Comb::kPair;
    }
    else {
        return Comb::kHigh;
    }
}




int main()
{
    Card tmp{13, Suit::kSpide};
    std::cout << tmp;

    return 0;
}