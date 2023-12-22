#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include "Tree.h"

namespace TI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FormTree
	/// </summary>
	public ref class FormTree : public System::Windows::Forms::Form
	{
	public:
		Tree^ treeInstance;
		tnode* root;
		int tempNode;
		int point;
		int tempAddInput;
		int tempRemoveInput;
		FormTree(void)
		{
			InitializeComponent();
			treeInstance = gcnew Tree();
			root = nullptr;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormTree()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelAddNode;
	protected:
	private: System::Windows::Forms::Label^ labelRemoveNode;
	private: System::Windows::Forms::TextBox^ textBoxAddNode;
	private: System::Windows::Forms::TextBox^ textBoxRemoveNode;
	private: System::Windows::Forms::Label^ labelResultText1;
	private: System::Windows::Forms::Label^ labelResultText2;
	private: System::Windows::Forms::Label^ labelResultWidth;
	private: System::Windows::Forms::Label^ labelResultDepth;
	private: System::Windows::Forms::Button^ buttonAddNode;
	private: System::Windows::Forms::Button^ buttonRemoveNode;

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
			this->labelAddNode = (gcnew System::Windows::Forms::Label());
			this->labelRemoveNode = (gcnew System::Windows::Forms::Label());
			this->textBoxAddNode = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRemoveNode = (gcnew System::Windows::Forms::TextBox());
			this->labelResultText1 = (gcnew System::Windows::Forms::Label());
			this->labelResultText2 = (gcnew System::Windows::Forms::Label());
			this->labelResultWidth = (gcnew System::Windows::Forms::Label());
			this->labelResultDepth = (gcnew System::Windows::Forms::Label());
			this->buttonAddNode = (gcnew System::Windows::Forms::Button());
			this->buttonRemoveNode = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelAddNode
			// 
			this->labelAddNode->AutoSize = true;
			this->labelAddNode->Location = System::Drawing::Point(13, 13);
			this->labelAddNode->Name = L"labelAddNode";
			this->labelAddNode->Size = System::Drawing::Size(83, 13);
			this->labelAddNode->TabIndex = 0;
			this->labelAddNode->Text = L"Добавить узел";
			// 
			// labelRemoveNode
			// 
			this->labelRemoveNode->AutoSize = true;
			this->labelRemoveNode->Location = System::Drawing::Point(13, 43);
			this->labelRemoveNode->Name = L"labelRemoveNode";
			this->labelRemoveNode->Size = System::Drawing::Size(76, 13);
			this->labelRemoveNode->TabIndex = 1;
			this->labelRemoveNode->Text = L"Удалить узел";
			// 
			// textBoxAddNode
			// 
			this->textBoxAddNode->Location = System::Drawing::Point(102, 10);
			this->textBoxAddNode->Name = L"textBoxAddNode";
			this->textBoxAddNode->Size = System::Drawing::Size(100, 20);
			this->textBoxAddNode->TabIndex = 2;
			this->textBoxAddNode->TextChanged += gcnew System::EventHandler(this, &FormTree::textBoxAddNode_TextChanged);
			// 
			// textBoxRemoveNode
			// 
			this->textBoxRemoveNode->Location = System::Drawing::Point(102, 40);
			this->textBoxRemoveNode->Name = L"textBoxRemoveNode";
			this->textBoxRemoveNode->Size = System::Drawing::Size(100, 20);
			this->textBoxRemoveNode->TabIndex = 3;
			this->textBoxRemoveNode->TextChanged += gcnew System::EventHandler(this, &FormTree::textBoxRemoveNode_TextChanged);
			// 
			// labelResultText1
			// 
			this->labelResultText1->AutoSize = true;
			this->labelResultText1->Location = System::Drawing::Point(13, 77);
			this->labelResultText1->Name = L"labelResultText1";
			this->labelResultText1->Size = System::Drawing::Size(90, 13);
			this->labelResultText1->TabIndex = 4;
			this->labelResultText1->Text = L"Обход в ширину:";
			// 
			// labelResultText2
			// 
			this->labelResultText2->AutoSize = true;
			this->labelResultText2->Location = System::Drawing::Point(11, 99);
			this->labelResultText2->Name = L"labelResultText2";
			this->labelResultText2->Size = System::Drawing::Size(92, 13);
			this->labelResultText2->TabIndex = 5;
			this->labelResultText2->Text = L"Обход в глубину:";
			// 
			// labelResultWidth
			// 
			this->labelResultWidth->AutoSize = true;
			this->labelResultWidth->Location = System::Drawing::Point(109, 77);
			this->labelResultWidth->Name = L"labelResultWidth";
			this->labelResultWidth->Size = System::Drawing::Size(35, 13);
			this->labelResultWidth->TabIndex = 6;
			this->labelResultWidth->Text = L"пусто";
			// 
			// labelResultDepth
			// 
			this->labelResultDepth->AutoSize = true;
			this->labelResultDepth->Location = System::Drawing::Point(109, 99);
			this->labelResultDepth->Name = L"labelResultDepth";
			this->labelResultDepth->Size = System::Drawing::Size(35, 13);
			this->labelResultDepth->TabIndex = 7;
			this->labelResultDepth->Text = L"пусто";
			// 
			// buttonAddNode
			// 
			this->buttonAddNode->Location = System::Drawing::Point(208, 10);
			this->buttonAddNode->Name = L"buttonAddNode";
			this->buttonAddNode->Size = System::Drawing::Size(75, 23);
			this->buttonAddNode->TabIndex = 8;
			this->buttonAddNode->Text = L"Добавить";
			this->buttonAddNode->UseVisualStyleBackColor = true;
			this->buttonAddNode->Visible = false;
			this->buttonAddNode->Click += gcnew System::EventHandler(this, &FormTree::buttonAddNode_Click);
			// 
			// buttonRemoveNode
			// 
			this->buttonRemoveNode->Location = System::Drawing::Point(208, 37);
			this->buttonRemoveNode->Name = L"buttonRemoveNode";
			this->buttonRemoveNode->Size = System::Drawing::Size(75, 23);
			this->buttonRemoveNode->TabIndex = 9;
			this->buttonRemoveNode->Text = L"Удалить";
			this->buttonRemoveNode->UseVisualStyleBackColor = true;
			this->buttonRemoveNode->Visible = false;
			this->buttonRemoveNode->Click += gcnew System::EventHandler(this, &FormTree::buttonRemoveNode_Click);
			// 
			// FormTree
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(306, 126);
			this->Controls->Add(this->buttonRemoveNode);
			this->Controls->Add(this->buttonAddNode);
			this->Controls->Add(this->labelResultDepth);
			this->Controls->Add(this->labelResultWidth);
			this->Controls->Add(this->labelResultText2);
			this->Controls->Add(this->labelResultText1);
			this->Controls->Add(this->textBoxRemoveNode);
			this->Controls->Add(this->textBoxAddNode);
			this->Controls->Add(this->labelRemoveNode);
			this->Controls->Add(this->labelAddNode);
			this->Name = L"FormTree";
			this->Text = L"FormTree";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBoxAddNode_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBoxAddNode->Text != "") {
			tempAddInput = Convert::ToInt32(textBoxAddNode->Text);
			buttonAddNode->Visible = true;
		}
	}
	private: System::Void textBoxRemoveNode_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBoxRemoveNode->Text != "") {
			tempRemoveInput = Convert::ToInt32(textBoxRemoveNode->Text);
			buttonRemoveNode->Visible = true;
		}
	}
	private: System::Void buttonAddNode_Click(System::Object^ sender, System::EventArgs^ e) {
		root = treeInstance->insertNode(root, tempAddInput);
		textBoxAddNode->Text = "";
		labelResultDepth->Text = "";
		labelResultWidth->Text = "";
		string resultDepth = treeInstance->depthSearch(root);
		labelResultDepth->Text = gcnew String(resultDepth.c_str());
		string resultWidth = treeInstance->widthSearch(root);
		labelResultWidth->Text = gcnew String(resultWidth.c_str());
	}
	private: System::Void buttonRemoveNode_Click(System::Object^ sender, System::EventArgs^ e) {
		treeInstance->deleteNode(root, tempRemoveInput);
		textBoxRemoveNode->Text = "";
		labelResultDepth->Text = "";
		labelResultWidth->Text = "";
		string resultDepth = treeInstance->depthSearch(root);
		labelResultDepth->Text = gcnew String(resultDepth.c_str());
		string resultWidth = treeInstance->widthSearch(root);
		labelResultWidth->Text = gcnew String(resultWidth.c_str());
	}
	};
}