import sys
from os.path import abspath, join, dirname
sys.path.insert(0, join(abspath(dirname("__file__")), "..", "py_prim"))

import queue
import pytest
from py_prim import Graph, Edge, run_algorithm

adjacency_matrix = [
        [0, 2, 8, 4],
        [2, 0, 16, 32],
        [8, 16, 0, 64],
        [4, 32, 64, 0]
    ]

G = Graph(adjacency_matrix)

def test_edge_comparison():
    assert Edge(2, 3, 1) == Edge(2, 3, 1)
    assert Edge(2, 3, 1) == Edge(2, 1, 3)
    assert Edge(2, 3, 1) != Edge(2, 3, 2)
    assert Edge(2, 3, 1) < Edge(3, 3, 1)

def test_edge_hash_comparison():
    assert hash(Edge(2, 3, 1)) == hash(Edge(2, 3, 1))
    assert hash(Edge(2, 3, 2)) != hash(Edge(2, 3, 1))
    assert hash(Edge(2, 2, 3)) == hash(Edge(2, 3, 2))

def test_graph_get_neighbors():
    res = G.neighbors(2)
    assert res == [0, 1, 3]

def test_graph_get_adjacent_edges():
    res = G.adjacent_edges(2)
    assert set(res) == set([Edge(8, 2, 0), 
                            Edge(16, 2, 1), 
                            Edge(64, 2, 3)])

def test_edge_priority_queue():
    pq = queue.PriorityQueue()
    pq.put(Edge(9, 1, 1))
    pq.put(Edge(0, 2, 3))
    pq.put(Edge(2, 1, 1))
    pq.get() == Edge(0, 2, 3)
    pq.get() == Edge(2, 1, 1)
    pq.get() == Edge(9, 1, 1)

def test_run_algorithm():
    res = run_algorithm(adjacency_matrix)
    assert res == set([(0, 2), (0, 1), (0, 3)])

if __name__ == "__main__":
    print("Running as a main script...")
