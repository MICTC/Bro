#include <string>
#include <iostream>

#pragma once

namespace MICGit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(69, 121);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Pull from \"develop\"";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(69, 166);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(141, 39);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Pull from \"feature\"";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(69, 211);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(141, 39);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Push onto \"feature\"";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 49);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(268, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(6, 75);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(68, 30);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Verify";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Enter the SSH URL of your GitHub repo.";
			this->label1->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			System::String ^ gitUrl = textBox1->Text;
		}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			system("call git checkout -b feature");
			system("call git pull origin develop");
			
		}
			 
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 
		}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			system("call git checkout -b feature");
			system("call git pull origin feature");
		}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			system("call git status");
			system("call git add -u");
			system("call git add .");
			system("call git status");
			system("SET /p comment=Please enter the comment for your commit:");
			system("call git commit -m '%comment%'");
			system("call git pull origin feature");
			system("call git push origin feature");
		 }
};
};

