import random, queue

random.seed(42)

class Edge:
    def __init__(self, weight, vertex1, vertex2):
        self.w = weight
        self.v1 = vertex1
        self.v2 = vertex2
        self.vertex = self.v1
        self.neighbor = self.v2

    def __eq__(self, other):
        return self.w == other.w and \
                ((self.v1 == other.v1 and self.v2 == other.v2) or \
                (self.v1 == other.v2 and self.v2 == other.v1))

    def __gt__(self, other):
        return self.w > other.w

    def __repr__(self):
        return f'Edge({self.w}, {self.v1}, {self.v2})'

    def __hash__(self):
        return self.w ^ self.v1 ^ self.v2

class Graph:
    def __init__(self, adjacency_matrix):
        self.adjacency_matrix = adjacency_matrix

    def __repr__(self):
        reprStr = 'Graph(\n'
        for row in self.adjacency_matrix:
            reprStr += f'\t{row}\n'
        reprStr += '\t)'
        return reprStr

    def adjacent_edges(self, vertex):
        candidates = self.adjacency_matrix[vertex]
        return [Edge(weight, vertex, neighbor) \
                for neighbor, weight in enumerate(candidates) if weight > 0]

    def weight(self, v1, v2):
        return self.adjacency_matrix[v1][v2]

    def neighbors(self, vertex):
        candidates = self.adjacency_matrix[vertex]
        return [neighbor \
                for neighbor, weight in enumerate(candidates) if weight > 0]

    def get_adjacency_matrix(self):
        return self.adjacency_matrix


def run_algorithm(adjacency_matrix):
    G = Graph(adjacency_matrix)
    mst = set()
    processedVerticies = set()
    edgeQueue = queue.PriorityQueue()

    initialVertex = 0
    processedVerticies.add(initialVertex)
    adjacent_edges = G.adjacent_edges(initialVertex)
    for edge in adjacent_edges:
        edgeQueue.put(edge)

    while len(processedVerticies) != len(G.get_adjacency_matrix()):
        minEdge = edgeQueue.get()
        mst.add((minEdge.v1, minEdge.v2))
        vertex = minEdge.neighbor
        processedVerticies.add(vertex)
        adjacent_edges = G.adjacent_edges(vertex)
        for edge in adjacent_edges:
            if edge.neighbor not in processedVerticies:
                edgeQueue.put(edge)

    return mst


