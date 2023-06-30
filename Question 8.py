class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
    
    def add_edge(self, u, v):
        self.adj_list[u].append(v)
    
    def compute_degrees(self):
        in_degrees = [0] * self.num_vertices
        out_degrees = [0] * self.num_vertices
        
        for u in range(self.num_vertices):
            for v in self.adj_list[u]:
                in_degrees[v] += 1
                out_degrees[u] += 1
        
        return in_degrees, out_degrees

g = Graph(5)
g.add_edge(1, 1)
g.add_edge(3, 2)
g.add_edge(1, 3)
g.add_edge(2, 1)
g.add_edge(0, 3)
g.add_edge(3, 2)
g.add_edge(2, 2)

in_degrees, out_degrees = g.compute_degrees()

print("Vertex\tIn-Degree\tOut-Degree")
for v in range(g.num_vertices):
    print(f"{v}\t{in_degrees[v]}\t\t{out_degrees[v]}")
