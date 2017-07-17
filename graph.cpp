#include "graph.h"

Graph::Graph()
{

}

QString Graph::dependencyResolve(Node* node)
{
	m_TraversedNodes.clear();
	m_LastError.clear();

	m_Resolved.clear();
	m_Unresolved.clear();

	dependencyResolveUtil(node);

	if(!m_LastError.isEmpty())
		return m_LastError.append("\nTraversed nodes: ").
				append(m_TraversedNodes);
	return QString("Traversed nodes: ").
			append(m_TraversedNodes);
}

void Graph::dependencyResolveUtil(Node *node)
{
	m_TraversedNodes.append(node->Name());
	m_Unresolved.append(node);
	foreach(Node* n, node->Edges()){
		if(!m_Resolved.contains(n)){
			if(m_Unresolved.contains(n)){
				m_LastError = "Circular dependency detected. : ";
				m_LastError.append(node->Name()).append(" -> ").append(n->Name());
				m_LastError.append("\nLast seen node : ").append(m_Unresolved.last()->Name());
				break;
			} else {
				m_TraversedNodes.append("->").append(n->Name()).append("\n");
				dependencyResolveUtil(n);
			}
		}
	}
	m_Resolved.append(node);
	m_Unresolved.removeOne(node);
}

QList<Node *> Graph::Resolved() const
{
	return m_Resolved;
}
