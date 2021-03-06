// GameForm.h
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
#include "Game.h"
#include "StartGame.h"
int lun[14] = { 6,6,6,6,6,6,0,6,6,6,6,6,6,0}; // Քարերի զանգված
Game game(lun); // Համակարգչի քայլի մտածման դասի օբյեկտ

int * const adress = game.GetAreaPtr();
namespace FunofMachines {

	/// <summary>
	/// Summary for GameForm
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::ToolStripMenuItem^  exiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  timerIntervalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tickToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tickToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  tickToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  tickToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  infoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gamesRulesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  newGameToolStripMenuItem;
	public:
		GameForm(void)
		{
			InitializeComponent();
			InitializeMyComponents(); // Պատրաստել դաշտերը
			this->UpdateGameData(); // Թարմացնել տվյալները
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		array<Label^>^ Lunok; // Դաշտերի զանգված 
		StartGame startgameoption; // Նոր խաղ դասի օբյեկտ
	private: System::ComponentModel::IContainer^  components;
			 /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timerIntervalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tickToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tickToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tickToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tickToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gamesRulesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->gameToolStripMenuItem, 
				this->timerIntervalToolStripMenuItem, this->infoToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(884, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// gameToolStripMenuItem
			// 
			this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->newGameToolStripMenuItem, 
				this->exiToolStripMenuItem});
			this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
			this->gameToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->gameToolStripMenuItem->Text = L"Game";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->newGameToolStripMenuItem->Text = L"&New Game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::newGameToolStripMenuItem_Click);
			// 
			// exiToolStripMenuItem
			// 
			this->exiToolStripMenuItem->Name = L"exiToolStripMenuItem";
			this->exiToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->exiToolStripMenuItem->Text = L"Exit";
			this->exiToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::exiToolStripMenuItem_Click);
			// 
			// timerIntervalToolStripMenuItem
			// 
			this->timerIntervalToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->tickToolStripMenuItem, 
				this->tickToolStripMenuItem1, this->tickToolStripMenuItem2, this->tickToolStripMenuItem3});
			this->timerIntervalToolStripMenuItem->Name = L"timerIntervalToolStripMenuItem";
			this->timerIntervalToolStripMenuItem->Size = System::Drawing::Size(92, 20);
			this->timerIntervalToolStripMenuItem->Text = L"Timer Interval";
			// 
			// tickToolStripMenuItem
			// 
			this->tickToolStripMenuItem->Name = L"tickToolStripMenuItem";
			this->tickToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->tickToolStripMenuItem->Text = L"250 tick";
			this->tickToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::tickToolStripMenuItem_Click);
			// 
			// tickToolStripMenuItem1
			// 
			this->tickToolStripMenuItem1->Name = L"tickToolStripMenuItem1";
			this->tickToolStripMenuItem1->Size = System::Drawing::Size(120, 22);
			this->tickToolStripMenuItem1->Text = L"500 tick";
			this->tickToolStripMenuItem1->Click += gcnew System::EventHandler(this, &GameForm::tickToolStripMenuItem1_Click);
			// 
			// tickToolStripMenuItem2
			// 
			this->tickToolStripMenuItem2->Name = L"tickToolStripMenuItem2";
			this->tickToolStripMenuItem2->Size = System::Drawing::Size(120, 22);
			this->tickToolStripMenuItem2->Text = L"750 tick";
			this->tickToolStripMenuItem2->Click += gcnew System::EventHandler(this, &GameForm::tickToolStripMenuItem2_Click);
			// 
			// tickToolStripMenuItem3
			// 
			this->tickToolStripMenuItem3->Name = L"tickToolStripMenuItem3";
			this->tickToolStripMenuItem3->Size = System::Drawing::Size(120, 22);
			this->tickToolStripMenuItem3->Text = L"1000 tick";
			this->tickToolStripMenuItem3->Click += gcnew System::EventHandler(this, &GameForm::tickToolStripMenuItem3_Click);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->gamesRulesToolStripMenuItem, 
				this->aboutToolStripMenuItem});
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->infoToolStripMenuItem->Text = L"Info";
			// 
			// gamesRulesToolStripMenuItem
			// 
			this->gamesRulesToolStripMenuItem->Name = L"gamesRulesToolStripMenuItem";
			this->gamesRulesToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->gamesRulesToolStripMenuItem->Text = L"Rules";
			this->gamesRulesToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::gamesRulesToolStripMenuItem_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &GameForm::GameForm_timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &GameForm::GameForm_timer2_Tick);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::aboutToolStripMenuItem_Click);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 562);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"GameForm";
			this->Text = L"Fun of Machines";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void InitializeMyComponents() // Պատրաստել դաշտերը
	{
		Lunok = gcnew array<Label^>(N);
		for(int i = 0 ; i < N ; ++i )
		{		
			Lunok[i] = gcnew Label();
			Lunok[i]->BackColor = System::Drawing::Color::Orange;
			Lunok[i]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			Lunok[i]->Font = gcnew System::Drawing::Font(this->Font->ToString(),25);
			this->Controls->Add(Lunok[i]);
		}
		for(int i = 0 ; i < 6 ; ++i ) // Խաղացողի դաշտեր
		{
			Lunok[i]->Size = System::Drawing::Size(60,60);
			Lunok[i]->Location = System::Drawing::Point(150+i*100,450);
			Lunok[i]->Image = gcnew Bitmap(Application::StartupPath + "\\ResourseFunofMachines\\lunok.bmp");
			Lunok[i]->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			Lunok[i]->Cursor = System::Windows::Forms::Cursors::Hand;

		}
			// Խաղացողի բանկ
			Lunok[6]->Size = System::Drawing::Size(60,150);
			Lunok[6]->Location = System::Drawing::Point(750,250);
			Lunok[6]->Image = gcnew Bitmap(Application::StartupPath + "\\ResourseFunofMachines\\kalax.bmp");
			Lunok[6]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		for(int i = 7 ; i < 13 ; ++i ) // Համակարգչի դաշտեր
		{
			Lunok[i]->Size = System::Drawing::Size(60,60);
			Lunok[i]->Location = System::Drawing::Point(650-(i-7)*100,150);
			Lunok[i]->Image = gcnew Bitmap(Application::StartupPath + "\\ResourseFunofMachines\\lunok.bmp");
			Lunok[i]->TextAlign = System::Drawing::ContentAlignment::TopCenter;
		}
			// Համակարգչի բանկ
			Lunok[13]->Size = System::Drawing::Size(60,150);
			Lunok[13]->Location = System::Drawing::Point(50,250);
			Lunok[13]->Image = gcnew Bitmap(Application::StartupPath + "\\ResourseFunofMachines\\kalax.bmp");
			Lunok[13]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		
		// Խաղացողի դաշտերի հետ կապում ենք չխկոց (click) իրադարձությունը 
		Lunok[0]->MouseClick += gcnew MouseEventHandler(this, & GameForm::Lunok1_Click);
		Lunok[1]->MouseClick += gcnew MouseEventHandler(this, & GameForm::Lunok2_Click);
		Lunok[2]->MouseClick += gcnew MouseEventHandler(this, & GameForm::Lunok3_Click);
		Lunok[3]->MouseClick += gcnew MouseEventHandler(this, & GameForm::Lunok4_Click);
		Lunok[4]->MouseClick += gcnew MouseEventHandler(this, & GameForm::Lunok5_Click);
		Lunok[5]->MouseClick += gcnew MouseEventHandler(this, & GameForm::Lunok6_Click);
		//////// End Lunoks ///////////

		//////// Others /////////////
	}
	void StepPlayer(int pos) // Խաղացողի քայլ
	{
		if( !System::Convert::ToInt32(Lunok[pos-1]->Text) ) // Եթե տվյալ դաշտեւմ քարերի քանակը 0 է
		{
			MessageBox::Show("Invalide Step");
			return;
		}
		for(int i = 0 ; i < N_Tree ; ++i ) // Խաղացողի դաշտերը դարձնում ենք անհասանելի
			Lunok[i]->Enabled = false;
		Lunok[pos-1]->BackColor = Color::Red;
		this->Refresh(); // Form-ի թարմացում
		this->StepPlayer_Graphics(pos); // Խաղացողի քայլը
		
	}
	void StepComputer() // Համակարգչի քայլ
	{
		int m = game.Alpa_Beta(); // Ընտրում ենք լավագույն քայլը
		if( !System::Convert::ToInt32(Lunok[m+6]->Text) )
			MessageBox::Show("Invalide Computer");
		Lunok[m+6]->BackColor = Color::Red;
		this->Refresh(); // Form-ի թարմացում
	//	System::Threading::Thread::Sleep(1000); // քնել 1 վայրկյան
		this->StepComputer_Graphics( m ); // համակարգչի քայլը
	}
	void OverStep()
	{
		for(int i = 0 ; i < N ; ++i )
			Lunok[i]->BackColor = Color::Orange;
		if( !GameOver() ) // Եթե խաղը ավարտված է
			for(int i = 0 ; i < N_Tree ; ++i ) // խաղացողի դաշտերը դարձնում ենք հասանելի
				Lunok[i]->Enabled = true;
		else // այլապես
			for(int i = 0 ; i < N ; ++i ) // բոլոր դաշտերը դարձնում ենք անհասանելի
				Lunok[i]->Enabled = false;
	}
	bool GameOver()
	{
		if(adress[6] > 36 ) // եթե խաղացողի բանկում քարերի քանակը մեծ է 36-ից
		{
			MessageBox::Show("You Win!"); // Խաղացողը հանթում է
			return true;
		}
		if(adress[13] > 36 ) // եթե համակարգչի բանկում քարերի քանակը մեծ է 36-ից
		{
			MessageBox::Show("You Lose."); // Խաղացողը պարտվում է
			return true;
		}
		if(adress[6] == 36 && adress[6] == 36 ) // եթե խաղացողի բանկում և համակարգչի բանկում քարերի քանակները 36 են 
		{		
			MessageBox::Show("No winer."); // Ոչ-ոքի արդյունք
			return true;
		}
		return false; // Խաղը չի ավարտվել
	}
	void Lunok1_Click(Object^ sender,MouseEventArgs^ e) // Խաղ 1-ին դաշտից
	{
		StepPlayer(1);
	}
	void Lunok2_Click(Object^ sender,MouseEventArgs^ e) // Խաղ 2-րդ դաշտից
	{
		StepPlayer(2);
	}
	void Lunok3_Click(Object^ sender,MouseEventArgs^ e) // Խաղ 3-րդ դաշտից
	{
		StepPlayer(3);
	}
	void Lunok4_Click(Object^ sender,MouseEventArgs^ e) // Խաղ 4-րդ դաշտից
	{
		StepPlayer(4);
	}
	void Lunok5_Click(Object^ sender,MouseEventArgs^ e) // Խաղ 5-րդ դաշտից
	{
		StepPlayer(5);
	}
	void Lunok6_Click(Object^ sender,MouseEventArgs^ e) // Խաղ 6-րդ դաշտից
	{
		StepPlayer(6);
	}

	void UpdateGameData() // Թամացնել դաշտերի արդյունքները
	{
		for(int i = 0 ; i < N ; ++i )
		{
			Lunok[i]->Text = adress[i].ToString();
		}
		this->Refresh();
	}
	private: int k,pos,step_index; // Օգտագործվուն են քայլի կատարման համար
	void StepPlayer_Graphics(int position) // Խաղացողի խաղը
	{
		pos = position;
		if(adress[--pos] == 0 ) return;
		k = adress[pos];
		step_index = k;
		adress[pos] = 0;
		System::Threading::Thread::Sleep(1000);
		this->UpdateGameData(); // 
		timer1->Enabled = true;
	}
	private: System::Void GameForm_timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{	
		if(k!=0)
		{	
			if(++pos == 13 )
				pos = 0;
			adress[pos]++;
			k--;
			this->UpdateGameData(); // Թարմացնել տվյալները
			return;
		}
		if(pos < 6 && step_index > 7 && adress[pos] > 1)
		{
			timer1->Enabled = false;
			StepPlayer_Graphics(pos+1);
			return ;
		}
		else
			if(pos > 6 && ( adress[pos] == 2 || adress[pos] == 3 ) )
			{			
				adress[6] += adress[pos];
				adress[pos] = 0;
				pos--;
				this->UpdateGameData(); // Թարմացնել տվյալները
				return;
			}
		if( adress[0] == 0 &&  adress[1] == 0 &&  adress[2] == 0 &&  adress[3] == 0 &&  adress[4] == 0 &&  adress[5] == 0 )
		{
			adress[13] += adress[7]+adress[8]+adress[9]+adress[10]+adress[11]+adress[12];
			adress[7] = 0 ;adress[8] = 0 ;adress[9] = 0 ;adress[10] = 0 ;adress[11] = 0 ;adress[12] = 0;
			this->UpdateGameData(); // Թարմացնել տվյալները
		}
		else if( adress[7] == 0 &&  adress[8] == 0 &&  adress[9] == 0 &&  adress[10] == 0 &&  adress[11] == 0 &&  adress[12] == 0 )
		{
			adress[6] += (adress[0]+adress[1]+adress[2]+adress[3]+adress[4]+adress[5]);
			adress[0] = 0 ;adress[1] = 0 ;adress[2] = 0 ;adress[3] = 0 ;adress[4] = 0 ;adress[5] = 0;
			this->UpdateGameData(); // Թարմացնել տվյալները
		}
		timer1->Enabled = false;
		this->StepComputer();
	}


	void StepComputer_Graphics(int position)  // Համակարգչի խաղը
	{
		pos = position;
		if(adress[(pos+=6)] == 0 ) return;
		k = adress[pos];
		step_index = k;
		adress[pos] = 0;
		System::Threading::Thread::Sleep(1000);
		this->UpdateGameData(); // Թարմացնել տվյալները
		timer2->Enabled = true;
	}
		private: System::Void GameForm_timer2_Tick(System::Object^  sender, System::EventArgs^  e)
	{	
		if(k!=0)
		{

			if(++pos == 14 )
				pos = 0;
			if(pos == 6 )
				pos = 7;
			adress[pos]++;
			k--;
			this->UpdateGameData(); // Թարմացնել տվյալները
			return;
		}
		if(pos > 6 && pos < 13 && step_index > 7 && adress[pos] > 1)
		{
			timer2->Enabled = false;
			StepComputer_Graphics(pos-6);
			return;
		}
		else
			if(pos < 6 && pos >=0 && ( adress[pos] == 2 || adress[pos] == 3 ) )
			{
				adress[13] += adress[pos];
				adress[pos] = 0;
				pos--;
				this->UpdateGameData(); // Թարմացնել տվյալները
				return;
			}
		if( adress[7] == 0 &&  adress[8] == 0 &&  adress[9] == 0 &&  adress[10] == 0 &&  adress[11] == 0 &&  adress[12] == 0 )
		{
			adress[6] += (adress[0]+adress[1]+adress[2]+adress[3]+adress[4]+adress[5]);
			adress[0] = 0 ;adress[1] = 0 ;adress[2] = 0 ;adress[3] = 0 ;adress[4] = 0 ;adress[5] = 0;
			this->UpdateGameData(); // Թարմացնել տվյալները
		}
		else if( adress[0] == 0 &&  adress[1] == 0 &&  adress[2] == 0 &&  adress[3] == 0 &&  adress[4] == 0 &&  adress[5] == 0 )
		{
			adress[13] += adress[7]+adress[8]+adress[9]+adress[10]+adress[11]+adress[12];
			adress[7] = 0 ;adress[8] = 0 ;adress[9] = 0 ;adress[10] = 0 ;adress[11] = 0 ;adress[12] = 0;
			this->UpdateGameData(); // Թարմացնել տվյալները
		}
		timer2->Enabled = false;
		this->OverStep();
	}
	private: System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) // Նոր խաղ
			 {
				 timer1->Enabled = false;
				 timer2->Enabled = false;
				 for(int i = 0 ; i < N ; ++i )
				 Lunok[i]->BackColor = Color::Orange;
				 for(int i = 0 ; i < N ; ++i )
				 Lunok[i]->Enabled = true;
				 this->startgameoption.ShowDialog();
				 game.Dispose();
				 game = Game(lun,(int)this->startgameoption.numericUpDown1->Value+1);// Տվյալների սկզբնական վերարժեքավորում
				 this->UpdateGameData(); // Թարմացնել տվյալները
				 if(this->startgameoption.radioButton2->Checked) // Եթե սկսելու է համակարգիչը
				 {
					 for(int i = 0 ; i < N_Tree ; ++i )
						 Lunok[i]->Enabled = false;
					 this->StepComputer();
				 }
			 }

private: System::Void exiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) // Դուրս գալ
		 {
			 Application::Exit();
		 }
private: System::Void tickToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) // Խաղի արագություն 250
		 {
			 timer1->Interval = 250;
			 timer2->Interval = 250;
		 }
private: System::Void tickToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) // Խաղի արագություն 500
		 {
			 timer1->Interval = 500;
			 timer2->Interval = 500;
		 }
private: System::Void tickToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) // Խաղի արագություն 750
		 {
			 timer1->Interval = 750;
			 timer2->Interval = 750;
		 }
private: System::Void tickToolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) // Խաղի արագություն 1000
		 {
			 timer1->Interval = 1000;
			 timer2->Interval = 1000;
		 }
private: System::Void gamesRulesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) // Խաղի կանոնները
		 {
			 System::Diagnostics::Process::Start(Application::StartupPath + "\\ResourseFunofMachines\\Gamerules.htm"); // բացել խաղի կանոնները
		 }
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) // Խաղի մասին
		 {
			 System::Diagnostics::Process::Start(Application::StartupPath + "\\ResourseFunofMachines\\AboutGame.htm");
		 }
};
}
