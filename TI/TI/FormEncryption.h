#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <array>
#include <algorithm>
#include <string>
#include <Windows.h>
#include <msclr/marshal_cppstd.h>
#undef max

namespace TI {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для FormEncryption
	/// </summary>
	public ref class FormEncryption : public System::Windows::Forms::Form
	{
	public:
		String^ Input_;
		int DictionarySize_ = 0;
		int BufferSize_ = 0;
		int Type_ = 0;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ resultGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;


	private: System::Windows::Forms::Button^ button1;
	public:
		FormEncryption(void)
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
		~FormEncryption()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::Label^ textLabel;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::TextBox^ dictionaryBox;


	private: System::Windows::Forms::Label^ dictionaryLabel;
	private: System::Windows::Forms::Label^ bufferLabel;
	private: System::Windows::Forms::TextBox^ bufferBox;


	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textLabel = (gcnew System::Windows::Forms::Label());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->dictionaryBox = (gcnew System::Windows::Forms::TextBox());
			this->dictionaryLabel = (gcnew System::Windows::Forms::Label());
			this->bufferLabel = (gcnew System::Windows::Forms::Label());
			this->bufferBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->resultGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Тип кодирования";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(115, 13);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(50, 17);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"LZ77";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &FormEncryption::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(115, 37);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(50, 17);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"LZ78";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &FormEncryption::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(115, 61);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(52, 17);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"LZSS";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &FormEncryption::radioButton3_CheckedChanged);
			// 
			// textLabel
			// 
			this->textLabel->AutoSize = true;
			this->textLabel->Location = System::Drawing::Point(63, 90);
			this->textLabel->Name = L"textLabel";
			this->textLabel->Size = System::Drawing::Size(45, 13);
			this->textLabel->TabIndex = 4;
			this->textLabel->Text = L"Фраза:";
			this->textLabel->Visible = false;
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(110, 83);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(197, 20);
			this->textBox->TabIndex = 5;
			this->textBox->Visible = false;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &FormEncryption::textBox_TextChanged);
			// 
			// dictionaryBox
			// 
			this->dictionaryBox->Location = System::Drawing::Point(110, 104);
			this->dictionaryBox->Name = L"dictionaryBox";
			this->dictionaryBox->Size = System::Drawing::Size(197, 20);
			this->dictionaryBox->TabIndex = 7;
			this->dictionaryBox->Visible = false;
			this->dictionaryBox->TextChanged += gcnew System::EventHandler(this, &FormEncryption::dictionaryBox_TextChanged);
			// 
			// dictionaryLabel
			// 
			this->dictionaryLabel->AutoSize = true;
			this->dictionaryLabel->Location = System::Drawing::Point(14, 111);
			this->dictionaryLabel->Name = L"dictionaryLabel";
			this->dictionaryLabel->Size = System::Drawing::Size(94, 13);
			this->dictionaryLabel->TabIndex = 6;
			this->dictionaryLabel->Text = L"Размер словаря:";
			this->dictionaryLabel->Visible = false;
			// 
			// bufferLabel
			// 
			this->bufferLabel->AutoSize = true;
			this->bufferLabel->Location = System::Drawing::Point(19, 132);
			this->bufferLabel->Name = L"bufferLabel";
			this->bufferLabel->Size = System::Drawing::Size(89, 13);
			this->bufferLabel->TabIndex = 8;
			this->bufferLabel->Text = L"Размер буфера:";
			this->bufferLabel->Visible = false;
			// 
			// bufferBox
			// 
			this->bufferBox->Location = System::Drawing::Point(110, 125);
			this->bufferBox->Name = L"bufferBox";
			this->bufferBox->Size = System::Drawing::Size(197, 20);
			this->bufferBox->TabIndex = 9;
			this->bufferBox->Visible = false;
			this->bufferBox->TextChanged += gcnew System::EventHandler(this, &FormEncryption::bufferBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(374, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Результат:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(443, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(213, 23);
			this->button1->TabIndex = 12;
			this->button1->Text = L"НЕ НАЖИМАТЬ, ВЫЛЕЗЕТ АМОГУС";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FormEncryption::button1_Click);
			// 
			// resultGrid
			// 
			this->resultGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->resultGrid->ColumnHeadersVisible = false;
			this->resultGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->resultGrid->Location = System::Drawing::Point(377, 37);
			this->resultGrid->Name = L"resultGrid";
			this->resultGrid->RowHeadersVisible = false;
			this->resultGrid->Size = System::Drawing::Size(299, 298);
			this->resultGrid->TabIndex = 13;
			this->resultGrid->Visible = false;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// FormEncryption
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 357);
			this->Controls->Add(this->resultGrid);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->bufferBox);
			this->Controls->Add(this->bufferLabel);
			this->Controls->Add(this->dictionaryBox);
			this->Controls->Add(this->dictionaryLabel);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->textLabel);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label1);
			this->Name = L"FormEncryption";
			this->Text = L"FormEncryption";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton1->Checked) {
			resultGrid->Visible = false;
			resultGrid->Rows->Clear();
			radioButton2->Checked = false;
			radioButton3->Checked = false;
			textLabel->Visible = true;
			textBox->Visible = true;
			dictionaryLabel->Visible = true;
			dictionaryBox->Visible = true;
			bufferLabel->Visible = true;
			bufferBox->Visible = true;
			textBox->Text = "";
			dictionaryBox->Text = "";
			bufferBox->Text = "";
			Type_ = 1;
		}
		else {

		}
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton2->Checked) {
			resultGrid->Visible = false;
			resultGrid->Rows->Clear();
			radioButton1->Checked = false;
			radioButton3->Checked = false;
			textLabel->Visible = true;
			textBox->Visible = true;
			dictionaryLabel->Visible = true;
			dictionaryBox->Visible = true;
			bufferLabel->Visible = false;
			bufferBox->Visible = false;
			textBox->Text = "";
			dictionaryBox->Text = "";
			bufferBox->Text = "";
			Type_ = 2;
		}
		else {

		}
	}

	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (radioButton3->Checked) {
			resultGrid->Visible = false;
			resultGrid->Rows->Clear();
			radioButton1->Checked = false;
			radioButton2->Checked = false;
			textLabel->Visible = true;
			textBox->Visible = true;
			dictionaryLabel->Visible = true;
			dictionaryBox->Visible = true;
			bufferLabel->Visible = true;
			bufferBox->Visible = true;
			textBox->Text = "";
			dictionaryBox->Text = "";
			bufferBox->Text = "";
			Type_ = 3;
		}
		else {

		}
	}

	private: System::Void textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		Input_ = textBox->Text;
	}

	private: System::Void dictionaryBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (dictionaryBox->Text != "") {
			DictionarySize_ = Convert::ToInt32(dictionaryBox->Text);
		}
	}

	private: System::Void bufferBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (bufferBox->Text != "") {
			BufferSize_ = Convert::ToInt32(bufferBox->Text);
		}
	}

		   void MarshalString(String^ s, string& os) {
			   using namespace Runtime::InteropServices;
			   const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			   os = chars;
			   Marshal::FreeHGlobal(IntPtr((void*)chars));
		   }

	private: void algorithmLZ77() {
		string inputUser;
		MarshalString(Input_, inputUser);
		vector<vector<string>> outputModel;
		int indexChar = 0;
		while (indexChar < inputUser.length()) {
			int bestLength = 0;
			int bestOffset = 0;
			string nextChar = "";
			int maxOffset = min(indexChar, DictionarySize_);
			int maxLength = min(static_cast<int>(inputUser.length()) - indexChar, BufferSize_);
			for (int offset = 1; offset <= maxOffset; offset++) {
				for (int length = 1; length <= maxLength; length++) {
					string stringWindow = inputUser.substr(indexChar - offset, length);
					string stringBuffer = inputUser.substr(indexChar, length);
					if (stringWindow == stringBuffer && length > bestLength) {
						bestLength = length;
						bestOffset = (offset - DictionarySize_) * (-1);
						if (indexChar + length < inputUser.length()) {
							nextChar = inputUser.substr(indexChar + length, 1);
						}
					}
				}
			}
			if (indexChar == inputUser.length() - 1) {
				outputModel.push_back({ inputUser.substr(max(0, indexChar - DictionarySize_), indexChar), inputUser.substr(indexChar, min(indexChar + BufferSize_, static_cast<int>(inputUser.length()))),"<0,0," + inputUser.substr(indexChar, 1) + ">" });
			}
			else {
				outputModel.push_back({ inputUser.substr(max(0, indexChar - DictionarySize_), indexChar),inputUser.substr(indexChar, min(indexChar + BufferSize_, static_cast<int>(inputUser.length()))),"<" + to_string(bestOffset) + "," + to_string(bestLength) + "," + (bestLength > 0 ? nextChar : inputUser.substr(indexChar, 1)) + ">" });
			}
			indexChar += bestLength + 1;
		}
		resultGrid->Visible = true;
		resultGrid->ColumnCount = 3;
		resultGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
		resultGrid->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;

		for (size_t i = 0; i < outputModel.size(); i++) {
			string& str = outputModel[i][1];
			/*if (str.length() > BufferSize_) {
				str = str.substr(0, BufferSize_);
			}
			else if (str.length() < BufferSize_) {
				int padding = BufferSize_ - str.length();
				str += string(padding, ' ');
			}
			string& leng = outputModel[i][0];
			if (leng.length() > DictionarySize_) {
				leng = leng.substr(0, DictionarySize_);
			}
			else if (leng.length() < DictionarySize_) {
				int padding = DictionarySize_ - leng.length();
				leng = string(padding, ' ') + leng;
			}*/
			string dictionaryStr = outputModel[i][0].substr(0, DictionarySize_);
			string bufferStr = outputModel[i][1].substr(0, BufferSize_);
			resultGrid->Rows->Add(gcnew String(dictionaryStr.c_str()), gcnew String(bufferStr.c_str()), gcnew String(outputModel[i][2].c_str()));
		}
	}

	private: static pair<string, int> FindMinFrequency(const unordered_map<string, int>& frequency) {
		pair<string, int> minPair = make_pair("", numeric_limits<int>::max());
		for (const auto& entry : frequency) {
			if (entry.second < minPair.second) {
				minPair = entry;
			}
		}
		return minPair;
	}

	private: void algorithmLZ78() {
		string inputUser;
		MarshalString(Input_, inputUser);
		vector<string> dictionary;
		int tempPosition = 0;
		dictionary.push_back("");
		unordered_map<string, int> frequency;
		frequency[""] = 0;
		vector<array<string, 3>> outputModel;
		outputModel.push_back({ "''", "", "0" });
		int i = 0;
		while (i < inputUser.length()) {
			string windowSymbols = string(1, inputUser[i]);
			int index = distance(dictionary.begin(), find(dictionary.begin(), dictionary.end(), windowSymbols));
			while (index != dictionary.size() && i < inputUser.length() - 1) {
				i++;
				windowSymbols += inputUser[i];
				index = distance(dictionary.begin(), find(dictionary.begin(), dictionary.end(), windowSymbols));
			}
			if (index == dictionary.size()) {
				string code = "<" + to_string(distance(dictionary.begin(), find(dictionary.begin(), dictionary.end(), windowSymbols.substr(0, windowSymbols.length() - 1)))) + ", '" + windowSymbols.back() + "'>";
				outputModel.push_back({ "'" + windowSymbols + "'", code, to_string(dictionary.size()) });
				if (dictionary.size() == DictionarySize_) {
					auto lastUsed = FindMinFrequency(frequency);
					dictionary.erase(
						remove(dictionary.begin(), dictionary.end(), lastUsed.first),
						dictionary.end()
					);
					frequency.erase(lastUsed.first);
				}
				dictionary.push_back(windowSymbols);
				frequency[windowSymbols] = 1;
			}
			else {
				frequency[windowSymbols]++;
			}
			i++;
		}
		string checkLastTwoSymbols = inputUser.length() > 1 ? inputUser.substr(inputUser.length() - 2) : "";
		string lastItemOutputModel = dictionary.back();
		if (lastItemOutputModel.find(checkLastTwoSymbols) == string::npos) {
			string lastSymbol = inputUser.substr(i - 1);
			string code = "<" + to_string(distance(dictionary.begin(), find(dictionary.begin(), dictionary.end(), ""))) + ", '" + lastSymbol + "'>";
			outputModel.push_back({ "'" + lastSymbol + "'", code, to_string(dictionary.size()) });
		}
		resultGrid->Visible = true;
		resultGrid->ColumnCount = 3;
		resultGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
		resultGrid->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
		for (size_t i = 0; i < outputModel.size(); i++) {
			//char tempDictionarySize = to_string(DictionarySize_)[1];
			if (tempPosition > DictionarySize_ && outputModel[i][1][1] == to_string(DictionarySize_)[0])
				outputModel[i][1][1] = '0';
			resultGrid->Rows->Add(gcnew String(outputModel[i][0].c_str()), gcnew String(outputModel[i][1].c_str()), Convert::ToString(tempPosition));
			tempPosition++;
		}
	}

	private: void algorithmLZSS() {
		string inputUser;
		MarshalString(Input_, inputUser);
		vector<vector<string>> outputModel;
		string dictionary = "";
		string buffer = inputUser.substr(0, min(BufferSize_, static_cast<int>(inputUser.length())));
		inputUser = inputUser.substr(buffer.length());
		while (!buffer.empty()) {
			int offset = 0;
			int length = 0;
			for (int i = 1; i <= buffer.length(); i++) {
				string subStr = buffer.substr(0, i);
				int position = dictionary.rfind(subStr);
				if (position != -1) {
					offset = DictionarySize_ - static_cast<int>(dictionary.length()) + position;
					length = subStr.length();
				}
				else {
					break;
				}
			}
			string code;
			int codeLength;
			if (length > 0) {
				code = "1<" + to_string(offset) + "," + to_string(length) + ">";
				codeLength = static_cast<int>(log2(DictionarySize_)) + static_cast<int>(log2(BufferSize_)) + 2;
			}
			else {
				code = "0'" + buffer.substr(0, 1) + "'";
				codeLength = 9;
			}
			outputModel.push_back({ dictionary, buffer, code, to_string(codeLength) });
			int shiftSize = max(length, 1);
			dictionary += buffer.substr(0, shiftSize);
			if (dictionary.length() > DictionarySize_) {
				dictionary = dictionary.substr(dictionary.length() - DictionarySize_);
			}
			buffer = buffer.substr(shiftSize);
			if (buffer.length() < BufferSize_ && !inputUser.empty()) {
				int addSize = min(static_cast<int>(BufferSize_ - buffer.length()), static_cast<int>(inputUser.length()));
				buffer += inputUser.substr(0, addSize);
				inputUser = inputUser.substr(addSize);
			}
		}
		resultGrid->Visible = true;
		resultGrid->ColumnCount = 4;
		resultGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::AllCells;
		resultGrid->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;
		for (size_t i = 0; i < outputModel.size(); i++) {
			resultGrid->Rows->Add(gcnew String(outputModel[i][0].c_str()), gcnew String(outputModel[i][1].c_str()), gcnew String(outputModel[i][2].c_str()), gcnew String(outputModel[i][3].c_str()));
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Type_ == 1)
			algorithmLZ77();
		else if (Type_ == 2)
			algorithmLZ78();
		else
			algorithmLZSS();
	}
	};
}
