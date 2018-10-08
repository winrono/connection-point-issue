// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

int main()
{
	HRESULT     hr;
	IShellLink* pISL;
	CoInitializeEx(NULL, COINIT_MULTITHREADED);
	GUID guid;
	std::wstring prog_id = L"Excel.Application";
	hr = ::CLSIDFromProgID(prog_id.c_str(), (LPCLSID)&guid);
	IUnknown * unk;
	hr = ::GetActiveObject(guid, NULL, &unk);
	IDispatch * ptr;
	hr = unk->QueryInterface(&ptr);
	EventRouter * router = new EventRouter(ptr);
	router->Add(1558);

	std::getchar();
	return 0;
}

