#include "graph.h"

#include <QQueue>
#include <QHash>

Graph::Graph()
{

}

Graph::Graph(QList<Node *> nodes)
{
	foreach(Node* n, nodes){
		addNode(n);
	}
}

bool Graph::addNode(Node *node)
{
	if(m_nodes.contains(node)) return false;
	m_nodes.append(node);
	m_edges.insert(node, QList<Node*>());
	return true;
}

bool Graph::addEdge(Node *from, Node *to)
{
	if(!m_edges.keys().contains(from)) return false;
	if(m_edges[from].contains(to)) return false;
	m_edges[from].append(to);
	return true;
}

bool Graph::isCyclicDependencyExists()
{
	return topologicalSortKahn().length() == 0 ? true : false;
}

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

QList<Node *> Graph::nodes() const
{
	return m_nodes;
}
