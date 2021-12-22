#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <locale.h>
#include <vector>
namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::IO;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(103, 41);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(262, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Считать цифры из файла";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(103, 96);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(262, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(103, 138);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(262, 33);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Начать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(488, 242);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(106, 181);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(258, 121);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(728, 347);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:System::IO::StreamReader^ sr;
	private:bool doneReading;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = "";

		if (doneReading) return;
		if (sr == nullptr) sr = gcnew System::IO::StreamReader("c:\\Users\\Nigga\\source\\repos\\Project2\\Project2\\Numbers.txt");

		for (int i = 0; i < 5; i++)
		{
			String^ line = sr->ReadLine();
			if (line == nullptr)
			{
				doneReading = true;
				sr->Close();
				break;
			}
			textBox1->AppendText(line + "\n");
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		setlocale(LC_ALL, "rus");
		ifstream fh("Numbers.txt");
		vector<string> vs;
		time_t ltime;
		errno_t err;
		time(&ltime);
		time_t now = time(0);
		char* dt = ctime(&now);
		label1->Text = "ФИО:\nСайнаро Умар Абукарович, группа к504\n\nТекущие дата и время:\n" + gcnew System::String(dt);
		richTextBox1->Text = File::ReadAllText(L"Numbers.txt");
		richTextBox1->ReadOnly = true;
	}
};
}
