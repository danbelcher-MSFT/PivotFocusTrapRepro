//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace PivotFocusTrapRepro
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed : Windows::UI::Xaml::Data::INotifyPropertyChanged
	{
	public:
		MainPage();

		virtual event Windows::UI::Xaml::Data::PropertyChangedEventHandler^ PropertyChanged;

		property Windows::Foundation::Collections::IVector<int>^ Collection
		{
			Windows::Foundation::Collections::IVector<int>^ get();
		}

		property bool DeleteVisible
		{
			bool get();
		}

	private:
		void OnVectorChanged(Windows::Foundation::Collections::IObservableVector<int>^ sender, Windows::Foundation::Collections::IVectorChangedEventArgs^ args);

		void OnAddButtonClicked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void OnDeleteButtonClicked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

	private:
		Platform::Collections::Vector<int>^ m_collection = ref new Platform::Collections::Vector<int>();
	};
}
