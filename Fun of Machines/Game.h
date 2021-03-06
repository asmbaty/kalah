// Game.h
#ifndef GAME_H
#define GAME_H
#include "Tree.h"
const int N = 14 ; // Զանգվածի տարրերի քանակ
class Game // Համակարգչի քայլի մտածման դաս
{
protected:
	int Area[N]; // Քարերի քանակների զանգված 
	Tree tree; // ծառ
	int Depth; // ծառի խորություն ( համակարգչի մտածելու քայլերի քանակ )
public:
	Game(int[N],int depth = 2); // կառուցիչ , որը ստանւմ է քարերի քանակների զանգվածը և ծառի խորությունը
	int* GetAreaPtr(); // Վերադարձնում է Area-ի հասցեն
	void Dispose(); // Մաքրում է ծառը
	void Alpa_Beta_Balance(Node* root,int[14],int& depth); // Բալանսավորում է ծառը
	int Alpa_Beta(); // Վերադարձնում է լավագույն խաղը դիրքը

	bool StepPlayer(int position,int* adress ); // Խաղացողի 'position' -րդ դիրքից քայլ 'adress' քարերի քանակների զանգվածով
	bool StepComputer(int position,int* adress ); // Համակարգչի 'position' -րդ դիրքից քայլ 'adress' քարերի քանակների զանգվածով

	// Չկա  պատճենման կառուցիչ և operator = //  
};
#endif