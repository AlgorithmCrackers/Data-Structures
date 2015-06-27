package graph;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

class Tuple { 
	public final Object x; 
	public final Object y; 
	public Tuple(Object x, Object y) { 
		this.x = x; 
		this.y = y;
	}
	public String toString() {
		StringBuilder s = new StringBuilder();
		s.append("(" + x + ", " + y + ")");
		return s.toString();
	}
}

public class DFS {
	private Map<Object, Object> parent;
	private Map<Object, Integer> start_time;
	private Map<Object, Integer> end_time;
	private Map<Tuple, String> edges; // edge classification for DFS
	private int time = 0;
	private List<Object> order;
	public DFS() {
		parent = new LinkedHashMap<Object, Object>();
		start_time = new HashMap<Object, Integer>();
		end_time = new HashMap<Object, Integer>();
		edges = new HashMap<Tuple, String>();
		order = new ArrayList<Object>();		
	}
	public String toString() {
		StringBuilder s = new StringBuilder();
		String NEWLINE = System.getProperty("line.separator");
		s.append("Parent: " + parent + NEWLINE);
		s.append("Order: " + order + NEWLINE);
		s.append("Edges: " + edges + NEWLINE);
		return s.toString();
	}
	public static DFS dfs(Graph g) {
		DFS results = new DFS();
		for (Object v: g.itervertices()) {
			if(! results.parent.containsKey(v)) {
				dfs_visit(g, v, results, null);
			}
		}
		return results;
	}
	private static void dfs_visit(Graph g, Object v, DFS results, Object parent) {
		results.parent.put(v, parent);
		results.time++;
		results.start_time.put(v, results.time);
		if (parent != null) {
			Tuple t = new Tuple(parent, v);
			results.edges.put(t, "tree");
		}
		for (Object a: g.adj(v)) {
			Tuple t = new Tuple(v, a);
			if (! results.parent.containsKey(a)) { // not visited already
				dfs_visit(g, a, results, v);
			} else if(! results.end_time.containsKey(a)) {
				results.edges.put(t, "back");
			}
			else if(results.start_time.get(v) < results.start_time.get(a)) {
				results.edges.put(t, "forward");
			}
			else {
				results.edges.put(t, "cross");
			}
		}
		results.time++;
		results.end_time.put(v, results.time);
		results.order.add(v);
	}
	public static List<Object> topological_sort(Graph g) {
		DFS d = DFS.dfs(g);
		Collections.reverse(d.order);
		return d.order;
	}
	public static void main(String[] args) {
		System.out.println(DFS.dfs(Graph.getDfsExampleGraph()));
	}

}
