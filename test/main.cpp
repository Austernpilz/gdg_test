#include "main.hpp"


int main(int argc, char *argv[])
{
  gdg dna;
  for (uint8_t i = 1; i<argc; ++i)
  {
    switch(argv[i])
    {
      case ("-ref"):
        dna.set_ref_genom(argv[++i]);
        break;
      case ("-s"):
        dna.set_size(argv[++i]);
        break;
      case ("-o"):
        dna.load_output_path(argv[++i]);
      case ("-c"):
        dna.read_config_file(argv[++i]);
        break;
      default:
        break;
    }
  }
  dna.run();
}