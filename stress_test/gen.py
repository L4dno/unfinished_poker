from random import *
#ранг - число
#масть - буква s,h,d,c
#на строчке рука через пробел
#карта слитно

n = randint(8,25)

ranks = [i for i in range(2,15)]
suits = ['c','d','h','s']

deck = []
for i in ranks:
    for j in suits:
        deck.append([i,j])
shuffle(deck)

forbiden = set()
card_ind = -1
j=0
for i in range(n):#число рук
    while j<5:
        card_ind = randint(0,51)
        if card_ind not in forbiden:
            forbiden.add(card_ind)
            print(deck[card_ind][0], deck[card_ind][1],sep='', end = ' ')
            j+=1
    forbiden.clear()
    j=0
    print()
