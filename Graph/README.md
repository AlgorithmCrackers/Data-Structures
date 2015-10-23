## BFS

![BFS graph](http://i.imgur.com/Pj7EEbA.png)

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

## DFS

![DFS graph](http://i.imgur.com/uMdnI9Q.png)
