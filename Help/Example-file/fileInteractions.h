#include "Includes.h"

class FileInteractions {
public:
  FileInteractions();
  void load(vector<string> &favGames, string &fileName);
  void save(vector<string> &favGames, string &fileName);
};
