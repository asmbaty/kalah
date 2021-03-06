// Game.cpp
#include <algorithm>
#include <ctime>
#include "Game.h"
using namespace std;

Game::Game(int  ar[14],int depth):Depth(depth)
{
	for(int i = 0 ; i < N ; ++i)
	{
		Area[i] = ar[i];
	}
}

int* Game::GetAreaPtr()
{
	return Area;
}

void Game::Dispose()
{
	this->tree.Clear();
}

void Game::Alpa_Beta_Balance(Node* root,int arr[14],int& depth)
{
	// Մեզ պետք է ծառը կառուցել depth խորությամբ
	if(depth == Depth) // Եթե հասել ենք Depth խորության 
	{
		return; // ֆունկցիան ավարտում ենք
	}
	if(arr[13] > 36 || arr[6] > 36 || ( arr[13] == 36 && arr[6] == 36 ) ) // Եթե խաղը ավարտված է  
	{
		return; // ֆունկցիան ավարտում ենք
	}
	int a[14];
	for(int i = 0 ; i < N_Tree ; ++i ) // Բոլոր որդիների համար
	{
		copy(arr,arr+N,a);
		if(depth % 2 == 0 ) // Զույգ խորության դեպքում
		{
			if(a[i+7] == 0 ) // Եթե համակարգչի տվյալ դիրքի քարերի թիվը 0 է , ապա նա չի կարող խաղալ այդ քայլը
				continue;
			StepComputer(i+1,a); // Համակարգչը կատարում է քայլ
		}
		else // Կենտ խորության դեպքում
		{
			if(a[i] == 0) // Եթե Խաղացողի տվյալ դիրքի քարերի թիվը 0 է , ապա նա չի կարող խաղալ այդ քայլը
				continue;
			StepPlayer(i+1,a);// Խաղացողը կատարում է քայլ
		}
		tree.Insert(root,i,a[13]-a[6]); // Կառուցում ենք ծառի i-րդ որդին
		depth++;
		Alpa_Beta_Balance(root->Childs[i],a,depth); // Բալանսավորում ենք ծառը i-րդ որդու համար
		depth--;
	}
	if(depth % 2 == 0) // Զույգ խորության դեպքում
		tree.Max_Childs(root); // Գագաթի արժեքը դառնում է որդիների մաքսիմումի արժեքը
	else // Կենտ խորության դեպքում
		tree.Min_Childs(root); // Գագաթի արժեքը դառնում է որդիների մինիմումի արժեքը
}

int Game::Alpa_Beta()
{
	srand( (unsigned int)time(NULL)); 
	int area[14];
	copy(Area,Area+N,area);
	int d = 0; // ծառի բալանսավորումը պետք է սկսենք 0 խորությունից
	tree.Clear(); // մաքրում ենք ծառը
	tree.CreateRoot(INT_MIN); //  Կառուցում ենք ծառը միայն արմատի INT_MIN տվյալով 
	this->Alpa_Beta_Balance(tree.GetRoot(),area,d); // բալանսավորում ենք ծառը
	Node* p = tree.GetRoot();
	int i = rand()%6;
	// Ընտրում ենք լավագույն քայլերից կամայականը 
	while(true) // ???
	{
		if( ++i == N_Tree )
			i = 0;
		if( p->Childs[i] == NULL)
			continue;
		if( p->Childs[i]->Info == p->Info )
			break;
	}
	// Վերադարձնում ենք այն
	return i+1;
}

bool Game::StepPlayer(int position,int* adress)
{
	if(adress[--position] == 0 ) return false; // Եթե տվյալ դիրքի քարերի քանակը 0 է , ապա քայլ չի թույլատրվում
	int k = adress[position];
	int step_index = k;
	adress[position] = 0;
	while(k!=0)
	{
		if(++position == 13 )
			position = 0;
		adress[position]++;
		k--;
	}
	if(position < 6 && step_index > 7 && adress[position] > 1 ) // Եթե շրջանցել է հակառակորդի քարերը և հասել նորից իր քարերին , ապա վերջացրած դիրքից սկսում է նոր քայլ
	{
		StepPlayer(position+1,adress);
		return true;
	}
	while(position > 6 && ( adress[position] == 2 || adress[position] == 3 ) ) // Եթե վերջին քայլից հետո հակաառակորդի դաշտում է և տվյալ դաշտի քարերի քանակը 2 կամ 3 է 
	{
		adress[6] += adress[position]; // այդ դաշտի քարերը գերի են ընկնում 
		adress[position] = 0;
		position--; // փորձում ենք գերի վերցնել նրանից ձախ գտնվող դաշտի քարերը
	}
	if( adress[0] == 0 &&  adress[1] == 0 &&  adress[2] == 0 &&  adress[3] == 0 &&  adress[4] == 0 &&  adress[5] == 0 ) // Եթե խաղացողի բոլոր դաշտերում քարերը վերջացել են 
	{
		adress[13] += adress[7]+adress[8]+adress[9]+adress[10]+adress[11]+adress[12]; // ապա դրանք ընկնում են հակառակորդի նվաճած քարերի մեջ
		adress[7] = 0 ;adress[8] = 0 ;adress[9] = 0 ;adress[10] = 0 ;adress[11] = 0 ;adress[12] = 0;
	}
	else if( adress[7] == 0 &&  adress[8] == 0 &&  adress[9] == 0 &&  adress[10] == 0 &&  adress[11] == 0 &&  adress[12] == 0 )
	{
		adress[6] += (adress[0]+adress[1]+adress[2]+adress[3]+adress[4]+adress[5]);
		adress[0] = 0 ;adress[1] = 0 ;adress[2] = 0 ;adress[3] = 0 ;adress[4] = 0 ;adress[5] = 0;
	}
	return true;
}

bool Game::StepComputer(int position,int* adress)
{
	if(adress[(position+=6)] == 0 ) return false;
	int k = adress[position];
	int step_index = k;
	adress[position] = 0;
	while(k!=0)
	{
		if(++position == 14 )
			position = 0;
		if(position == 6 )
			position = 7;
		adress[position]++;
		k--;
	}
	if(position > 6 && position < 13 && step_index > 7 && adress[position] > 1)
	{
		StepComputer(position-6,adress);
		return true;
	}
	else
		while(position < 6 && position >=0 && ( adress[position] == 2 || adress[position] == 3 ) )
		{
			adress[13] += adress[position];
			adress[position] = 0;
			position--;
		}
	if( adress[7] == 0 &&  adress[8] == 0 &&  adress[9] == 0 &&  adress[10] == 0 &&  adress[11] == 0 &&  adress[12] == 0 )
	{
		adress[6] += (adress[0]+adress[1]+adress[2]+adress[3]+adress[4]+adress[5]);
		adress[0] = 0 ;adress[1] = 0 ;adress[2] = 0 ;adress[3] = 0 ;adress[4] = 0 ;adress[5] = 0;
	}
	else if( adress[0] == 0 &&  adress[1] == 0 &&  adress[2] == 0 &&  adress[3] == 0 &&  adress[4] == 0 &&  adress[5] == 0 )
	{
		adress[13] += adress[7]+adress[8]+adress[9]+adress[10]+adress[11]+adress[12];
		adress[7] = 0 ;adress[8] = 0 ;adress[9] = 0 ;adress[10] = 0 ;adress[11] = 0 ;adress[12] = 0;
	}
	return true;
}