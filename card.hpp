#include <string>

enum class Comb {
    kFourKind = 0,
    kStraightFlush = 1,
    kStraight = 2,
    kFlush = 3,
    kHigh = 4,
    kPair = 5,
    kTwoPair = 6,
    kRoyalFlush = 7,
    kThreeKind = 8,
    kFullHouse = 9
};

enum class Suit {
    kUnknown = -1,
    kClub = 1,
    kDiamond = 2,
    kHeart = 4,
    kSpide = 8
};

struct Card {
    int rank = -1;
    Suit suit = Suit::kUnknown;
};

std::string RankToStr(int rank) {
    //���� ���� ����������� �� ����������
    if (rank <= 10) {
        return std::to_string(rank);
    }
    else {
        switch (rank) {
        case 11: return "J";
        case 12: return "Q";
        case 13: return "K";
        case 14: return "A";
        }
    }
}

char SuitToChar(Suit suit) {
    //����������
    switch (suit) {
    case Suit::kClub: return 'c';
    case Suit::kDiamond: return 'd';
    case Suit::kHeart: return 'h';
    case Suit::kSpide: return 's';
    }
}

Suit CharToSuit(const char symb) {
    //����������
    switch (symb) {
    case 'c':return Suit::kClub;
    case 'd':return Suit::kDiamond;
    case 'h': return Suit::kHeart;
    case 's':return Suit::kSpide;
    }
}

std::ostream& operator<<(std::ostream& os, const Card card) {
    os << RankToStr(card.rank) << SuitToChar(card.suit);
    return os;
}

std::istream& operator>>(std::istream& is, Card& card) {
    char suit = ' ';
    is >> card.rank >> suit;
    card.suit = CharToSuit(suit);
    return is;
}

int GetSuit(Card card) {
    //���� ���������� �� ����������
    switch (card.suit) {
    case Suit::kClub: return 1;
    case Suit::kDiamond: return 2;
    case Suit::kHeart: return 4;
    case Suit::kSpide: return 8;
    }
}

bool operator<(const Card lhs, const Card rhs) {
    //return lhs.suit < rhs.suit;
    return lhs.rank < rhs.rank;
}

//��� ��������� ������ �� ����� ����� ����� �����

//int GetRank(const char rank) {
//    switch (rank) {
//    case 'A': return 14;
//    case 'K': return 13;
//    case 'Q': return 12;
//    case 'J': return 11;
//    default: return rank - '0';
//    }
//}

void foo() noexcept;