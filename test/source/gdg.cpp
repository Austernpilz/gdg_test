
#include "gdg.hpp"



void gdg::set_ref_genom(std::string & s)
{
  ref_genom = s;
}

void gdg::set_size(std::string & s)
{
  gdg_size = std::stod(s);
}

void gdg::read_config_file(std::string & s)
{
  simple = "false";
  config_file = s;
}

void gdg::load_output_path(std::string & s)
{
  outout_path = s;
}

// vo

void gdg::run()
{
  if (simple)
  {
    Region r;
    r.name = "Simpler Test";
    r.load_MarkovChain(ref_genom);
    r.r_size = gdg_size;
    r.generate_sequence(gdg_size, 3);
    std::cout << "> " << r.name << r.priority << "\n";
    for (auto & i: testsequence)
    {
      std::cout << i;
    }
    std::cout << "Finished \n";
    return;
  }
  else
  {
    std::ifstream fin(config_file);
    std::string line;

    Rules r;

    while (std::getline(fin, line))
    {
      if (line[0] == '#')
      {
        continue;
      }
      r.load_rule(line);
    }

    Seq_Map m;

    r.build_regions(m);


    
    
    for (auto& region : m.container_vec)
    {
      std::cout << "> " << region.name << region.priority << "\n";
      for (auto & i: region.testsequence)
      {
        std::cout << i;
      }
    }
    std::cout << "Finished with .dna \n";
    

    for (auto& poly : r.p_LookUp)
    {
      m.name = poly.first;
      m.polyform(poly.second);

      for (auto& region : m.container_vec)
      {
        std::cout << "> " << region.name << region.priority << "\n";
        for (auto & i: region.testsequence)
        {
          std::cout << i;
        }
      }
      std::cout << "Finished with .poly " << m.name << "\n";
    }

  }

}
