##### BFS

#### Complexity
Time Complexity: O(V + E)
V for initialization
E for traverse all edges

#### Algo  
    1. take queue
    2. visited = [false] * V // V for initialization
    3. q.push(start vertex), visited[start vertex] = true
    4. while !q.empty():
        a. u = q.pop()
        b. for v in AdjacencyList[u]: // E for traverse
            if !visited[v]:
                visited[v] = true
                q.push(v)
     
##### DFS

#### Complexity
Time Complexity: O(V + E)
V for initialization
E for traverse all edges

#### Algo
    1. visited = [False] * V // V for initialization
    2. dfs(visited, adjList, start vertex)
    
    dfs(visited, adjList, u):
        visited[u] = True
        for v in adjList[u]:
            if not visited[v]:
                dfs(visited, adjList, v)
     
