import random

def generate_edges(n, num_edges):
    edges = []
    for i in range(n-1):
        edges.append((i, i + 1, random.randint(1, 100)))
    remaining_edges = num_edges - (n - 1)
    for _ in range(remaining_edges):
        a, b = random.sample(range(n), 2)
        weight = random.randint(1, 100)
        edges.append((a, b, weight))
    return edges

def generate_queries(num_queries, n):
    queries = []
    for _ in range(num_queries):
        a, b = random.sample(range(n), 2)
        queries.append((a, b))
    return queries

def generate_dataset(n, num_edges, num_queries):
    edges = generate_edges(n, num_edges)
    queries = generate_queries(num_queries, n)

    with open('dataset.txt', 'w') as f:
        f.write(f'{n} {num_edges} {num_queries}\n')
        for edge in edges:
            f.write(f'{edge[0]} {edge[1]} {edge[2]}\n')
        for query in queries:
            f.write(f'{query[0]} {query[1]}\n')

if __name__ == '__main__':
    n = 1000
    num_edges = 1500  # Adjust the number of edges as needed
    num_queries = 20
    generate_dataset(n, num_edges, num_queries)

