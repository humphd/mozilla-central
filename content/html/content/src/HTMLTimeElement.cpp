/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "HTMLTimeElement.h"
#include "mozilla/dom/HTMLTimeElementBinding.h"
#include "nsContentUtils.h"
#include "nsGenericHTMLElement.h"
#include "nsGkAtoms.h"

// XXXhumph: doing this manually, since
// NS_IMPL_NS_NEW_HTML_ELEMENT(Track) assumes names with nsHTML* vs. HTML*
nsGenericHTMLElement*
NS_NewHTMLTimeElement(already_AddRefed<nsINodeInfo> aNodeInfo,
                       mozilla::dom::FromParser aFromParser)
{
  return new mozilla::dom::HTMLTimeElement(aNodeInfo);
}

namespace mozilla {
namespace dom {

HTMLTimeElement::HTMLTimeElement(already_AddRefed<nsINodeInfo> aNodeInfo)
    : nsGenericHTMLElement(aNodeInfo)
{
  SetIsDOMBinding();
}

HTMLTimeElement::~HTMLTimeElement()
{
}

NS_IMPL_ADDREF_INHERITED(HTMLTimeElement, Element)
NS_IMPL_RELEASE_INHERITED(HTMLTimeElement, Element)

NS_INTERFACE_TABLE_HEAD(HTMLTimeElement)
  NS_HTML_CONTENT_INTERFACE_TABLE1(HTMLTimeElement,
                                   nsIDOMHTMLElement)
  NS_HTML_CONTENT_INTERFACE_TABLE_TO_MAP_SEGUE(HTMLTimeElement,
                                               nsGenericHTMLElement)
NS_HTML_CONTENT_INTERFACE_MAP_END

NS_IMPL_ELEMENT_CLONE(HTMLTimeElement)

JSObject*
HTMLTimeElement::WrapNode(JSContext* cx, JSObject* scope, bool* triedToWrap)
{
  return HTMLTimeElementBinding::Wrap(cx, scope, this, triedToWrap);
}

bool
HTMLTimeElement::ParseAttribute(int32_t aNamespaceID, nsIAtom* aAttribute,
                                const nsAString& aValue, nsAttrValue& aResult)
{
  if (aAttribute == nsGkAtoms::datetime) {
//XXX parse date out
//    return aResult.ParseSpecialIntValue(aValue);
  }
  return nsGenericHTMLElement::ParseAttribute(aNamespaceID, aAttribute,
                                              aValue, aResult);
}

} // namespace dom
} // namespace mozilla
