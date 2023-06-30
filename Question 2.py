class Rel:
    def __init__(self, matrix):
        self.matrix = matrix
        self.size = len(matrix)

    def reflexive(self):
        for i in range(self.size):
            if not self.matrix[i][i]:
                return False
        return True

    def transitive(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[i][j]:
                    for k in range(self.size):
                        if self.matrix[j][k] and not self.matrix[i][k]:
                            return False
        return True

    def symmetric(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[i][j] != self.matrix[j][i]:
                    return False
        return True

    def antisymmetric(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[i][j] and self.matrix[j][i] and i != j:
                    return False
        return True

    def find(self):
        equivalence = self.reflexive() and self.symmetric() and self.transitive()
        partial = self.reflexive() and self.antisymmetric() and self.transitive()
        if equivalence:
            return "It is an equivalence relation"
        elif partial:
            return "It is a partial order relation"
        else:
            return "It is not any type of relation"

matrix = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 1], [0, 0, 1, 1]]
relation = Rel(matrix)
classify = relation.find()
print(classify)
