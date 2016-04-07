/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     ArrayList<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    HashSet<UndirectedGraphNode> visited;
    HashMap<UndirectedGraphNode, UndirectedGraphNode> map;
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node == null) return null;
        visited = new HashSet<UndirectedGraphNode>();
        map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
        return dfs(node);
    }
    public UndirectedGraphNode dfs(UndirectedGraphNode node) {
        if(visited.contains(node)) return map.get(node);
        visited.add(node);
        UndirectedGraphNode nw = new UndirectedGraphNode(node.label);
        map.put(node, nw);
        Iterator<UndirectedGraphNode> it = node.neighbors.iterator();
        while(it.hasNext())
            nw.neighbors.add(dfs(it.next()));
        return nw;
    }
}