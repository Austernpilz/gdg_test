#include "region.hpp"

#include "../Util/DNA.hpp"
#include <fstream>
#include <sstream>


// struct Constrains{};

class Seq_Map
{
  std::string name;
  double size = 0;
  
  std::vector<Region> container_vec;
  // void load(std::string & name, ){};
  void polyform(std::vector<std::string>& poly){};
  void load_regions(Region& r){};
  void run(){};
  
};

