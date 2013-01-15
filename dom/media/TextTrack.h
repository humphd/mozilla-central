/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 et tw=78: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_dom_TextTrack_h
#define mozilla_dom_TextTrack_h

#include "nsCycleCollectionParticipant.h"
#include "nsTraceRefcnt.h"

namespace mozilla {
namespace dom {

class TextTrack MOZ_FINAL : public nsISupports
{
public:
  TextTrack()
  {
    MOZ_COUNT_CTOR(TextTrack);
  }

  ~TextTrack()
  {
    MOZ_COUNT_DTOR(TextTrack);
  }

  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_CYCLE_COLLECTION_SCRIPT_HOLDER_CLASS(TextTrack)

// XXXhumph: do rest of decl for this...

};

} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_TextTrack_h
