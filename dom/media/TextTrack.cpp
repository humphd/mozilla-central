/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 et tw=78: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "mozilla/dom/TextTrack.h"

//#include "nsDOMClassInfoID.h"
//#include "nsContentUtils.h"
#include "mozilla/dom/TextTrackBinding.h"

namespace mozilla {
namespace dom {

NS_IMPL_CYCLE_COLLECTING_ADDREF(TextTrack)
NS_IMPL_CYCLE_COLLECTING_RELEASE(TextTrack)

NS_INTERFACE_MAP_BEGIN_CYCLE_COLLECTION(TextTrack)
  NS_INTERFACE_MAP_ENTRY(nsISupports)
NS_INTERFACE_MAP_END

NS_IMPL_CYCLE_COLLECTION_CLASS(TextTrack)

NS_IMPL_CYCLE_COLLECTION_TRAVERSE_BEGIN(TextTrack)
  NS_IMPL_CYCLE_COLLECTION_TRAVERSE_SCRIPT_OBJECTS
NS_IMPL_CYCLE_COLLECTION_TRAVERSE_END

} // namespace dom
} // namespace mozilla
