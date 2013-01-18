/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 et tw=78: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_TextTrack_h
#define mozilla_dom_TextTrack_h

#include "mozilla/dom/TextTrackCue.h"
#include "mozilla/dom/TextTrackCueList.h"

#include "nsCycleCollectionParticipant.h"

namespace mozilla {
namespace dom {

class TextTrackCue;

class TextTrack MOZ_FINAL : public nsISupports,
                            public nsWrapperCache
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(TextTrack)

  // TextTrack WebIDL
  TextTrack(nsISupports *aParent) : mParent(aParent)
  {
    SetIsDOMBinding();
  }

  ~TextTrack()
  {
    mParent = nullptr;
  }

  virtual JSObject* WrapObject(JSContext* aCx, JSObject* aScope,
                               bool* aTriedToWrap);

  nsISupports* GetParentObject()
  {
    return mParent;
  }

  void GetKind(nsAString& aKind)
  {
    aKind = mKind;
  }

  void GetLabel(nsAString& aLabel)
  {
    aLabel = mLabel;
  }

  void GetLanguage(nsAString& aLanguage)
  {
    aLanguage = mLanguage;
  }

  void GetInBandMetadataTrackDispatchType(nsAString& aType)
  {
    aType = mType;
  }

  TextTrackCueList*
  GetCues()
  {
    // XXXhumph: todo
    return nullptr;
  }

  TextTrackCueList*
  GetActiveCues()
  {
    // XXXhumph: todo
    return nullptr;
  }


/*
  NS_IMETHOD GetKind(nsAString& aKind);
  NS_IMETHOD GetLabel(nsAString& aLabel);
  NS_IMETHOD GetLanguage(nsAString& aLanguage);
  NS_IMETHOD GetInBandMetadataTrackDispatchType(nsAString& aInBandMetadataTrackDispatchType);
*/

// XXXhumph: todo
//  NS_IMETHOD GetMode(TextTrackMode& aMode);
//  NS_IMETHOD SetMode(const TextTrackMode& aMode);

/*
  NS_IMETHOD GetCues(TextTrackCueList& aCues);
  NS_IMETHOD GetActiveCues(TextTrackCueList& aActiveCues);
*/

  void AddCue(TextTrackCue& cue)
  {
    // XXXhumph: todo
  }

  void RemoveCue(TextTrackCue& cue)
  {
    // XXXhumph: todo
  }

  // XXXhumph: need to do eventhandler stuff still, see webidl

private:
  nsCOMPtr<nsISupports> mParent;

  nsString mKind;
  nsString mLabel;
  nsString mLanguage;
  nsString mType;

  // XXXhumph: need list of cues, active cues...
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_TextTrack_h
