/*
 * i18n.c: Internationalization
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: i18n.c 1.2 2000/11/11 16:20:47 kls Exp $
 */

/*
 * How to add a new language:
 *
 * 1. Announce your translation action on the Linux-DVB mailing
 *    list to avoid duplicate work.
 * 2. Increase the value of 'NumLanguages'.
 * 3. Add a new line to every member of the 'Phrases[]' array,
 *    containing the translated text for the new language.
 *    For example, assuming you want to add the Italian language,
 *
 *       { "English",
 *         "Deutsch",
 *       },
 *
 *    would become
 *
 *       { "English",
 *         "Deutsch",
 *         "Italiano",
 *       },
 *
 *    and so on.
 *    Note that only the characters defined in 'fontosd.c' will
 *    be available!
 * 4. Compile VDR and test the new language by switching to it
 *    in the "Setup" menu.
 * 5. Send the modified 'i18n.c' file to <kls@cadsoft.de> to have
 *    it included in the next version of VDR.
 */

#include "i18n.h"
#include <stdio.h>
#include "config.h"
#include "tools.h"

const int NumLanguages = 2;

typedef const char *tPhrase[NumLanguages];

const tPhrase Phrases[] = {
  // The name of the language (this MUST be the first phrase!):
  { "English",
    "Deutsch",
  },
  // Menu titles:
  { "Main",
    "Hauptmen�",
  },
  { "Schedule",
    "Programm",
  },
  { "Channels",
    "Kan�le",
  },
  { "Timers",
    "Timer",
  },
  { "Recordings",
    "Aufzeichnungen",
  },
  { "Setup",
    "Einstellungen",
  },
  { "Commands",
    "Befehle",
  },
  { "Edit Channel",
    "Kanal Editieren",
  },
  { "Edit Timer",
    "Timer Editieren",
  },
  { "Event",
    "Sendung",
  },
  { "Summary",
    "Inhalt",
  },
  { "Schedule - %s",
    "Programm - %s",
  },
  { "What's on now?",
    "Was l�uft jetzt?",
  },
  { "What's on next?",
    "Was l�uft als n�chstes?",
  },
  // Button texts (must not be more than 10 characters!):
  { "Edit",
    "Editieren",
  },
  { "New",
    "Neu",
  },
  { "Delete",
    "L�schen",
  },
  { "Mark",
    "Markieren",
  },
  { "Record",
    "Aufnehmen",
  },
  { "Play",
    "Wiedergabe",
  },
  { "Resume",
    "Weiter",
  },
  { "Summary",
    "Inhalt",
  },
  { "Switch",
    "Umschalten",
  },
  { "Now",
    "Jetzt",
  },
  { "Next",
    "N�chste",
  },
  { "Schedule",
    "Programm",
  },
  // Confirmations:
  { "Delete Channel?",
    "Kanal l�schen?",
  },
  { "Delete Timer?",
    "Timer l�schen?",
  },
  { "Delete Recording?",
    "Aufzeichnung l�schen?",
  },
  { "Stop Recording?",
    "Aufzeichnung beenden?",
  },
  // Channel parameters:
  { "Name",
    "Name",
  },
  { "Frequency",
    "Frequenz",
  },
  { "Polarization",
    "Polarisation",
  },
  { "Diseqc",
    "Diseqc",
  },
  { "Srate",
    "Srate",
  },
  { "Vpid",
    "Vpid",
  },
  { "Apid",
    "Apid",
  },
  { "CA",
    "CA",
  },
  { "Pnr",
    "Pnr",
  },
  // Timer parameters:
  { "Active",
    "Aktiv",
  },
  { "Channel",
    "Kanal",
  },
  { "Day",
    "Tag",
  },
  { "Start",
    "Anfang",
  },
  { "Stop",
    "Ende",
  },
  { "Priority",
    "Priorit�t",
  },
  { "Lifetime",
    "Lebensdauer",
  },
  { "File",
    "Datei",
  },
  // Error messages:
  { "Channel is being used by a timer!",
    "Kanal wird von einem Timer benutzt",
  },
  { "Can't switch channel!",
    "Kanal kann nicht umgeschaltet werden!",
  },
  { "Timer is recording!",
    "Timer zeichnet gerade auf!",
  },
  { "Error while deleting recording!",
    "Fehler beim L�schen der Aufzeichnung!",
  },
  { "*** Invalid Channel ***",
    "*** Ung�ltiger Kanal ***",
  },
  { "No free DVB device to record!",
    "Keine freie DVB-Karte zum Aufnehmen!",
  },
  { "Channel locked (recording)!",
    "Kanal blockiert (zeichnet auf)!",
  },
  // Setup parameters:
  { "OSD-Language",
    "OSD-Sprache",
  },
  { "PrimaryDVB",
    "Prim�res Interface",
  },
  { "ShowInfoOnChSwitch",
    "Info zeigen",
  },
  { "MenuScrollPage",
    "Seitenweise scrollen",
  },
  { "MarkInstantRecord",
    "Direktaufz. markieren",
  },
  { "LnbFrequLo",
    "Untere LNB-Frequenz",
  },
  { "LnbFrequHi",
    "Obere LNB-Frequenz",
  },
  { "SetSystemTime",
    "Systemzeit stellen",
  },
  { "MarginStart",
    "Zeitpuffer bei Anfang",
  },
  { "MarginStop",
    "Zeitpuffer bei Ende",
  },
  // The days of the week:
  { "MTWTFSS",
    "MDMDFSS",
  },
  // Learning keys:
  { "Learning Remote Control Keys",
    "Fernbedienungs-Codes lernen",
  },
  { "Phase 1: Detecting RC code type",
    "Phase 1: FB Code feststellen",
  },
  { "Press any key on the RC unit",
    "Eine Taste auf der FB dr�cken",
  },
  { "RC code detected!",
    "FB Code erkannt!",
  },
  { "Do not press any key...",
    "Keine Taste dr�cken...",
  },
  { "Phase 2: Learning specific key codes",
    "Phase 2: Einzelne Tastencodes lernen",
  },
  { "Press key for '%s'",
    "Taste f�r '%s' dr�cken",
  },
  { "Press 'Up' to confirm",
    "'Auf' dr�cken zum Best�tigen",
  },
  { "Press 'Down' to continue",
    "'Ab' dr�cken zum Weitermachen",
  },
  { "(press 'Up' to go back)",
    "('Auf' dr�cken um zur�ckzugehen)",
  },
  { "(press 'Down' to end key definition)",
    "('Ab' dr�cken zum Beenden",
  },
  { "Phase 3: Saving key codes",
    "Phase 3: Codes abspeichern",
  },
  { "Press 'Up' to save, 'Down' to cancel",
    "'Auf' speichert, 'Ab' bricht ab",
  },
  // Key names:
  { "Up",
    "Auf",
  },
  { "Down",
    "Ab",
  },
  { "Menu",
    "Men�",
  },
  { "Ok",
    "Ok",
  },
  { "Back",
    "Zur�ck",
  },
  { "Left",
    "Links",
  },
  { "Right",
    "Rechts",
  },
  { "Red",
    "Rot",
  },
  { "Green",
    "Gr�n",
  },
  { "Yellow",
    "Gelb",
  },
  { "Blue",
    "Blau",
  },
  // Miscellaneous:
  { "yes",
    "ja",
  },
  { "no",
    "nein",
  },
  { "Stop replaying",
    "Wiedergabe beenden",
  },
  { "Stop recording ", // note the trailing blank!
    "Aufzeichnung beenden ",
  },
  { "Switching primary DVB...",
    "Prim�res Interface wird umgeschaltet...",
  },
  { "Up/Dn for new location - OK to move",
    "Auf/Ab f�r neue Position, dann OK",
  },
  { NULL }
  };

const char *tr(const char *s)
{
  if (Setup.OSDLanguage) {
     for (const tPhrase *p = Phrases; **p; p++) {
         if (strcmp(s, **p) == 0)
            return (*p)[Setup.OSDLanguage];
         }
     esyslog(LOG_ERR, "no translation found for '%s' in language %d (%s)\n", s, Setup.OSDLanguage, Phrases[0][Setup.OSDLanguage]);
     }
  return s;
}

const char * const * Languages(void)
{
  return &Phrases[0][0];
}

