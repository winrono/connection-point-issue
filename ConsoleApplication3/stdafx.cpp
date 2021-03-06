// stdafx.cpp : source file that includes just the standard includes
// ConsoleApplication3.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"


EventRouter::EventRouter(IDispatch * ptr) : cookie_(NULL), point_(NULL)
{
	// TODO: reduce multiple cp request
	IConnectionPointContainer * cpc;
	HRESULT hr = ptr->QueryInterface(__uuidof(IConnectionPointContainer), (void **)&cpc);
	if (FAILED(hr))
	{
		return;
	}

	IEnumConnectionPoints * ecp;

	hr = cpc->EnumConnectionPoints(&ecp);
	if (FAILED(hr))
	{
		return;
	}

	ULONG fetched;
	IConnectionPoint * cp;

	hr = ecp->Next(1, &cp, &fetched);
	if (FAILED(hr) || fetched != 1)
	{
		return;
	}

	point_ = cp;
}

EventRouter::~EventRouter()
{
}

void EventRouter::Add(DISPID dispid)
{
	if (!point_)
	{
		return;
	}

	if (cookie_ == 0)
	{
		point_->Advise(this, &cookie_);
	}
}

HRESULT EventRouter::QueryInterface(REFIID riid, void **ppv)
{
	if (!ppv)
	{
		return E_POINTER;
	}

	if (::IsEqualGUID(riid, IID_IUnknown) || ::IsEqualGUID(riid, IID_IDispatch))
	{
		*ppv = this;
		AddRef();
		return S_OK;
	}

	*ppv = NULL;
	return E_NOINTERFACE;
}

ULONG EventRouter::AddRef()
{
	return ++ref_count_;
}

ULONG EventRouter::Release()
{
	std::cout << "Release is called" << std::endl;
	if (--ref_count_ == 0)
	{
		delete this;
	}
	return ref_count_;
}

HRESULT EventRouter::GetTypeInfoCount(UINT *pctinfo)
{
	return E_NOTIMPL;
}

HRESULT EventRouter::GetTypeInfo(UINT iti, LCID lcid, ITypeInfo **ti)
{
	return E_NOTIMPL;
}

HRESULT EventRouter::GetIDsOfNames(REFIID riid, LPOLESTR *names, UINT names_count, LCID lcid, DISPID *dispid)
{
	return E_NOTIMPL;
}

HRESULT EventRouter::Invoke(DISPID dispid,
	REFIID riid,
	LCID lcid,
	WORD flags,
	DISPPARAMS *dp,
	VARIANT *result,
	EXCEPINFO *excepinfo,
	UINT *argerr)
{
	std::cout << "Invoked!" << std::endl;
	return S_OK;
}

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
