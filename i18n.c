/*
 * i18n.c: Internationalization
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: i18n.c 1.12 2001/02/13 22:17:27 kls Exp $
 *
 * Slovenian translations provided by Miha Setina <mihasetina@softhome.net>
 * Italian   translations provided by Alberto Carraro <bertocar@tin.it>
 *
 */

/*
 * How to add a new language:
 *
 * 1. Announce your translation action on the Linux-DVB mailing
 *    list to avoid duplicate work.
 * 2. Increase the value of 'NumLanguages'.
 * 3. Insert a new line in every member of the 'Phrases[]' array,
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
 *    and so on. Append your language after the last existing language
 *    and write the name of your language in your language (not in English,
 *    which means that it should be 'Italiano', not 'Italian').
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

const int NumLanguages = 4;

typedef const char *tPhrase[NumLanguages];

const tPhrase Phrases[] = {
  // The name of the language (this MUST be the first phrase!):
  { "English",
    "Deutsch",
    "Slovenski",
    "Italiano",
  },
  // Menu titles:
  { "Main",
    "Hauptmen�",
    "Glavni meni",
    "Principale",
  },
  { "Schedule",
    "Programm",
    "Urnik",
    "Programmi",
  },
  { "Channels",
    "Kan�le",
    "Kanali",
    "Canali",
  },
  { "Timers",
    "Timer",
    "Termini",
    "Timer",
  },
  { "Recordings",
    "Aufzeichnungen",
    "Posnetki",
    "Registrazioni",
  },
  { "Setup",
    "Einstellungen",
    "Nastavitve",
    "Opzioni",
  },
  { "Commands",
    "Befehle",
    "Ukazi",
    "Comandi",
  },
  { "Edit Channel",
    "Kanal Editieren",
    "Uredi kanal",
    "Modifica canale",
  },
  { "Edit Timer",
    "Timer Editieren",
    "Uredi termin",
    "Modifica Timer",
  },
  { "Event",
    "Sendung",
    "Oddaja",
    "Eventi",
  },
  { "Summary",
    "Inhalt",
    "Vsebina",
    "Sommario",
  },
  { "Schedule - %s",
    "Programm - %s",
    "Urnik - %s",
    "Programma - %s",
  },
  { "What's on now?",
    "Was l�uft jetzt?",
    "Kaj je na sporedu?",
    "In programmazione",
  },
  { "What's on next?",
    "Was l�uft als n�chstes?",
    "Kaj sledi?",
    "Prossimi programmi",
  },
  // Button texts (must not be more than 10 characters!):
  { "Edit",
    "Editieren",
    "Uredi",
    "Modifica",
  },
  { "New",
    "Neu",
    "Novo",
    "Nuovo",
  },
  { "Delete",
    "L�schen",
    "Odstrani",
    "Cancella",
  },
  { "Mark",
    "Markieren",
    "Oznaci",
    "Marca",
  },
  { "Record",
    "Aufnehmen",
    "Posnemi",
    "Registra",
  },
  { "Play",
    "Wiedergabe",
    "Predavajaj",
    "Riproduci",
  },
  { "Rewind",
    "Anfang",
    "Zacetek",
    "Da inizio",
  },
  { "Resume",
    "Weiter",
    "Nadaljuj",
    "Riprendi",
  },
  { "Summary",
    "Inhalt",
    "Vsebina",
    "Sommario",
  },
  { "Switch",
    "Umschalten",
    "Preklopi",
    "Cambia",
  },
  { "Now",
    "Jetzt",
    "Sedaj",
    "Adesso",
  },
  { "Next",
    "N�chste",
    "Naslednji",
    "Prossimo",
  },
  { "Schedule",
    "Programm",
    "Urnik",
    "Programma",
  },
  // Confirmations:
  { "Delete channel?",
    "Kanal l�schen?",
    "Odstrani kanal?",
    "Cancello il canale?",
  },
  { "Delete timer?",
    "Timer l�schen?",
    "Odstani termin?",
    "Cancello il timer?",
  },
  { "Delete recording?",
    "Aufzeichnung l�schen?",
    "Odstrani posnetek?",
    "Cancello la registrazione?",
  },
  { "Stop recording?",
    "Aufzeichnung beenden?",
    "Koncaj snemanje?",
    "Fermo la registrazione?",
  },
  { "Cancel editing?",
    "Schneiden abbrechen?",
    "Zelite prekiniti urejanje?",
    "Annullo la modifica?",
  },
  // Channel parameters:
  { "Name",
    "Name",
    "Naziv",
    "Nome",
  },
  { "Frequency",
    "Frequenz",
    "Frekvenca",
    "Frequenza",
  },
  { "Polarization",
    "Polarisation",
    "Polarizacija",
    "Polarizzazione",
  },
  { "Diseqc",
    "Diseqc",
    "Diseqc",
    "Diseqc",
  },
  { "Srate",
    "Srate",
    "Srate",
    "Srate",
  },
  { "Vpid",
    "Vpid",
    "Vpid",
    "Vpid",
  },
  { "Apid",
    "Apid",
    "Apid",
    "Apid",
  },
  { "Tpid",
    "Tpid",
    "Tpid",
    "Tpid",
  },
  { "CA",
    "CA",
    "CA",
    "CA",
  },
  { "Pnr",
    "Pnr",
    "Pnr",
    "Pnr",
  },
  // Timer parameters:
  { "Active",
    "Aktiv",
    "Aktivno",
    "Attivo",
  },
  { "Channel",
    "Kanal",
    "Kanal",
    "Canale",
  },
  { "Day",
    "Tag",
    "Dan",
    "Giorno",
  },
  { "Start",
    "Anfang",
    "Zacetek",
    "Inizio",
  },
  { "Stop",
    "Ende",
    "Konec",
    "Fine",
  },
  { "Priority",
    "Priorit�t",
    "Prioriteta",
    "Priorita",
  },
  { "Lifetime",
    "Lebensdauer",
    "Veljavnost",
    "Durata",
  },
  { "File",
    "Datei",
    "Datoteka",
    "Nome",
  },
  // Error messages:
  { "Channel is being used by a timer!",
    "Kanal wird von einem Timer benutzt!",
    "Urnik zaseda kanal!",
    "Canale occupato da un timer!",
  },
  { "Can't switch channel!",
    "Kanal kann nicht umgeschaltet werden!",
    "Ne morem preklopiti kanala!",
    "Impossibile cambiare canale!",
  },
  { "Timer is recording!",
    "Timer zeichnet gerade auf!",
    "Snemanje po urniku!",
    "Registrazione di un timer in corso!",
  },
  { "Error while deleting recording!",
    "Fehler beim L�schen der Aufzeichnung!",
    "Napaka pri odstranjevanju posnetka!",
    "Errore durante la canc del filmato!",
  },
  { "*** Invalid Channel ***",
    "*** Ung�ltiger Kanal ***",
    "*** Neznan kanal ***",
    "*** CANALE INVALIDO ***",
  },
  { "No free DVB device to record!",
    "Keine freie DVB-Karte zum Aufnehmen!",
    "Ni proste DVB naprave za snemanje!",
    "Nessuna card DVB disp per registrare!",
  },
  { "Channel locked (recording)!",
    "Kanal blockiert (zeichnet auf)!",
    "Zaklenjen kanal (snemanje)!",
    "Canale bloccato (in registrazione)!",
  },
  { "Can't start editing process!",
    "Schnitt kann nicht gestartet werden!",
    "Ne morem zaceti urejanja!",
    "Imposs iniziare processo di modifica",
  },
  { "Editing process already active!",
    "Schnitt bereits aktiv!",
    "Urejanje je ze aktivno!",
    "Processo di modifica gia` attivo",
  },
  // Setup parameters:
  { "OSD-Language",
    "OSD-Sprache",
    "OSD-jezik",
    "Linguaggio OSD",
  },
  { "PrimaryDVB",
    "Prim�res Interface",
    "Primarna naprava",
    "Scheda DVB primaria",
  },
  { "ShowInfoOnChSwitch",
    "Info zeigen",
    "Pokazi naziv kanala",
    "Vis info nel cambio canale",
  },
  { "MenuScrollPage",
    "Seitenweise scrollen",
    "Drsni meni",
    "Scrolla pagina nel menu",
  },
  { "MarkInstantRecord",
    "Direktaufz. markieren",
    "Oznaci direktno snemanje",
    "Marca la registrazione",
  },
  { "LnbFrequLo",
    "Untere LNB-Frequenz",
    "Spodnja LNB-frek.",
    "Freq LO LNB",
  },
  { "LnbFrequHi",
    "Obere LNB-Frequenz",
    "Zgornja LNB-frek.",
    "Freq HI LNB",
  },
  { "SetSystemTime",
    "Systemzeit stellen",
    "Sistemski cas",
    "Setta orario auto",
  },
  { "MarginStart",
    "Zeitpuffer bei Anfang",
    "Premor pred zacetkom",
    "Min margine inizio",
  },
  { "MarginStop",
    "Zeitpuffer bei Ende",
    "Premor za koncem",
    "Min margine fine",
  },
  { "EPGScanTimeout",
    "Zeit bis EPG Scan",
    "Cas do EPG pregleda",
    "Timeout EPG",
  },
  // The days of the week:
  { "MTWTFSS",
    "MDMDFSS",
    "PTSCPSN",
    "DLMMGVS",
  },
  // Learning keys:
  { "Learning Remote Control Keys",
    "Fernbedienungs-Codes lernen",
    "Ucim se kod upravljalca",
    "Apprendimento tasti unita` remota",
  },
  { "Phase 1: Detecting RC code type",
    "Phase 1: FB Code feststellen",
    "Faza 1: Sprejemanje IR kode",
    "Fase 1: tipo ricevitore RC",
  },
  { "Press any key on the RC unit",
    "Eine Taste auf der FB dr�cken",
    "Pritisnite tipko na upravljalcu",
    "Premere un tasto nell'unita` RC",
  },
  { "RC code detected!",
    "FB Code erkannt!",
    "IR koda sprejeta!",
    "Codice RC rilevato!",
  },
  { "Do not press any key...",
    "Keine Taste dr�cken...",
    "Ne pritiskajte tipk...",
    "Non premere alcun tasto...",
  },
  { "Phase 2: Learning specific key codes",
    "Phase 2: Einzelne Tastencodes lernen",
    "Faza 2: Ucenje posebnih kod",
    "Fase 2: Codici specifici dei tasti",
  },
  { "Press key for '%s'",
    "Taste f�r '%s' dr�cken",
    "Pritisnite tipko za '%s'",
    "Premere il tasto per '%s'",
  },
  { "Press 'Up' to confirm",
    "'Auf' dr�cken zum Best�tigen",
    "Pritisnite tipko 'Gor' za potrditev",
    "Premere 'Su' per confermare",
  },
  { "Press 'Down' to continue",
    "'Ab' dr�cken zum Weitermachen",
    "Pritisnite tipko 'Dol' za nadaljevanje",
    "Premere 'Giu' per confermare",
  },
  { "(press 'Up' to go back)",
    "('Auf' dr�cken um zur�ckzugehen)",
    "(pritisnite 'Gor' za nazaj)",
    "(premere 'Su' per tornare indietro)",
  },
  { "(press 'Down' to end key definition)",
    "('Ab' dr�cken zum Beenden",
    "(pritisnite 'Dol' za konec)",
    "('Giu' per finire la definiz tasti)",
  },
  { "Phase 3: Saving key codes",
    "Phase 3: Codes abspeichern",
    "Faza 3: Shranjujem kodo",
    "Fase 3: Salvataggio key codes",
  },
  { "Press 'Up' to save, 'Down' to cancel",
    "'Auf' speichert, 'Ab' bricht ab",
    "'Gor' za potrditev, 'Dol' za prekinitev",
    "'Su' per salvare, 'Giu' per annullare",
  },
  // Key names:
  { "Up",
    "Auf",
    "Gor",
    "Su",
  },
  { "Down",
    "Ab",
    "Dol",
    "Giu",
  },
  { "Menu",
    "Men�",
    "Meni",
    "Menu",
  },
  { "Ok",
    "Ok",
    "Ok",
    "Ok",
  },
  { "Back",
    "Zur�ck",
    "Nazaj",
    "Indietro",
  },
  { "Left",
    "Links",
    "Levo",
    "Sinistra",
  },
  { "Right",
    "Rechts",
    "Desno",
    "Destra",
  },
  { "Red",
    "Rot",
    "Rdeca",
    "Rosso",
  },
  { "Green",
    "Gr�n",
    "Zelena",
    "Verde",
  },
  { "Yellow",
    "Gelb",
    "Rumena",
    "Giallo",
  },
  { "Blue",
    "Blau",
    "Modra",
    "Blu",
  },
  // Miscellaneous:
  { "yes",
    "ja",
    "da",
    "si",
  },
  { "no",
    "nein",
    "ne",
    "no",
  },
  { "Stop replaying",
    "Wiedergabe beenden",
    "Prekini ponavljanje",
    "Interrompi riproduzione",
  },
  { "Stop recording ", // note the trailing blank!
    "Aufzeichnung beenden ",
    "Prekini shranjevanje ",
    "Interrompi registrazione ",
  },
  { "Cancel editing",
    "Schneiden abbrechen",
    "Prekini urejanje",
    "Annulla modifiche",
  },
  { "Switching primary DVB...",
    "Prim�res Interface wird umgeschaltet...",
    "Preklapljanje primarne naprave...",
    "Cambio su card DVB primaria...",
  },
  { "Up/Dn for new location - OK to move",
    "Auf/Ab f�r neue Position - dann OK",
    "Gor/Dol za novo poz. - Ok za premik",
    "Su/Giu per nuova posizione - OK per muovere",
  },
  { "Editing process started",
    "Schnitt gestartet",
    "Urejanje se je zacelo",
    "Processo di modifica iniziato",
  },
  { NULL }
  };

const char *tr(const char *s)
{
  if (Setup.OSDLanguage) {
     for (const tPhrase *p = Phrases; **p; p++) {
         if (strcmp(s, **p) == 0) {
            const char *t = (*p)[Setup.OSDLanguage];
            if (t && *t)
               return t;
            }
         }
     esyslog(LOG_ERR, "no translation found for '%s' in language %d (%s)\n", s, Setup.OSDLanguage, Phrases[0][Setup.OSDLanguage]);
     }
  return s;
}

const char * const * Languages(void)
{
  return &Phrases[0][0];
}

