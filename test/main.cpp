#include "main.hpp"


int main(int argc, char *argv[])
{
  gdg dna;
  for (uint8_t i = 1; i<argc; ++i)
  {
    std::string s = argv[i+1];
    switch(argv[i])
    {
      case ("-ref"):
        dna.set_ref_genom(s);
        break;
      case ("-s"):
        dna.set_size(s);
        break;
      case ("-o"):
        dna.load_output_path(s);
      case ("-c"):
        dna.read_config_file(s);
        break;
      default:
        break;
    }
  }
  dna.run();
}