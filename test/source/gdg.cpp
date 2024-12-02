
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
//   std::vector<std::string> line_vec;
//   std::istringstream iss(line);
//   std::string field;

//   while(std::getline(iss, field, '\t'))
//       line_vec.push_back(field);

//   if (line_vec[0] == ".dna")
//   {
//     Map container;
//     container.name = line_vec[1];

//     std::stringstream sstream(line_vec[2]);
//     sstream >> container.size;

//     container.instructions = line_vec[3];

//     map_vec.push_back(container);

//   }
//   if (line_vec[0] == ".poly")
//   {
//     Region haploid;
//     haploid.name = line_vec[1];
//     haploid.instructions = line_vec[2];

//     region_vec.push_back(haploid);
//   }
//   if (line_vec[0] == ".sample")
//   {
//     Sequence_Builder sample;
//     sample.name = line_vec[1];
//     sample.instructions = line_vec[2];

//     seq_vec.push_back(sample);
//     }


//   for (auto& elem : map_vec)
//   {
//     elem.load_values();
//     elem.run();
//   }

//   for (auto& elem : region_vec)
//   {

//   }
// }
//     read_rules(std::string path)
//     Rules r;
//     r.laod
//   }
//   Seq_Map m;
  
//   r.
//   while()
//   {

//   }
  

// };
// id gdg::read_rules(std::string path)



      // for (auto& elem : seq_vec)
      // {

      // }

      // for (auto& elem : testsequence)
      // {
      //   std::cout << line_vec[0] << '\t' << line_vec[1] << '\t' << line_vec[3] << '\t' << line_vec[4] << '\n';
      // }

      

      // std::stringstream sstream1(line_vec[1]);
      // sstream1 >> BED_field.chromStart;
      // std::stringstream sstream2(line_vec[2]);
      // sstream2 >> BED_field.chromEnd;
      
      // BED_field.score = stod(line_vec[5]);
      // BED_field.strand = line_vec[4][0];

      // BED_table.push_back(BED_field);
  //   }
    
  //   fin.close();

  //   return ;
  // }



// int main()
// {
//   // if else Höllle
//   //read Document,
//   //build sequence

//   //funktions, copy, insert, delete



// }