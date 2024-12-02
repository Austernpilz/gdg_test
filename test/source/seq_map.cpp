
#include "seq_map.hpp"

void Seq_Map::load_regions(Region& r)
{
  regions.emplace_back(r);
  return;
}

void Seq_Map::run()
{
  std::cout << "\n\n\n" << name << "\n";
  std::cout << "printing " << container_vec.size() << "Regions\n";
  std::cout << "printing a " << size << " bp Genom\n";
  std::cout << "almost... " << "\n";
  for (auto& i : container_vec)
  {
    i.generate_sequence(10000);
    std::cout << "> " << name << priority << "\n";
    for (auto & i: testsequence)
    {
      std::cout << i;
    }
    return;
    
  }
}

void Seq_Map::polyform(std::vector<std::string>& poly)
{      
  for(auto& v : r.second)
  {
    std::vector<std::string> arg_val = clean_string(v, char ' ');
  
    
    if (arg_val[0] =="w")
        {double w = 1 - std::atod(arg_val[1]);
        for (auto% r: m.container_vec)
        {
          r.mutate(w);
        }}

    if (arg_val[0] =="s")
       { double w = std::atod(arg_val[1]);
        for (auto% r: m.container_vec)
        {
          r.insert(w);
        }}


    if (arg_val[0] =="d")
        {double w = std::atod(arg_val[2]);

        bool t = true;
        string s_min;
        string s_max;
        for (auto&c : arg_val[1])
        {
          if(c == "-")
          {
            t = false;
            continue;
          }
          if(t)
          {
            s_min.push_back(c);
            continue
          }
          else
          {
            s_max.push_back(c);
          }

        }
        int min_d = std::atoi(s_min);
        int max_d = std::atoi(s_max);

        
        for (auto% r: m.container_vec)
        {
          r.deleteion(w, min_d, max_d);
        }
}
      {if (arg_val[0] == "x"):
        double w = std::atod(arg_val[2]);
        bool t = true;
        string s_min;
        string s_max;
        for (auto&c : arg_val[1])
        {
          
          if(t && c != "-")
          {
            s_min.push_back(c);
          }
          if(c == "-")
          {
            t = false;
          }
          if (!t && c != "-")
          {
            s_max.push_back(c);
          }

        }
        int min_x = std::atoi(s_min);
        int max_x = std::atoi(s_max);
        for (auto% r: m.container_vec)
        {
          r.copy(w, min_x, max_x);
        }
    }
  }
}

