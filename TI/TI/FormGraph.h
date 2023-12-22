#pragma once
#include <cstddef>
namespace TI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для FormGraph
	/// </summary>
	
	public ref class FormGraph : public System::Windows::Forms::Form
	{
	public:

		int Vertixes_;
		int MatrixType_;	//0 -неориентированный, 1 - ориентированный
		int** AdjacencyMatrix_;	//Матрица смежности
		int** AdjacencyList_;	//Список смежности
		int** IncidenceMatrix_;	//Матрица инцидентности
		int Edges_;
		int First_;
		int Second_;
		int cFirst_ = 0;
		int cSecond_ = 0;
		int MAX = 100;
		int CurrentPossition_ = 0;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	public:
		int type;
		FormGraph(void)
		{
			InitializeComponent();
			Vertixes_ = 0;
			MatrixType_ = 0;
			Edges_ = 0;
			AdjacencyMatrix_ = new int* [MAX];
			for (int i = 0; i < MAX; i++)
				AdjacencyMatrix_[i] = new int[MAX];
			AdjacencyList_ = new int* [MAX];
			for (int i = 0; i < MAX; i++)
				AdjacencyList_[i] = new int[MAX];
			IncidenceMatrix_ = new int* [MAX];
			for (int i = 0; i < MAX; i++)
				IncidenceMatrix_[i] = new int[MAX];
			for (int i = 0; i < MAX; i++)
				for (int j = 0; j < MAX; j++) {
					AdjacencyMatrix_[i][j] = 0;
					AdjacencyList_[i][j] = NULL;
					IncidenceMatrix_[i][j] = 0;
				}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormGraph()
		{
			if (components)
			{
				delete components;
			}
			for (int i = 0; i < MAX; i++) {
				delete[] AdjacencyMatrix_[i];
				delete[] AdjacencyList_[i];
				delete[] IncidenceMatrix_[i];
			}
			delete[] AdjacencyMatrix_;
			delete[] AdjacencyList_;
			delete[] IncidenceMatrix_;
		}
		FormGraph(int tmp_vertixes, int tmp_type) {	
			Vertixes_ = tmp_vertixes;
			MatrixType_ = tmp_type;
			Edges_ = 0;
			AdjacencyMatrix_ = new int* [MAX];
			for (int i = 0; i < MAX; i++)
				AdjacencyMatrix_[i] = new int[MAX];
			AdjacencyList_ = new int* [MAX];
			for (int i = 0; i < MAX; i++)
				AdjacencyList_[i] = new int[MAX];
			IncidenceMatrix_ = new int* [MAX];
			for (int i = 0; i < MAX; i++)
				IncidenceMatrix_[i] = new int[MAX];
			for (int i = 0; i < MAX; i++)
				for (int j = 0; j < MAX; j++) {
					AdjacencyMatrix_[i][j] = 0;
					AdjacencyList_[i][j] = NULL;
					IncidenceMatrix_[i][j] = 0;
				}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	protected:

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
		List<TextBox^>^ textBoxes2 = gcnew List<TextBox^>();
		List<TextBox^>^ textBoxes3 = gcnew List<TextBox^>();
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(129, 9);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(44, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &FormGraph::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Количество вершин:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(60, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Тип графа";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Неориентированный", L"Ориентированный" });
			this->comboBox1->Location = System::Drawing::Point(129, 36);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(168, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &FormGraph::comboBox1_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Пары рёбер:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(381, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Результат:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(381, 36);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(37, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Пусто";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(450, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(230, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"НЕ НАЖИМАТЬ, ВЫЛЕЗЕТ АМОГУС";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormGraph::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(16, 78);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(85, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Новое ребро";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FormGraph::button2_Click);
			// 
			// FormGraph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(690, 324);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"FormGraph";
			this->Text = L"FormGraph";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void addElem() {
		if (MatrixType_ == 0) {
			AdjacencyMatrix_[First_][Second_] = AdjacencyMatrix_[Second_][First_] = 1;
			IncidenceMatrix_[First_][Edges_] = IncidenceMatrix_[Second_][Edges_] = 1;
		}
		else {
			AdjacencyMatrix_[First_][Second_] = 1;
			IncidenceMatrix_[First_][Edges_] = 1;
			IncidenceMatrix_[Second_][Edges_] = -1;
		}
		Edges_++;
	}

	private: void generateAdjacencyList() {
		for (int i = 0; i <= Vertixes_; i++) {
			int temp = 0;
			for (int j = 0; j <= Vertixes_; j++) {
				if (AdjacencyMatrix_[i][j] == 1) {
					AdjacencyList_[i][temp] = j;
					temp++;
				}
			}
		}
	}

	private: void check() {
		if (cFirst_ == cSecond_)
			addElem();
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text != "") {
			Vertixes_ = Convert::ToInt32(textBox1->Text);
		}
		else {
			for each (TextBox ^ textBox in textBoxes2)
			{
				this->Controls->Remove(textBox);
			}
			for each (TextBox ^ textBox in textBoxes3)
			{
				this->Controls->Remove(textBox);
			}
			textBoxes2->Clear();
			textBoxes3->Clear();
			CurrentPossition_ = 0;
		}

	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (comboBox1->SelectedItem->ToString() == "Неориентированный") {
			type = 1;
		}
		else {
			type = 0; 
		}
	}

	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ textBox = safe_cast<TextBox^>(sender);
		First_ = Convert::ToInt32(textBox->Text);
		cFirst_++;
		check();
	}

	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ textBox = safe_cast<TextBox^>(sender);
		Second_ = Convert::ToInt32(textBox->Text);
		cSecond_++;
		check();
	}

	private: void printGraph() {
			   generateAdjacencyList();
			   String^ labelText = "Список смежности \n";
			   for (int i = 0; i <= Vertixes_; i++) {
				   bool tmp_column = false;
				   int j = 0;
				   labelText += "V" + i + ": ";
				   do {
					   if (AdjacencyList_[i][j] != NULL) {
						   labelText += "V" + AdjacencyList_[i][j] + " ";
						   j++;
					   }
					   else
						   tmp_column = true;
				   } while (tmp_column != true);
				   labelText += ";\n";
			   }
			   labelText += "\nМатрица смежности \n";
			   labelText += "   ";
			   for (int i = 0; i <= Vertixes_; i++) {
				   labelText += " V" + i;
			   }
			   labelText += "\n";
			   for (int i = 0; i <= Vertixes_; i++) {
				   labelText += "V" + i + ":";
				   for (int j = 0; j <= Vertixes_; j++) {
					   labelText += String::Format("{0, 3}", AdjacencyMatrix_[i][j]);
				   }
				   labelText += "\n";
			   }
			   labelText += "\nМатрица инцидентности \n";
			   labelText += "   ";
			   for (int i = 1; i <= Edges_; i++) {
				   labelText += " E" + i;
			   }
			   labelText += "\n";
			   for (int i = 0; i <= Vertixes_; i++) {
				   labelText += "V" + i + ":";
				   for (int j = 0; j < Edges_; j++) {
					   labelText += String::Format("{0, 3}", IncidenceMatrix_[i][j]);
				   }
				   labelText += "\n";
			   }
			   label5->Text = labelText;
		   }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		printGraph();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ newTextBox2 = gcnew TextBox();
		newTextBox2->Location = System::Drawing::Point(129, 60 + CurrentPossition_ * 30);
		this->Controls->Add(newTextBox2);
		textBoxes2->Add(newTextBox2);
		TextBox^ newTextBox3 = gcnew TextBox();
		newTextBox3->Location = System::Drawing::Point(229, 60 + CurrentPossition_ * 30);
		this->Controls->Add(newTextBox3);
		textBoxes3->Add(newTextBox3);
		CurrentPossition_++;
		for each (TextBox ^ textBox in textBoxes2)
		{
			textBox->TextChanged += gcnew System::EventHandler(this, &FormGraph::textBox2_TextChanged);
		}
		for each (TextBox ^ textBox in textBoxes3)
		{
			textBox->TextChanged += gcnew System::EventHandler(this, &FormGraph::textBox3_TextChanged);
		}
	}
};
}
