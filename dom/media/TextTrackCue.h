/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 et tw=78: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_TextTrackCue_h
#define mozilla_dom_TextTrackCue_h

#include "TextTrack.h"
#include "nsCycleCollectionParticipant.h"
#include "mozilla/dom/DocumentFragment.h"
#include "nsDOMEventTargetHelper.h"

namespace mozilla {
namespace dom {

class TextTrack;

class TextTrackCue MOZ_FINAL : public nsDOMEventTargetHelper
{
public:
  NS_DECL_ISUPPORTS_INHERITED
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(TextTrackCue)
  NS_FORWARD_NSIDOMEVENTTARGET(nsDOMEventTargetHelper::)

  TextTrackCue(nsISupports* aGlobal,  const double aStartTime,
               const double aEndTime, const nsAString& aText);
  ~TextTrackCue();

  static already_AddRefed<TextTrackCue>
  Constructor(nsISupports* aGlobal,  const double aStartTime,
              const double aEndTime, const nsAString& aText,
              ErrorResult& aRv)
  {
    return new TextTrackCue(aGlobal, aStartTime, aEndTime, aText);
  }

  virtual JSObject* WrapObject(JSContext* aCx, JSObject* aScope,
                               bool* aTriedToWrap);

  nsISupports* GetParentObject();

  TextTrack* GetTrack() const;

  void GetId(nsAString& aId) const;
  void SetId(const nsAString& aId);

  double StartTime() const;
  void SetStartTime(const double aStartTime);

  double EndTime() const;
  void SetEndTime(const double aEndTime);

  bool PauseOnExit();
  void SetPauseOnExit(const bool aPauseOnExit);

  void GetVertical(nsAString& aVertical);
  void SetVertical(const nsAString& aVertical);

  bool SnapToLines();
  void SetSnapToLines(bool aSnapToLines);

  int32_t Position();
  void SetPosition(int32_t aPosition);

  int32_t Size();
  void SetSize(int32_t aSize);

  void GetAlign(nsAString& aAlign);
  void SetAlign(const nsAString& aAlign);

  void GetText(nsAString& aText);
  void SetText(const nsAString& aText);

  DocumentFragment* GetCueAsHTML();

  IMPL_EVENT_HANDLER(enter)
  IMPL_EVENT_HANDLER(exit)

private:
  void CueChanged()
  {
    if (mTrack) {
// XXXhumph: need this on TextTrack (dale)
//      mTrack->CueChanged(this);
    }
  }

  nsCOMPtr<nsISupports> mGlobal;

  nsRefPtr<TextTrack> mTrack;
  nsString mId;
  nsString mVertical;
  nsString mAlign;
  nsString mText;
  double mStartTime;
  double mEndTime;
  int32_t mPosition;
  int32_t mSize;
  bool mPauseOnExit;
  bool mSnapToLines;
};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_TextTrackCue_h
