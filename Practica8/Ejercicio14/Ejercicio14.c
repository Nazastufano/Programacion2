
/* 14. Una empresa ferroviaria planifica el tendido de vías para unir cinco localidades determinadas.
Para ello cuenta con la siguiente tabla con las distancias entre las mismas. Se solicita diseñar de
la manera más eficiente dicho tendido.

        L1   L2   L3   L4   L5
    L1       5    50   80   90
    L2            70   60   50
    L3                 8    20
    L4                      10

Kruskal
         L1
     
     L2      L3

     L4      L5

(L1,L2):5 x
(L3,L4):8
(L4,L5):10
(L3,L5):20
(L1,L3):50
(L2,L5):50
(L2,L4):60
(L2,L3):70
(L1,L4):80
(L1,L5):90

vcc = [L1, L2, L3, L4, L5]


         L1
      5/
     L2      L3

     L4      L5

(L3,L4):8 x
(L4,L5):10
(L3,L5):20
(L1,L3):50
(L2,L5):50
(L2,L4):60
(L2,L3):70
(L1,L4):80
(L1,L5):90

vcc = [L1, L1, L3, L4, L5]


         L1
      5/
     L2      L3
            / 
         8/
        /
     L4      L5

(L4,L5):10 x
(L3,L5):20
(L1,L3):50
(L2,L5):50
(L2,L4):60
(L2,L3):70
(L1,L4):80
(L1,L5):90


vcc = [L1, L1, L3, L3, L5]


         L1
      5/
     L2      L3
            / 
         8/
        /     
     L4------L5
         10

(L3,L5):20 descartada por bucle
(L1,L3):50 x
(L2,L5):50 
(L2,L4):60
(L2,L3):70
(L1,L4):80
(L1,L5):90

vcc = [L1, L1, L4, L4, L4]

         L1
      5/    \50
     L2      L3
            / 
         8/
        /
     L4------L5
         10
vcc = [L1, L1, L1, L1, L1]

*/