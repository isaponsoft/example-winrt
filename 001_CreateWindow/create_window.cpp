/*
 * cl.exe /EHsc /std:c++17 001_create_window.cpp
 */
#include <iostream>
#include <windows.h>
#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.UI.Core.h>

#pragma comment(lib, "WindowsApp.lib")

using namespace winrt;

struct App : implements<App, Windows::ApplicationModel::Core::IFrameworkViewSource, Windows::ApplicationModel::Core::IFrameworkView>
{
	Windows::ApplicationModel::Core::IFrameworkView CreateView()
	{
		std::cout << "CreateView" << std::endl;
		return *this;
	}

	void Initialize(Windows::ApplicationModel::Core::CoreApplicationView const &)
	{
		std::cout << "Initialize" << std::endl;
	}

	void Load(hstring const&)
	{
		std::cout << "Load" << std::endl;
	}

	void Run()
	{
		std::cout << "RUN" << std::endl;

		Windows::UI::Core::CoreWindow		window		= Windows::UI::Core::CoreWindow::GetForCurrentThread();
		window.Activate();
	
		Windows::UI::Core::CoreDispatcher	dispatcher	= window.Dispatcher();
		dispatcher.ProcessEvents(Windows::UI::Core::CoreProcessEventsOption::ProcessUntilQuit);
	}

	void SetWindow(Windows::UI::Core::CoreWindow const & window)
	{
		std::cout << "SetWindow" << std::endl;
	}

	void Uninitialize()
	{
		std::cout << "Uninitialize" << std::endl;
	}
};


//int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
int main()
{
	std::cout << "main" << std::endl;
	try
	{
		winrt::init_apartment();
		Windows::ApplicationModel::Core::CoreApplication::Run(winrt::make<App>());
	}
	catch (winrt::hresult_error const& e)
	{
		std::cout << "Exception: " << winrt::to_string(e.message()) << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Exception: Unkown type" << std::endl;
	}
	return	0;
}
