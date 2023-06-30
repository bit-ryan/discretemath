class Graph:
    def __init__(self, num_vertices):
        self.num_vertices = num_vertices
        self.adj_list = [[] for _ in range(num_vertices)]
    
    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
    
    def is_complete_graph(self):
        for i in range(self.num_vertices):
            if len(self.adj_list[i]) != self.num_vertices - 1:
                return False
        return True

g = Graph(4)
g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(0, 3)
g.add_edge(1, 2)
g.add_edge(1, 3)
g.add_edge(2, 3)

if g.is_complete_graph():
    print("The graph is a complete graph.")
else:
    print("The graph is not a complete graph.")
