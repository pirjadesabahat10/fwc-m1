print("AND gate using MUX (S=A, I0=0, I1=B)")
for A in [0,1]:
    for B in [0,1]:
        Y = 0 if A==0 else B
        print(A,B,"-",Y)
print("\nXOR gate using MUX (S=A, I0=B, I1=B')")
for A in [0,1]:
    for B in [0,1]:
        Y = B if A==0 else 1-B
        print(A,B,"-",Y)
print("\nAnswer: AND = 1 MUX, XOR = 1 MUX")
print("Correct option: (C) 1 and 1")
