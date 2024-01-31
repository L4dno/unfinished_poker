def evaluateHand(cs, ss):
    pokerHands = ["4 of a Kind", "Straight Flush","Straight",
                  "Flush","High Card","1 Pair","2 Pair","Royal Flush",
                  "3 of a Kind","Full House"]

    v = 0
    o=0
    s = 1 << cs[0] | 1 << cs[1] | 1 << cs[2] | 1 << cs[3] | 1 << cs[4]
    
    for i in range(5):
        o = 2**(cs[i] * 4)
        v += o * ((v / o & 15) + 1)
        
    v = v % 15 - (s / (s & -s) == 31) or (3 if (s == 0x403c) else 1)
    v -= (ss[0] == (ss[1] | ss[2] | ss[3] | ss[4])) * (-5 if (s == 0x7c00) else 1)
    return pokerHands[v];


A = 14
K =13
Q=12
J=11
C = 1
S = 2
H = 4
D = 8
print(evaluateHand([A,10,J,K,Q],[C,C,C,C,C]));
## Royal Flush
