// Tree.cpp
#include <iostream>
#include "Tree.h"


Node::Node()
{
	this->Info = NULL;
	for(int i = 0 ; i < N_Tree ; ++i )
		this->Childs[i] = NULL;
}

Node::Node(int info)
{
	this->Info = info;
	for(int i = 0 ; i < N_Tree ; ++i )
		this->Childs[i] = NULL;
}

Node::Node(int info,Node childs[])
{
	this->Info = info;
	for(int i = 0 ; i < N_Tree ; ++i )
		Childs[i] = & childs[i];
}

Tree::Tree():Root(NULL) {}

Tree::Tree(int info)
{
	this->Root = new Node(info);
}

Tree::Tree(Node * adressroot):Root(adressroot) {}

Tree::~Tree()
{
	this->Clear();
}

void Tree::CreateRoot(int info)
{
	Root = new Node(info);
}

bool Tree::Insert(Node* p,int position,int info)
{
	if(p == NULL || position >= N_Tree )
		return false;
	p->Childs[position] = new Node(info);
	return true;
}

void Tree::Clear_Helper(Node* root)
{
	if(root == NULL ) return;
	for(int i = 0 ; i < N_Tree ; ++i )
	{
		Clear_Helper(root->Childs[i]);
	}
	delete root;
}

void Tree::Clear()
{
	Clear_Helper(Root);
	this->Root = NULL;
}

void Tree::Max_Childs(Node* p)
{
	if( p == NULL ) throw "Tree::Max_Chids : adress is NULL";
	int k = INT_MIN;  
	for(int i = 0 ; i < N_Tree ; ++i )
		if(p->Childs[i] != NULL &&  p->Childs[i]->Info > k )
			k = p->Childs[i]->Info;
	p->Info = k;
}

void Tree::Min_Childs(Node* p)
{
	if( p == NULL ) throw "Tree::Min_Chids : adress is NULL";
	int k = INT_MAX; 
	for(int i = 1 ; i < N_Tree ; ++i )
		if(p->Childs[i] != NULL && p->Childs[i]->Info < k )
			k = p->Childs[i]->Info;
	p->Info = k;
}

bool Tree::Empty()const
{
	return Root == NULL ;
}

Node* Tree::GetRoot()const
{
	return Root;
}