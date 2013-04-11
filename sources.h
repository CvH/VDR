/*
 * sources.h: Source handling
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: sources.h 3.1 2013/04/11 10:23:16 kls Exp $
 */

#ifndef __SOURCES_H
#define __SOURCES_H

#include "config.h"

class cSource : public cListObject {
public:
  enum eSourceType {
    stNone  = 0x00000000,
    stAtsc  = ('A' << 24),
    stCable = ('C' << 24),
    stSat   = ('S' << 24),
    stTerr  = ('T' << 24),
    st_Mask = 0xFF000000,
    st_Pos  = 0x0000FFFF,
    };
private:
  int code;
  char *description;
public:
  cSource(void);
  cSource(char Source, const char *Description);
  ~cSource();
  int Code(void) const { return code; }
  int Position(void) { return Position(code); }
      ///< Returns the orbital position of the satellite in case this is a DVB-S
      ///< source (zero otherwise). The returned value is in the range -1800...+1800.
      ///< A positive sign indicates a position east of Greenwich, while western
      ///< positions have a negative sign. The absolute value is in "degrees * 10",
      ///< which allows for a resolution of 1/10 of a degree.
  const char *Description(void) const { return description; }
  bool Parse(const char *s);
  static int Position(int Code);
  static char ToChar(int Code) { return (Code & st_Mask) >> 24; }
  static cString ToString(int Code);
  static int FromString(const char *s);
  static int FromData(eSourceType SourceType, int Position = 0, bool East = false);
  static bool IsAtsc(int Code) { return (Code & st_Mask) == stAtsc; }
  static bool IsCable(int Code) { return (Code & st_Mask) == stCable; }
  static bool IsSat(int Code) { return (Code & st_Mask) == stSat; }
  static bool IsTerr(int Code) { return (Code & st_Mask) == stTerr; }
  static bool IsType(int Code, char Source) { return int(Code & st_Mask) == (int(Source) << 24); }
  };

class cSources : public cConfig<cSource> {
public:
  cSource *Get(int Code);
  };

extern cSources Sources;

#endif //__SOURCES_H
