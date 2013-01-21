/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "HTMLTrackElement.h"
#include "mozilla/dom/HTMLTrackElementBinding.h"

NS_IMPL_NS_NEW_HTML_ELEMENT(Track)

namespace mozilla {
namespace dom {

HTMLTrackElement::~HTMLTrackElement()
{
}

NS_IMPL_ADDREF_INHERITED(HTMLTrackElement, Element)
NS_IMPL_RELEASE_INHERITED(HTMLTrackElement, Element)

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

} // namespace dom
} // namespace mozilla
