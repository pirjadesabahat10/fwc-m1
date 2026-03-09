gates = ["NOT", "OR", "AND", "XNOR", "NOR", "NAND", "XOR"]

for gate in gates:
    print("Checking:", gate)

    if gate == "NAND" or gate == "NOR":
        print(gate, "is a Universal Gate")

print("Option C is Correct: NAND and NOR")

