#include <iostream>

#include "iniParser.h"

int main(int argc, char *argv[]) {
  // init deamon thread
  std::string iniFilename = "../conf.ini";
  TL::IniParser *ini = new TL::IniParser(iniFilename);
  // sec = ini.section(sectionName);
  // sec.key(keyname).Int(); sec.key(keyname).String();
  // sec.key(keyname).Double()
  delete ini;
}