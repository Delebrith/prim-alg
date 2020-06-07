import random, queue

random.seed(42)

class Edge:
    def __init__(self, weight, vertex1, vertex2):
        """
        Construct a new Edge object

        Parameters
        ----------
        weight : int
            Edge weights.
        vertex1 : int
            Index of the first vertex.
        vertex2 : int
            Index of the second vertex.

        Returns
        -------
        None.

        """
        self.w = weight
        self.v1 = vertex1
        self.v2 = vertex2
        self.vertex = self.v1
        self.neighbor = self.v2

    def __eq__(self, other):
        """
        Chech if edges are equal based on their weight and vertex indicies

        Parameters
        ----------
        other : Edge
            Edge to compare.

        Returns
        -------
        bool
            True if both edges has same weight and indices

        """
        return self.w == other.w and \
                ((self.v1 == other.v1 and self.v2 == other.v2) or \
                (self.v1 == other.v2 and self.v2 == other.v1))

    def __gt__(self, other):
        """
        Compare edges based on their weights

        Parameters
        ----------
        other : Edge
            Edge to compare.

        Returns
        -------
        bool
            Weight of the given edge is bigger than 
            the weight of object.

        """
        return self.w > other.w

    def __repr__(self):
        return f'Edge({self.w}, {self.v1}, {self.v2})'

    def __hash__(self):
        """
        Compute hash function.

        Returns
        -------
        int
            Hash functin result.

        """
        return self.w ^ self.v1 ^ self.v2
    
    def has_one_vertex_in(self, vertices):
        """
        Check if given hash set of verticies contains one of the 
        verticies of the edge

        Parameters
        ----------
        vertices : set
            Set of verticies.

        Returns
        -------
        bool
            Set has one of the edge verticies.

        """
        return (self.v1 in vertices and self.v2 not in vertices) or (self.v1 not in vertices and self.v2 in vertices) 

class Graph:
    def __init__(self, adjacency_matrix):
        """
        Construct a new Graph object

        Parameters
        ----------
        adjacency_matrix : 2D array
           Adjacency matrix.

        Returns
        -------
        None.

        """
        self.adjacency_matrix = adjacency_matrix

    def __repr__(self):
        reprStr = 'Graph(\n'
        for row in self.adjacency_matrix:
            reprStr += f'\t{row}\n'
        reprStr += '\t)'
        return reprStr

    def adjacent_edges(self, vertex):
        """
        Get adjacent edges Of vertex

        Parameters
        ----------
        vertex : int
            Vertex index.

        Returns
        -------
        list
            Resulting set of adjacent edges.

        """
        candidates = self.adjacency_matrix[vertex]
        return [Edge(weight, vertex, neighbor) \
                for neighbor, weight in enumerate(candidates) if weight > 0]

    def weight(self, v1, v2):
        """
        Get edge weight

        Parameters
        ----------
        v1 : int
            First vertex index.
        v2 : int
            Second vertex index.

        Returns
        -------
        int
            Edge weight.

        """
        return self.adjacency_matrix[v1][v2]

    def neighbors(self, vertex):
        """
        Neighboring verticies

        Parameters
        ----------
        vertex : int
            Index of the vertex.

        Returns
        -------
        list
            List of neighboring vertex indices.

        """
        candidates = self.adjacency_matrix[vertex]
        return [neighbor \
                for neighbor, weight in enumerate(candidates) if weight > 0]

    def get_adjacency_matrix(self):
        """
        """
        return self.adjacency_matrix


def run_algorithm(adjacency_matrix):
    """
    Prim's algorithm implementation

    Parameters
    ----------
    adjacency_matrix : 2D array
        Adjacency matrix with edge weights

    Returns
    -------
    mst : set
        Set of edges that belong to MST.

    """

    # Initialize required objects
    G = Graph(adjacency_matrix)
    mst = set()
    processedVertices = set()
    edgeQueue = queue.PriorityQueue()

    # Insert edges of the first vertex into the MST
    initialVertex = 0
    processedVertices.add(initialVertex)
    adjacent_edges = G.adjacent_edges(initialVertex)
    for edge in adjacent_edges:
        edgeQueue.put(edge)

    # While there is more verticies to process
    while len(processedVertices) != len(G.get_adjacency_matrix()):
        
        # Get edge with the smallest weigth
        minEdge = edgeQueue.get()
        
        if minEdge.has_one_vertex_in(processedVertices):
            mst.add((minEdge.v1, minEdge.v2))
            vertex = minEdge.neighbor if minEdge.neighbor not in processedVertices else minEdge.vertex 
            processedVertices.add(vertex)
            adjacent_edges = G.adjacent_edges(vertex)
            
            # Put its adjacent edges into the priority queue
            for edge in adjacent_edges:
                edgeQueue.put(edge)

    return mst


