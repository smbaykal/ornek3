#include "graph.h"

#include <QQueue>
#include <QHash>

/*!
 * \brief Graph::Graph Initializes empty graph.
*/
Graph::Graph()
{

}

/*!
 * \brief Graph::Graph Initializes graph with existing nodes.
 * \param nodes Nodes to adding graph.
*/
Graph::Graph(QList<Node *> nodes)
{
	foreach(Node* n, nodes){
		addNode(n);
	}
}

/*!
 * \brief addNode Adds non existing node to graph.
 * \param node Node to add.
 * \return If adding successful returns true, otherwise false
*/
bool Graph::addNode(Node *node)
{
	if(m_nodes.contains(node)) return false;
	m_nodes.append(node);
	m_edges.insert(node, QList<Node*>());
	return true;
}

/*!
 * \brief addEdge Adds non existing edge to graph.
 * \param from Edge starting node.
 * \param to Edge ending node.
 * \return If from and to nodes exists and there is no edge between them returns true, otherwise false
*/
bool Graph::addEdge(Node *from, Node *to)
{
	if(!m_edges.keys().contains(from)) return false;
	if(m_edges[from].contains(to)) return false;
	m_edges[from].append(to);
	return true;
}

/*!
 * \brief isCyclicDependencyExists Looks for cyclic dependency in graph.
 * \return If there is cyclic dependency returns true, otherwise false
*/
bool Graph::isCyclicDependencyExists()
{
	return topologicalSortKahn().length() == 0 ? true : false;
}

/*!
 * \brief Graph::calculateDepths Calculates all nodes depths.
 * \return Returns depth level and nodes in that level. If there is cyclic dependency returns empty.
 */
QHash<int, QList<Node *> > Graph::calculateDepths()
{
	QHash<int, QList<Node*>> depths;
	if(isCyclicDependencyExists()) return depths;
	QHash<Node*, bool> visited;
	foreach(Node* n, m_nodes){
		visited.insert(n, false);
	}

	calculateDepthsUtil(m_nodes.first(), &visited, 0, &depths);

	return depths;
}

/*!
 *\brief topologicalSortKahn Topological sorting with Kahn's algorithm.
 *\return Returns sorted list.
 *\quotation
 * 		find indegree for each vertex
 * 		Q = empty FIFO Queue
 * 		add all vertices with no incoming edges to Q
 * 		while Q isn't empty
 * 			remove any vertex u from Q
 * 			put u next in the topological ordering
 * 			for each outgoing edge u->v
 * 				decrement v's indegree
 * 				if v's indegree is 0
 * 					add v to Q
 * 		if list length != node count return empty list
 * 		return list
 *  \endquotation
*/
QList<Node *> Graph::topologicalSortKahn()
{
	QHash<Node*, int> indegree;
	foreach(Node* n, m_nodes){
		indegree.insert(n, 0);
	}
	foreach(Node *n, m_nodes){
		foreach(Node* edge, m_edges[n]){
			indegree[edge]++;
		}
	}

	QQueue<Node*> queue;
	foreach(Node* n, m_nodes){
		if(indegree[n] == 0){
			queue.enqueue(n);
		}
	}

	QList<Node*> topologicalOrder;
	while(!queue.isEmpty()){
		Node* dequeue = queue.dequeue();
		topologicalOrder.insert(0, dequeue);
		foreach(Node* edge, m_edges[dequeue]){
			indegree[edge]--;
			if(indegree[edge] == 0){
				queue.enqueue(edge);
			}
		}
	}

	if(topologicalOrder.length() != m_nodes.length()){
		return QList<Node*>();
	}
	return topologicalOrder;
}

/*!
 * \brief topologicalSortDFS Topological sorting with DepthFirstSearch algorithm.
 *  \return Returns sorted list.
 *  \quotation
 * 		let v be a sink vertex of G (sink: has no incoming edges)
 * 		delete all edges to v
 * 		add v to list
 * 		recurse on G - {v}
 * 		return list
 *  \endquotation
*/
QList<Node *> Graph::topologicalSortDFS()
{
	QQueue<Node*> top_order;
	QList<Node*> vertex = m_nodes;
	QHash<Node*, QList<Node*>> edges = m_edges;
	int i = 0;
	while(!vertex.isEmpty()){
		if(edges[vertex[i]].isEmpty()){
			for(int j = 0; j < vertex.length(); j++){
				if(j != i && edges[vertex[j]].contains(vertex[i])){
					edges[vertex[j]].removeOne(vertex[i]);
				}
			}
			top_order.push_back(vertex[i]);
			vertex.removeAt(i);
			i = 0;
		} else{
			i++;
			if(i >= vertex.length()){
				return QList<Node*>();
			}
		}
	}
	return top_order;
}

/*!
 * \brief nodes
 * \return Returns all existing nodes
*/
QList<Node *> Graph::nodes() const
{
	return m_nodes;
}

/*!
 * \brief Graph::edges
 * \return Returns all existing edges
 */
QHash<Node *, QList<Node *> > Graph::edges() const
{
	return m_edges;
}

/*!
 * \brief Graph::calculateDepthsUtil Depth first search based recursive depth calculator
 * \param node Node to calculate depth
 * \param visited Visited nodes
 * \param currentDepth Node's current depth
 * \param depths All nodes depths.
 */
void Graph::calculateDepthsUtil(Node *node, QHash<Node *, bool> *visited, int currentDepth, QHash<int, QList<Node *> > *depths)
{
	(*visited)[node] = true;
	foreach(Node* n, m_edges[node]){
		calculateDepthsUtil(n, visited, currentDepth + 1, depths);
	}
	if(!depths->keys().contains(currentDepth)){
		depths->insert(currentDepth, QList<Node*>() << node);
	} else{
		(*depths)[currentDepth].append(node);
	}
}
