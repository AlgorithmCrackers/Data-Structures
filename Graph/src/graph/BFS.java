package graph;

import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;

public class BFS {
	private Map<Object, Integer> level;
	private Map<Object, Object> parent;
	
	public BFS() {
		level = new LinkedHashMap<Object, Integer>();
		parent = new LinkedHashMap<Object, Object>();
	}
	public String toString() {
		StringBuilder s = new StringBuilder();
		String NEWLINE = System.getProperty("line.separator");
		s.append("Parent: " + parent + NEWLINE);
		s.append("level: " + level + NEWLINE);
		return s.toString();
	}
	public static BFS bfsGraph(Graph g, Object s) {
		BFS b = new BFS();
		b.parent.put(s, null);
		b.level.put(s, 0);
		Queue<Object> queue = new LinkedList<Object>();
		queue.add(s);
		while (!queue.isEmpty()) {
			Object u = queue.poll();
			for(Object a: g.adj(u)) { // for all neighbors of vertex u
				if(!b.level.containsKey(a)) { // if not already visited
					b.parent.put(a, u);
					b.level.put(a, b.level.get(u)+1);
					queue.add(a);
				}
			}
		}
		return b;
	}
	/**
     * Unit tests BFS.
     */
    public static void main(String[] args) {
    	System.out.println(BFS.bfsGraph(Graph.getBfsExampleGraph(), "s"));
    }
}
