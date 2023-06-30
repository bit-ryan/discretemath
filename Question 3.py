from itertools import permutations

digits = input("Enter a set of digits: ")
repetition = input("Allow repetition? (yes/no): ").lower()

if repetition == "yes":
    perm = permutations(digits)
else:
    perm = permutations(digits, len(digits))

print("Permutations:")
for p in perm:
    print(''.join(p))
