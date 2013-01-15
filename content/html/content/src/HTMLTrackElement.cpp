/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "mozilla/dom/HTMLTrackElement.h"
#include "mozilla/dom/HTMLTrackElementBinding.h"
#include "mozilla/ErrorResult.h"
#include "nsContentUtils.h"

NS_IMPL_NS_NEW_HTML_ELEMENT(Track)
//DOMCI_NODE_DATA(HTMLTrackElement, mozilla::dom::HTMLTrackElement)

namespace mozilla {
namespace dom {

HTMLTrackElement::~HTMLTrackElement()
{
}

NS_IMPL_ADDREF_INHERITED(HTMLTrackElement, Element)
NS_IMPL_RELEASE_INHERITED(HTMLTrackElement, Element)

// QueryInterface implementation for HTMLTrackElement
NS_INTERFACE_TABLE_HEAD(HTMLTrackElement)
  NS_HTML_CONTENT_INTERFACE_TABLE1(HTMLTrackElement,
                                   nsIDOMHTMLElement)
  NS_HTML_CONTENT_INTERFACE_TABLE_TO_MAP_SEGUE(HTMLTrackElement,
                                               nsGenericHTMLElement)
NS_HTML_CONTENT_INTERFACE_MAP_END

NS_IMPL_ELEMENT_CLONE(HTMLTrackElement)

JSObject*
HTMLTrackElement::WrapNode(JSContext* cx, JSObject* scope, bool* triedToWrap)
{
  return HTMLTrackElementBinding::Wrap(cx, scope, this, triedToWrap);
}

// attribute DOMString kind
NS_IMETHODIMP
HTMLTrackElement::GetKind(nsAString& aKind)
{
  nsString kind;
  GetKind(kind);
  aKind = kind;
  return NS_OK;
}

NS_IMETHODIMP
HTMLTrackElement::SetKind(const nsAString& aKind)
{
  mozilla::ErrorResult rv;
  SetKind(aKind, rv);
  return rv.ErrorCode();
}

// attribute DOMString src
NS_IMETHODIMP
HTMLTrackElement::GetSrc(nsAString& aSrc)
{
  nsString src;
  GetKind(src);
  aSrc = src;
  return NS_OK;
}

NS_IMETHODIMP
HTMLTrackElement::SetSrc(const nsAString& aSrc)
{
  mozilla::ErrorResult rv;
  SetSrc(aSrc, rv);
  return rv.ErrorCode();
}

// attribute DOMString srclang
NS_IMETHODIMP
HTMLTrackElement::GetSrclang(nsAString& aSrclang)
{
  nsString srclang;
  GetKind(srclang);
  aSrclang = srclang;
  return NS_OK;
}

NS_IMETHODIMP
HTMLTrackElement::SetSrclang(const nsAString& aSrclang)
{
  mozilla::ErrorResult rv;
  SetSrclang(aSrclang, rv);
  return rv.ErrorCode();
}

// attribute DOMString label
NS_IMETHODIMP
HTMLTrackElement::GetLabel(nsAString& aLabel)
{
  nsString label;
  GetKind(label);
  aLabel = label;
  return NS_OK;
}

NS_IMETHODIMP
HTMLTrackElement::SetLabel(const nsAString& aLabel)
{
  mozilla::ErrorResult rv;
  SetLabel(aLabel, rv);
  return rv.ErrorCode();
}

} // namespace dom
} // namespace mozilla
