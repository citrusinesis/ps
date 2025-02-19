package pkg

type Graph[T comparable] struct {
	vertices map[T][]T
}

func NewGraph[T comparable]() *Graph[T] {
	return &Graph[T]{
		vertices: make(map[T][]T),
	}
}

func (g *Graph[T]) AddVertex(v T) {
	if _, exists := g.vertices[v]; !exists {
		g.vertices[v] = []T{}
	}
}

func (g *Graph[T]) AddEdge(v, w T) {
	g.AddVertex(v)
	g.AddVertex(w)
	g.vertices[v] = append(g.vertices[v], w)
}

func (g *Graph[T]) RemoveEdge(v, w T) {
	if adj, exists := g.vertices[v]; exists {
		newAdj := make([]T, 0, len(adj))
		for _, x := range adj {
			if x != w {
				newAdj = append(newAdj, x)
			}
		}
		g.vertices[v] = newAdj
	}
}

func (g *Graph[T]) RemoveVertex(v T) {
	delete(g.vertices, v)
	for u, adj := range g.vertices {
		newAdj := make([]T, 0, len(adj))
		for _, x := range adj {
			if x != v {
				newAdj = append(newAdj, x)
			}
		}
		g.vertices[u] = newAdj
	}
}

func (g *Graph[T]) DFS(start T, visited map[T]bool, result *[]T) {
	if visited[start] {
		return
	}
	visited[start] = true
	*result = append(*result, start)
	for _, neighbor := range g.vertices[start] {
		g.DFS(neighbor, visited, result)
	}
}

func (g *Graph[T]) BFS(start T) []T {
	var result []T
	visited := make(map[T]bool)
	queue := []T{start}
	visited[start] = true

	for len(queue) > 0 {
		var v T

		v, queue = queue[0], queue[1:]
		result = append(result, v)

		for _, neighbor := range g.vertices[v] {
			if !visited[neighbor] {
				visited[neighbor] = true
				queue = append(queue, neighbor)
			}
		}
	}

	return result
}
