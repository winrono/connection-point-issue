// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include "Shobjidl_core.h"
#include <iostream>

class EventRouter : public IDispatch
{
public:
	EventRouter(IDispatch *);
	~EventRouter();

	void Add(DISPID dispid);

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppv) override;
	ULONG STDMETHODCALLTYPE AddRef() override;
	ULONG STDMETHODCALLTYPE Release() override;

	HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pctinfo) override;
	HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iti, LCID lcid, ITypeInfo **ti) override;
	HRESULT STDMETHODCALLTYPE GetIDsOfNames(REFIID riid, LPOLESTR *names, UINT names_count, LCID lcid, DISPID *dispid) override;
	HRESULT STDMETHODCALLTYPE Invoke(DISPID dispid,
		REFIID riid,
		LCID lcid,
		WORD wflags,
		DISPPARAMS *dp,
		VARIANT *result,
		EXCEPINFO *excepinfo,
		UINT *argerr) override;

private:
	IConnectionPoint * point_;
	int ref_count_ = 0;
	DWORD cookie_;
};

// TODO: reference additional headers your program requires here
