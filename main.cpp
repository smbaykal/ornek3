#include <QCoreApplication>

#include <QDebug>

#include "graph.h"

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	Graph g;

	/*Node* nodeA = new Node("A");
	Node* nodeB = new Node("B");
	Node* nodeC = new Node("C");
	Node* nodeD = new Node("D");
	Node* nodeE = new Node("E");

	g.addNode(nodeA);
	g.addNode(nodeB);
	g.addNode(nodeC);
	g.addNode(nodeD);
	g.addNode(nodeE);

	g.addEdge(nodeA, nodeB);
	g.addEdge(nodeA, nodeD);
	g.addEdge(nodeB, nodeC);
	g.addEdge(nodeB, nodeE);
	g.addEdge(nodeC, nodeD);
	g.addEdge(nodeC, nodeE);*/

	/*Node* cl1 = new Node("Cl1");
	Node* cl2 = new Node("Cl2");
	Node* cl3 = new Node("Cl3");
	Node* cl4 = new Node("Cl4");

	g.addNode(cl1);
	g.addNode(cl2);
	g.addNode(cl3);
	g.addNode(cl4);

	g.addEdge(cl1, cl2);
	g.addEdge(cl1, cl3);
	g.addEdge(cl2, cl4);
	g.addEdge(cl3, cl2);
	g.addEdge(cl4, cl3);*/


	Node* nodeA = new Node("A");
	Node* nodeB = new Node("B");
	Node* nodeC = new Node("C");
	Node* nodeD = new Node("D");
	Node* nodeE = new Node("E");
	Node* nodeF = new Node("F");

	g.addNode(nodeA);
	g.addNode(nodeB);
	g.addNode(nodeC);
	g.addNode(nodeD);
	g.addNode(nodeE);
	g.addNode(nodeF);

	g.addEdge(nodeA, nodeB);
	g.addEdge(nodeA, nodeC);
	g.addEdge(nodeA, nodeD);
	g.addEdge(nodeB, nodeE);
	g.addEdge(nodeD, nodeF);


	QString result = "Topological sorting; Kahn: ";
	foreach(Node* n, g.topologicalSortKahn()){
		result.append(n->name()).append(" ");
	}
	qDebug().noquote() << result.simplified();

	result = "\nTopological sorting; DFS: ";
	foreach(Node* n, g.topologicalSortDFS()){
		result.append(n->name()).append(" ");
	}
	qDebug().noquote() << result.simplified();

	result = "\nAll nodes: ";
	foreach(Node* n, g.nodes()){
		result.append(n->name()).append(" ");
	}
	qDebug().noquote() << result.simplified();

	qDebug() << "Is cyclic dependency exists? :" << g.isCyclicDependencyExists();

	for(int i = 0; i < g.calculateDepths().keys().length(); i++){
		QString out = QString::number(i).append(" : ");
		foreach(Node* n, g.calculateDepths()[i]){
			out.append(n->name()).append(" ");
		}
		qDebug() << out.simplified();
	}
	return 0;
}

