#include "Includes.h"

class FileInteractions {
public:
  // Custom hash can be a standalone function object.

  FileInteractions();
  void load(vector<string> &favGames, string fileName);
  void save(vector<string> &favGames, string fileName);
  void encriptedLoad(vector<string> &favGames, string fileName,
                     const vector<int> &primes, const int &pass);
  void encriptedSave(vector<string> &favGames, string fileName,
                     const vector<int> &primes, const int &pass);
};
