//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace PivotFocusTrapRepro;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();

	m_collection->VectorChanged += ref new VectorChangedEventHandler<int>(this, &MainPage::OnVectorChanged);
}

IVector<int>^ MainPage::Collection::get()
{
	return m_collection;
}

bool MainPage::DeleteVisible::get()
{
	return m_collection->Size > 0;
}

void MainPage::OnVectorChanged(IObservableVector<int>^ sender, IVectorChangedEventArgs^ args)
{
	PropertyChanged(this, ref new PropertyChangedEventArgs(L"DeleteVisible"));
}

void MainPage::OnAddButtonClicked(Object^ sender, RoutedEventArgs^ e)
{
	m_collection->Append(m_collection->Size);
}

void MainPage::OnDeleteButtonClicked(Object^ sender, RoutedEventArgs^ e)
{
	AddButton->Focus(::FocusState::Programmatic);
	m_collection->Clear();
}
