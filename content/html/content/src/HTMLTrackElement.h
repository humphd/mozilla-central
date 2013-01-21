/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_HTMLTrackElement_h
#define mozilla_dom_HTMLTrackElement_h

#include "nsIDOMHTMLElement.h"
#include "nsIDOMEventTarget.h"
#include "nsGenericHTMLElement.h"
#include "nsGkAtoms.h"

namespace mozilla {
namespace dom {

class HTMLTrackElement : public nsGenericHTMLElement,
                         public nsIDOMHTMLElement
{
public:
  HTMLTrackElement(already_AddRefed<nsINodeInfo> aNodeInfo)
    : nsGenericHTMLElement(aNodeInfo)
  {
    SetIsDOMBinding();
  }
  virtual ~HTMLTrackElement();

  // nsISupports
  NS_DECL_ISUPPORTS_INHERITED

  // nsIDOMNode
  NS_FORWARD_NSIDOMNODE_TO_NSINODE

  // nsIDOMElement
  NS_FORWARD_NSIDOMELEMENT_TO_GENERIC

  // nsIDOMHTMLElement
  NS_FORWARD_NSIDOMHTMLELEMENT_TO_GENERIC

  // nsIDOMHTMLTrackElement
  NS_IMETHOD GetKind(nsAString& aKind);
  NS_IMETHOD SetKind(const nsAString& aKind);
  NS_IMETHOD GetSrc(nsAString& aSrc);
  NS_IMETHOD SetSrc(const nsAString& aSrc);
  NS_IMETHOD GetSrclang(nsAString& aSrclang);
  NS_IMETHOD SetSrclang(const nsAString& aSrclang);
  NS_IMETHOD GetLabel(nsAString& aLabel);
  NS_IMETHOD SetLabel(const nsAString& aLabel);

  // HTMLTrackElement WebIDL
  void GetKind(nsString& aKind)
  {
    GetHTMLAttr(nsGkAtoms::kind, aKind);
  }
  void SetKind(const nsAString& aKind, mozilla::ErrorResult& aError)
  {
    SetHTMLAttr(nsGkAtoms::kind, aKind, aError);
  }

  void GetSrc(nsString& aSrc)
  {
    GetHTMLAttr(nsGkAtoms::src, aSrc);
  }
  void SetSrc(const nsAString& aSrc, mozilla::ErrorResult& aError)
  {
    SetHTMLAttr(nsGkAtoms::src, aSrc, aError);
  }

  void GetSrclang(nsString& aSrclang)
  {
    GetHTMLAttr(nsGkAtoms::srclang, aSrclang);
  }
  void SetSrclang(const nsAString& aSrclang, mozilla::ErrorResult& aError)
  {
    SetHTMLAttr(nsGkAtoms::srclang, aSrclang, aError);
  }

  void GetLabel(nsString& aLabel)
  {
    GetHTMLAttr(nsGkAtoms::label, aLabel);
  }
  void SetLabel(const nsAString& aLabel, mozilla::ErrorResult& aError)
  {
    SetHTMLAttr(nsGkAtoms::label, aLabel, aError);
  }

  virtual nsresult Clone(nsINodeInfo *aNodeInfo, nsINode **aResult) const;
  virtual nsIDOMNode* AsDOMNode() { return this; }

protected:
  virtual JSObject* WrapNode(JSContext *aCx, JSObject *aScope,
                             bool *aTriedToWrap) MOZ_OVERRIDE;
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_HTMLTrackElement_h
