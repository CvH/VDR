/*
 * plugin.h: The VDR plugin interface
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: plugin.h 1.7 2004/04/30 13:46:21 kls Exp $
 */

#ifndef __PLUGIN_H
#define __PLUGIN_H

#include "i18n.h"
#include "menuitems.h"
#include "osdbase.h"
#include "tools.h"

#define VDRPLUGINCREATOR(PluginClass) extern "C" void *VDRPluginCreator(void) { return new PluginClass; }

class cPlugin {
  friend class cDll;
private:
  static char *configDirectory;
  const char *name;
  void SetName(const char *s);
public:
  cPlugin(void);
  virtual ~cPlugin();

  const char *Name(void) { return name; }
  virtual const char *Version(void) = 0;
  virtual const char *Description(void) = 0;
  virtual const char *CommandLineHelp(void);

  virtual bool ProcessArgs(int argc, char *argv[]);
  virtual bool Initialize(void);
  virtual bool Start(void);
  virtual void Housekeeping(void);

  virtual const char *MainMenuEntry(void);
  virtual cOsdObject *MainMenuAction(void);

  virtual cMenuSetupPage *SetupMenu(void);
  virtual bool SetupParse(const char *Name, const char *Value);
  void SetupStore(const char *Name, const char *Value = NULL);
  void SetupStore(const char *Name, int Value);

  void RegisterI18n(const tI18nPhrase * const Phrases);

  static void SetConfigDirectory(const char *Dir);
  static const char *ConfigDirectory(const char *PluginName = NULL);
  };

class cDll : public cListObject {
private:
  char *fileName;
  char *args;
  void *handle;
  cPlugin *plugin;
public:
  cDll(const char *FileName, const char *Args);
  virtual ~cDll();
  bool Load(bool Log = false);
  cPlugin *Plugin(void) { return plugin; }
  };

class cDlls : public cList<cDll> {};

class cPluginManager {
private:
  static cPluginManager *pluginManager;
  char *directory;
  time_t lastHousekeeping;
  int nextHousekeeping;
  cDlls dlls;
public:
  cPluginManager(const char *Directory);
  virtual ~cPluginManager();
  void SetDirectory(const char *Directory);
  void AddPlugin(const char *Args);
  bool LoadPlugins(bool Log = false);
  bool InitializePlugins(void);
  bool StartPlugins(void);
  void Housekeeping(void);
  static bool HasPlugins(void);
  static cPlugin *GetPlugin(int Index);
  static cPlugin *GetPlugin(const char *Name);
  void Shutdown(bool Log = false);
  };

#endif //__PLUGIN_H
