#ifndef GRAPH_H
#define GRAPH_H

#include <QList>
#include <QHash>

#include "node.h"

class Graph
{
public:
	///
	/// \brief Graph::Graph Initializes empty graph.
	///
	explicit Graph();


	///
	/// \brief Graph::Graph Initializes graph with existing nodes.
	/// \param nodes Nodes to adding graph.
	///
	explicit Graph(QList<Node*> nodes);

	///
	/// \brief addNode Adds non existing node to graph.
	/// \param node Node to add.
	/// \return If adding successful returns true, otherwise false
	///
	bool addNode(Node* node);

	///
	/// \brief addEdge Adds non existing edge to graph.
	/// \param from Edge starting node.
	/// \param to Edge ending node.
	/// \return If from and to nodes exists and there is no edge between them returns true, otherwise false
	///
	bool addEdge(Node* from, Node* to);

	///
	/// \brief isCyclicDependencyExists Looks for cyclic dependency in graph.
	/// \return If there is cyclic dependency returns true, otherwise false
	///
	bool isCyclicDependencyExists();

	///
	/// \brief topologicalSortKahn Topological sorting with Kahn's algorithm.
	/// \return Returns sorted list.
	/// \quotation
	///		find indegree for each vertex
	///		Q = empty FIFO Queue
	///		add all vertices with no incoming edges to Q
	///		while Q isn't empty
	///			remove any vertex u from Q
	///			put u next in the topological ordering
	///			for each outgoing edge u->v
	///				decrement v's indegree
	///				if v's indegree is 0
	///					add v to Q
	///		if list length != node count return empty list
	///		return list
	/// \endquotation
	QList<Node *> topologicalSortKahn();

	///
	/// \brief topologicalSortDFS Topological sorting with DepthFirstSearch algorithm.
	/// \return Returns sorted list.
	/// \quotation
	///		let v be a sink vertex of G (sink: has no incoming edges)
	///		delete all edges to v
	///		add v to list
	///		recurse on G - {v}
	///		return list
	/// \endquotation
	///
	QList<Node*> topologicalSortDFS();

	///
	/// \brief nodes
	/// \return Returns all existing nodes
	///
	QList<Node *> nodes() const;

private:
	QList<Node*> m_nodes;
	QHash<Node*, QList<Node*>> m_edges;
};

#endif // GRAPH_H
