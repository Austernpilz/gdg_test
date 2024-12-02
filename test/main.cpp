#include "main.hpp"


int main(int argc, char *argv[])
{
  gdg dna;
  for (uint8_t i = 1; i<argc; ++i)
  {
    
    auto ma = &(argv[i]);
    auto s = &(argv[i+1]);

    std::cout << ma << " " << s;
    if (ma) == "-ref")
    {dna.set_ref_genom(s);}
    if (ma == "-s")
        {dna.set_size(s);}
    if (ma == "-o")
        {dna.load_output_path(s);}
    if (ma == "-c")
       { dna.read_config_file(s);}
  }
  dna.run();
}