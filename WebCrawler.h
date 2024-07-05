// WebCrawler.h
#pragma once
#include "FileContentForm.h"
#include "LRUCache.h"
#include "Interface.h"
#include "Indexer.h"
#include "TextCrawler.h"
#include <msclr/marshal_cppstd.h>
using namespace std;

namespace PROJECT_DS {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class WebCrawler : public System::Windows::Forms::Form {
    public:
        Indexer* indexer;
    private: System::Windows::Forms::TextBox^ textBox4;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::TextBox^ textBox5;
    private: System::Windows::Forms::Label^ label1;


    public:
        Interface* i;
        WebCrawler(void) {
            InitializeComponent();
            indexer = new Indexer(100); // Initialize Indexer with cache size of 100
            i = new Interface(*indexer);
        }

    protected:
        ~WebCrawler() {
            if (components) {
                delete components;
            }
            this->!WebCrawler();
        }

        !WebCrawler() {
            delete indexer;
            delete i;
        }

    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::Button^ button1;

    private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
           void InitializeComponent(void) {
               this->textBox1 = (gcnew System::Windows::Forms::TextBox());
               this->textBox2 = (gcnew System::Windows::Forms::TextBox());
               this->textBox3 = (gcnew System::Windows::Forms::TextBox());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->textBox4 = (gcnew System::Windows::Forms::TextBox());
               this->button2 = (gcnew System::Windows::Forms::Button());
               this->textBox5 = (gcnew System::Windows::Forms::TextBox());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // 
               // textBox1
               // 
               this->textBox1->BackColor = System::Drawing::Color::AntiqueWhite;
               this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
               this->textBox1->Enabled = false;
               this->textBox1->Font = (gcnew System::Drawing::Font(L"Snap ITC", 45, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Italic | System::Drawing::FontStyle::Underline)),
                   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
               this->textBox1->ForeColor = System::Drawing::Color::DarkSalmon;
               this->textBox1->Location = System::Drawing::Point(25, 81);
               this->textBox1->Margin = System::Windows::Forms::Padding(0);
               this->textBox1->Name = L"textBox1";
               this->textBox1->Size = System::Drawing::Size(490, 97);
               this->textBox1->TabIndex = 0;
               this->textBox1->Text = L"GOOGLYY";
               this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
               this->textBox1->TextChanged += gcnew System::EventHandler(this, &WebCrawler::textBox1_TextChanged);
               // 
               // textBox2
               // 
               this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
               this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->textBox2->Location = System::Drawing::Point(25, 265);
               this->textBox2->Margin = System::Windows::Forms::Padding(4);
               this->textBox2->Multiline = true;
               this->textBox2->Name = L"textBox2";
               this->textBox2->Size = System::Drawing::Size(563, 211);
               this->textBox2->TabIndex = 2;
               // 
               // textBox3
               // 
               this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
               this->textBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->textBox3->Location = System::Drawing::Point(25, 200);
               this->textBox3->Margin = System::Windows::Forms::Padding(4);
               this->textBox3->Multiline = true;
               this->textBox3->Name = L"textBox3";
               this->textBox3->Size = System::Drawing::Size(438, 48);
               this->textBox3->TabIndex = 4;
               // 
               // button1
               // 
               this->button1->BackColor = System::Drawing::Color::DarkSalmon;
               this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                   static_cast<System::Int32>(static_cast<System::Byte>(192)));
               this->button1->Location = System::Drawing::Point(424, 198);
               this->button1->Margin = System::Windows::Forms::Padding(4);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(164, 50);
               this->button1->TabIndex = 5;
               this->button1->Text = L"SEARCH";
               this->button1->UseVisualStyleBackColor = false;
               this->button1->Click += gcnew System::EventHandler(this, &WebCrawler::button1_Click);
               // 
               // textBox4
               // 
               this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
               this->textBox4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->textBox4->Location = System::Drawing::Point(25, 13);
               this->textBox4->Margin = System::Windows::Forms::Padding(4);
               this->textBox4->Multiline = true;
               this->textBox4->Name = L"textBox4";
               this->textBox4->Size = System::Drawing::Size(747, 35);
               this->textBox4->TabIndex = 6;
               this->textBox4->TextChanged += gcnew System::EventHandler(this, &WebCrawler::textBox4_TextChanged);
               // 
               // button2
               // 
               this->button2->BackColor = System::Drawing::Color::DarkSalmon;
               this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
                   static_cast<System::Int32>(static_cast<System::Byte>(192)));
               this->button2->Location = System::Drawing::Point(780, 13);
               this->button2->Margin = System::Windows::Forms::Padding(4);
               this->button2->Name = L"button2";
               this->button2->Size = System::Drawing::Size(46, 35);
               this->button2->TabIndex = 7;
               this->button2->Text = L"S";
               this->button2->UseVisualStyleBackColor = false;
               this->button2->Click += gcnew System::EventHandler(this, &WebCrawler::button2_Click);
               // 
               // textBox5
               // 
               this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
               this->textBox5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->textBox5->Location = System::Drawing::Point(639, 121);
               this->textBox5->Margin = System::Windows::Forms::Padding(4);
               this->textBox5->Multiline = true;
               this->textBox5->Name = L"textBox5";
               this->textBox5->Size = System::Drawing::Size(162, 355);
               this->textBox5->TabIndex = 9;
               this->textBox5->TextChanged += gcnew System::EventHandler(this, &WebCrawler::textBox5_TextChanged);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->label1->ForeColor = System::Drawing::Color::DarkSalmon;
               this->label1->Location = System::Drawing::Point(633, 82);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(119, 32);
               this->label1->TabIndex = 10;
               this->label1->Text = L"History:";
               this->label1->Click += gcnew System::EventHandler(this, &WebCrawler::History_Click);
               // 
               // WebCrawler
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
               this->ClientSize = System::Drawing::Size(839, 506);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->textBox5);
               this->Controls->Add(this->button2);
               this->Controls->Add(this->textBox4);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->textBox3);
               this->Controls->Add(this->textBox2);
               this->Controls->Add(this->textBox1);
               this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
               this->Name = L"WebCrawler";
               this->Text = L"WebCrawler";
               this->Load += gcnew System::EventHandler(this, &WebCrawler::WebCrawler_Load);
               this->ResumeLayout(false);
               this->PerformLayout();

           }
