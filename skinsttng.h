/*
 * skinsttng.h: A VDR skin with ST:TNG Panels
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: skinsttng.h 1.1 2004/04/18 09:38:47 kls Exp $
 */

#ifndef __SKINSTTNG_H
#define __SKINSTTNG_H

#include "skins.h"

class cSkinSTTNG : public cSkin {
public:
  cSkinSTTNG(void);
  virtual const char *Description(void);
  virtual cSkinDisplayChannel *DisplayChannel(bool WithInfo);
  virtual cSkinDisplayMenu *DisplayMenu(void);
  virtual cSkinDisplayReplay *DisplayReplay(bool ModeOnly);
  virtual cSkinDisplayVolume *DisplayVolume(void);
  virtual cSkinDisplayMessage *DisplayMessage(void);
  };

#endif //__SKINSTTNG_H
