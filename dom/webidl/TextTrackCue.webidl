/* -*- Mode: IDL; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The origin of this IDL file is
 * http://www.whatwg.org/specs/web-apps/current-work/#texttrackcue
 */

enum AutoKeyword { "auto" };

[Constructor(double startTime, double endTime, DOMString text)]
interface TextTrackCue : EventTarget {
  readonly attribute TextTrack? track;

           attribute DOMString id;
           attribute double startTime;
           attribute double endTime;
           attribute boolean pauseOnExit;
           attribute DOMString vertical;
           attribute boolean snapToLines;
// XXXhumph: https://www.w3.org/Bugs/Public/show_bug.cgi?id=20651
//           attribute (long or AutoKeyword) line;
           attribute long position;
           attribute long size;
           attribute DOMString align;
           attribute DOMString text;
  DocumentFragment getCueAsHTML();

           attribute EventHandler onenter;
           attribute EventHandler onexit;
};