#pragma endregion

    private: System::Void WebCrawler_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        System::String^ input = textBox3->Text;
         string query = msclr::interop::marshal_as< string>(input);

        // Perform the search and get sorted files
        indexer->indexAllTextFiles("C:\\Uni\\");
        auto sortedFiles = indexer->sortFilesByWordFrequency(query);
        indexer->addToSearchHistory(query);

        // Prepare the results string
         ostringstream results;
        results << "Files sorted by frequency of the word or query '" << query << "':\r\n";
        for (const auto& pair : sortedFiles) {
            results << pair.first << "\r\n"; //pair.first << " (" << pair.second << ")\r\n";
        }

        // Display the results in textBox2
        System::String^ resultStr = msclr::interop::marshal_as<System::String^>(results.str());
        textBox2->Text = resultStr;

         ifstream inputFile("search_history.txt");
        if (!inputFile.is_open()) {
            System::Windows::Forms::MessageBox::Show("Error: Unable to open data.txt");
            return;
        }

         stringstream buffer;
        buffer << inputFile.rdbuf();
        inputFile.close();
        System::String^ data = msclr::interop::marshal_as<System::String^>(buffer.str());
        textBox5->Text = data;
    }
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    System::String^ filePath = textBox4->Text;
    FileContentForm^ fileContentForm = gcnew FileContentForm(filePath);
    fileContentForm->Show();
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void History_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
    //System::Threading::Thread::Sleep(1000);
}
};
}
