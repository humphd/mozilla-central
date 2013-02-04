/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_HTMLTimeElement_h
#define mozilla_dom_HTMLTimeElement_h

#include "nsIDOMHTMLElement.h"
#include "nsGenericHTMLElement.h"
#include "nsGkAtoms.h"

namespace mozilla {
namespace dom {

class HTMLTimeElement MOZ_FINAL : public nsGenericHTMLElement,
                                  public nsIDOMHTMLElement
{
public:
  HTMLTimeElement(already_AddRefed<nsINodeInfo> aNodeInfo);
  virtual ~HTMLTimeElement();

  // nsISupports
  NS_DECL_ISUPPORTS_INHERITED

  // nsIDOMNode
  NS_FORWARD_NSIDOMNODE_TO_NSINODE

  // nsIDOMElement
  NS_FORWARD_NSIDOMELEMENT_TO_GENERIC

  // nsIDOMHTMLElement
  NS_FORWARD_NSIDOMHTMLELEMENT_TO_GENERIC

  // HTMLTimeElement WebIDL
  void GetDateTime(nsAString& aDateTime)
  {
    GetHTMLAttr(nsGkAtoms::datetime, aDateTime);
  }

  void SetDateTime(const nsAString& aDateTime)
  {
    SetHTMLAttr(nsGkAtoms::datetime, aDateTime);
  }

  virtual nsresult Clone(nsINodeInfo* aNodeInfo, nsINode** aResult) const;
  virtual nsIDOMNode* AsDOMNode() { return this; }

protected:
  virtual JSObject* WrapNode(JSContext* aCx, JSObject* aScope,
                             bool* aTriedToWrap) MOZ_OVERRIDE;
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_HTMLTimeElement_h
