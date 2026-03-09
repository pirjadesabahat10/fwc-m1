kmap = [
[0,1,0,0],
[0,1,1,1],
[1,1,1,0],
[0,0,1,0]
]

print("Cells with value 1:")

for i in range(4):
    for j in range(4):
        if kmap[i][j] == 1:
            print("1 at row", i, "column", j)

print("\nMinimal SOP Expression:")
print("P'QS' + PRS + QRS + P'RS + PQR'")

print("\nCorrect Option: (b)")
