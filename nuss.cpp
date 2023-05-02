#pragma once
#include <string>
//#include <msclr\marshal_cppstd.h>
#include "C:\Users\Asus\source\repos\GUI1\bmtExtractor.h"
#include "C:\Users\Asus\source\repos\GUI1\Header1.h"

namespace GUI1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Text;
	using namespace System::Threading::Tasks;
	using namespace System::Windows::Forms;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Rectangle^ Rect;
		Rectangle newRect;
		Point LocXY;
		Point LocX1Y1;
		Pen^ selPen;
		Bitmap^ bmp;
		Bitmap^ Fl1Bmp;
		Bitmap^ cropImg;
		Graphics^ g;
		Point^ poin;
		OpenFileDialog^ fl1;

	private: System::Windows::Forms::PictureBox^ pictureBox2;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;


	public:
		///selPen.Color=
		bool IsMouseDown = false;

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		void MarshalString(String^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
		std::string* str;
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
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(31, 14);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 80);
			this->button1->TabIndex = 0;
			this->button1->Text = L"SelectImg";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(285, 14);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(194, 80);
			this->button2->TabIndex = 1;
			this->button2->Text = L"ChooseFile";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(31, 174);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(768, 597);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(1082, 174);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(490, 597);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(840, 14);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(177, 80);
			this->label2->TabIndex = 7;
			this->label2->Text = L"size";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(1098, 14);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(177, 80);
			this->label3->TabIndex = 9;
			this->label3->Text = L"cords";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 122);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 16);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Nu";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1796, 793);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		   if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		   {
			   pictureBox1->Image = Image::FromFile(ofd->FileName);
			   pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		   }
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		fl1 = gcnew OpenFileDialog();
		std::string a;
		
		//fl1->Filter = "Text files (*.bmt)|*.bmt";
		if (fl1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			
			MarshalString(fl1->FileName,a );
			Bmtextractor(a);
			Fl1Bmp = gcnew Bitmap("C:\\Users\\Asus\\source\\repos\\GUI1\\GUI1\\image.bmp");
			pictureBox1->Image = Fl1Bmp;
			
			//label2->Text = pictureBox1->Width.ToString()+" " + pictureBox1->Height.ToString();
			//pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
		}

	}
private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	IsMouseDown = true;
	LocXY = e->Location;
}
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (IsMouseDown == true)
	{
		LocX1Y1 = e->Location;
		Refresh();
	}
}
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (IsMouseDown == true)
	{
		
		LocX1Y1 = e->Location;
		IsMouseDown = false;
		if (Rect != nullptr) {
			poin = gcnew Point(0, 0);
			bmp = gcnew Bitmap(pictureBox1->Image, pictureBox1->Width, pictureBox1->Height);
			cropImg = gcnew Bitmap(Rect->Width, Rect->Height);
			g = Graphics::FromImage(cropImg);
			g->DrawImage(bmp,0,0,newRect,GraphicsUnit::Pixel);
			pictureBox2->Image = cropImg;
			label2->Text = "Width:"+Rect->Width.ToString() + "\nHeight:" + Rect->Height.ToString();
			label3->Text = "X,Y:"+ LocXY.X.ToString() + "," + LocXY.Y.ToString()+"; X1Y1:"+ LocX1Y1.X.ToString() +"," + LocX1Y1.Y.ToString() +";";
			
		}
		float Nunum;
		std::string a;
		MarshalString(fl1->FileName, a);
		Bmtextractor(a);
		Nunum = countNu(pictureBox1->Width, pictureBox1->Height, a, LocXY.X, LocXY.Y, LocX1Y1.X, LocX1Y1.Y);
		label1->Text = Nunum.ToString();
		
	}
}
private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	
	selPen = gcnew Pen(Color::Red);
	e->Graphics->DrawRectangle(selPen, GetRect());

	
}
    Rectangle GetRect()
	{
		Rect = gcnew Rectangle();
		Rect->X = Math::Min(LocXY.X, LocX1Y1.X);
		newRect.X = Math::Min(LocXY.X, LocX1Y1.X);
		Rect->Y = Math::Min(LocXY.Y, LocX1Y1.Y);
		newRect.Y = Math::Min(LocXY.Y, LocX1Y1.Y);
		Rect->Width = Math::Abs(LocXY.X- LocX1Y1.X);
		newRect.Width = Math::Abs(LocXY.X - LocX1Y1.X);
		Rect->Height = Math::Abs(LocXY.Y-LocX1Y1.Y);
		newRect.Height = Math::Abs(LocXY.Y - LocX1Y1.Y);
	
		return *Rect;
	}


private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
