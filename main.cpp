#include <QCoreApplication>

#include <QDebug>

#include "graph.h"

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	/*Node* cl1 = new Node("cl1");
	Node* cl2 = new Node("cl2");
	Node* cl3 = new Node("cl3");
	Node* cl4 = new Node("cl4");

	cl1->addEdge(cl2);
	cl1->addEdge(cl3);
	cl2->addEdge(cl4);
	cl3->addEdge(cl2);
	cl4->addEdge(cl3);*/

	Node* nodeA = new Node("A");
	Node* nodeB = new Node("B");
	Node* nodeC = new Node("C");
	Node* nodeD = new Node("D");
	Node* nodeE = new Node("E");

	nodeA->addEdge(nodeB);
	nodeA->addEdge(nodeD);
	nodeB->addEdge(nodeC);
	nodeB->addEdge(nodeE);
	nodeC->addEdge(nodeE);
	nodeC->addEdge(nodeD);

	Graph g;

	qDebug().noquote() << g.dependencyResolve(nodeA);
	//qDebug().noquote() << g.dependencyResolve(cl1);

	return 0;
}

