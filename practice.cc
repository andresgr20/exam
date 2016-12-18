#include "node.h"
#include <utility>
using namespace std;

Node::Node():value(value),next{nullptr} {}

Node::Node(const Node &other):value{other.value},{
	value=other.value;
	next=other.next? new Node{* other.next}:nullptr;
}

Node&::Node operator=(const Node &other){
	if(this==&other) return *this;
	Node *tmp=next;
	next=other.next? new Node{* other.next}: nullptr;
	value=other.value;
	delete tmp;
	return *this;
	/* Other way of doing it using the copy and swap idiom
	Node tmp=other;
	swap(tmp);
	return this;
	*/
}

Node::Node(Node &&other):value{other.value},next{other.next} {
	other.next=nullptr;
}


Node& ::Node operator=(Node &&other){ //compiler knows that otehr is tmp r-value object due to the &&
	swap(value,other.value);
	swap(next,other.next);
	return *this;
}


ostream& operator<<(ostream &out,Node other){
	Node *cur=other;
	while(cur){
		out << cur->value << endl;
		cur=cur->next;
	}
	return out;
}

istream& operator>>(istream &in,Node other){
	int value;
	in >> value;
	other.value=value;
	return in;
}