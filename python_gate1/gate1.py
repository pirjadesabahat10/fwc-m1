A = 1
B = 0
C = 1
A_bar = 1 - A
B_bar = 1 - B
out1 = A_bar or B
out2 = B_bar or C
out3 = out1 or out2
print("A' =", A_bar)
print("B' =", B_bar)
print("Output =", out3)
print("NOT gates = 2")
print("OR gates = 3")
print("Correct Answer: Option (D)")
