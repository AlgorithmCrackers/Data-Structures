## BFS

![BFS graph](http://i.imgur.com/Pj7EEbA.png)

### Analysis

- `Adj[v]` is looped through only once.
- Time = `for v: Vertices { | Adj[v] | }`  = `O(E)`
  - `|E|` for directed edges
  - `2|E|` for undirected edges
- `O(V + E)` to also list vertices unreaachable from v (those still not assigned a level)

### Result
```
Parent: {s=null, a=s, x=s, z=a, c=x, d=x, f=c, v=c}
level: {s=0, a=1, x=1, z=2, c=2, d=2, f=3, v=3}
```

- For vertex `v`, fewest edges to get from `s`(start) to `v` is 
  - `level[v]` if v is assigned a level
  - ∞ else (no path)

- Parent pointers form the **shortest path tree**.
  - To find the shortest path for `v`, `parent[v]`, `parent[ parent[v] ]`....till `s` (or null)

### Applications:

* Connected Components
* vertex-coloring problem

## DFS

![DFS graph](http://i.imgur.com/uMdnI9Q.png)

### Analysis
- `DFS_visit` gets called with a vertex `s` only once (because then parent[s] is set)
- time in DFS_visit = `for s: Vertices { | Adj[v] | }`  = `O(E)`
- DFS outer loop adds `O(V)`
- `O(V + E)` time

### Job scheduling
- given directed acyclic graph(DAG), where vertices represent tasks, and edges represent dependencies, order task without violating dependencies.
- **Topological Sort** : reverse of DFS finishing times (time at which DFS_visit(v) finishes)

```
DFS_visit(v)
    ....
    order.append(v)
    
order.reverse()
```
### Result

```
Parent: {a=null, b=a, e=b, d=e, c=null, f=c}
Order: [d, e, b, a, f, c]
Edges: {(e, d)=tree, (c, e)=cross, (c, f)=tree, (a, d)=forward, (a, b)=tree, (b, e)=tree, (d, b)=back, (f, f)=back}

```

#### Applications

* Finding cycles
* Topological sorting
* Strongly Connected Components
