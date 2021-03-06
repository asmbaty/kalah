// Tree.h
#ifndef TREE_H
#define TREE_H
const int N_Tree = 6;// Ծառի որդիների քանակը
struct Node // Ծառի հանգույցի մշակման դաս
{
	Node();
	Node(int info);
	Node(int info,Node childs[]);
	int Info;
	Node *Childs[N_Tree];
};
class Tree 
{
private:
	Node* Root; // Ծառի արմատ
	void Clear_Helper(Node* root); // Մաքրել ծառը ֆունկցիայի օգնական ֆունկցիա
public:
	Tree(); // Լռությամբ կառուցիչ
	Tree(Node*); // Կառուցիչ , որը ստանում է արմատի հասցեն
	Tree(int info); // Կառուցիչ , որը ստանում է արմատի հանգույցի պարունակությունը
	virtual ~Tree(); // Փլուզիչ
	void CreateRoot(int info); // Կառուցում է արմատը 'info' պարունակությամբ
	bool Insert(Node*,int position,int info); // Ավելացնել  նշված հանգույցից 'position' - րդ որդի  'info' հանգույցի պարունակությամբ

	void Clear(); // Մաքրել ծառը
	void Max_Childs(Node*); // Նշված հանգույցի պարունակությունը դառնում է իր որդիների մաքսիմումի արժեքը : Եթե որդի չունի , ապա INT_MIN  
	void Min_Childs(Node*); // Նշված հանգույցի պարունակությունը դառնում է իր որդիների մաքսիմումի արժեքը : Եթե որդի չունի , ապա INT_MAX

	bool Empty()const; // Ծառի դատարկ լինելու ստուգում
	Node* GetRoot()const; // Վերադարձնում է ծառի արմատը

	// Չկա  պատճենման կառուցիչ և operator = //  
};
#endif