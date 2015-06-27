package graph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Graph {
	private Map<Object, Set<Object>> adj;
	private int V; // vertices count
	private int E; // edges count
	public Graph() {
		adj = new HashMap<Object, Set<Object>>();
	}
	public void add_DirectedEdge(Object u, Object v){
		if (!adj.containsKey(u)) {
			adj.put(u, new HashSet<Object>());
			V++;
		}
		adj.get(u).add(v); E++;
	}
	public void add_UndirectedEdge(Object u, Object v){
		if (!adj.containsKey(u)) {
			adj.put(u, new HashSet<Object>());
			V++;
		}
		if (!adj.containsKey(v)) {
			adj.put(v, new HashSet<Object>());
			V++;
		}
		adj.get(u).add(v);
		adj.get(v).add(u);
		E++;
	}
	public Iterable<Object> adj(Object v) {
        return adj.get(v);
    }
	public Iterable<Object> itervertices() {
		return adj.keySet();
	}
	public String toString() {
		StringBuilder s = new StringBuilder();
		String NEWLINE = System.getProperty("line.separator");
		s.append(V + " vertices, " + E + " edges " + NEWLINE);
		for (Object v: itervertices()) {
			s.append(v + ": ");
			for (Object w : adj.get(v)) {
				s.append(w + " ");
			}
			s.append(NEWLINE);
		}
		return s.toString();
	}
	/**
	 * returns <a href="http://courses.csail.mit.edu/6.006/fall11/lectures/lecture13.pdf">MIT BFS lecture</a> example graph
	 */
	public static Graph getBfsExampleGraph() {
		Graph g = new Graph();
		g.add_UndirectedEdge("s", "a");
		g.add_UndirectedEdge("a", "z");
		g.add_UndirectedEdge("s", "x");
		g.add_UndirectedEdge("d", "c");
		g.add_UndirectedEdge("x", "d");
		g.add_UndirectedEdge("x", "c");
		g.add_UndirectedEdge("d", "f");
		g.add_UndirectedEdge("c", "f");
		g.add_UndirectedEdge("f", "v");
		g.add_UndirectedEdge("c", "v");
		return g;
	}
	/**
	 * returns <a href="http://courses.csail.mit.edu/6.006/fall11/lectures/lecture14.pdf">MIT DFS lecture</a> example graph
	 */
	public static Graph getDfsExampleGraph() {
		Graph g = new Graph();
		g.add_DirectedEdge("a", "b");
		g.add_DirectedEdge("a", "d");
		g.add_DirectedEdge("b", "e");
		g.add_DirectedEdge("d", "b");
		g.add_DirectedEdge("e", "d");
		g.add_DirectedEdge("c", "e");
		g.add_DirectedEdge("c", "f");
		g.add_DirectedEdge("f", "f");
		return g;
	}
    /**
     * Unit tests the Graph data type.
     */
    public static void main(String[] args) {
        Graph G = Graph.getBfsExampleGraph();
        System.out.println(G);
        Graph D = Graph.getDfsExampleGraph();
        System.out.println(D);
    }

}
