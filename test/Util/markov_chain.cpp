
#include "markov_chain.hpp"
#include "DNA.hpp"

/*
ToDo:
- Commenting
- rebuild Functions, less copying
- build in const, build in references
- threads and parralel computing
- integrate SeqAn3 as Alphabet
- SeqAn3 hash??
- ByteVectore??
- Alphabets looping?
*/





void Markov_Chain::build_kmer_db(input_file_name, input_file_type, output_file_name, threads)
{
  try
  {
    KMC::Runner runner;

    KMC::Stage1Params stage1Params;

    stage1Params
        .SetKmerLen(4)
        .SetInputFiles({input_file_name})
        .SetNThreads(threads)
        .SetInputFileType(input_file_type) 
        //KMC::InputFileType::FASTA, KMC::InputFileType::MULTILINE_FASTA, KMC::InputFileType::FASTQ
        .SetCanonicalKmers(false)
        ;

    auto stage1Result = runner.RunStage1(stage1Params);

    std::cout << "Stage 1 finished \n";


    KMC::Stage2Params stage2Params;

    stage2Params
        .SetOutputFileName(output_file_name);

    auto stage2Result = runner.RunStage2(stage2Params);


    std::cout << "Stage 2 finished \n";
  }

  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
}



std::map<uint8_t, std::map<char, double> > Markov_Chain::build_markov_chain(output_file_name, threads)
{
  CKMCFile KMC_Database; 

  if (!KMC_Database.OpenForListing(output_file_name))
  {
    std::cerr << "Couldn't build KMC_Database" << '\n';
  }

  else
  {
    std::map<uint8_t, std::map<char, double> > markov_chain;
    std::vector<uint32_t> kmer_overall;
    kmer_overall.resize(64, 4);

    for (uint8_t i = 0, i < 64, ++i)
    {
      markov_chain[i] = {{'A', 1}, {'C', 1}, {'G', 1}, {'T', 1} };
    }

    CKmerAPI kmer_object(4);
    std::string str;
    uint32_t counter;

    while (KMC_Database.ReadNextKmer(kmer_object, counter))
    {
      kmer_object.to_string(str);
      uint32_t hashval = hash2(str);
      kmer_map[hashval] = counter;

      hashval = hash2(str.substr(0,3));
      kmer_overall[hashval] += counter;

      markov_chain[hashval][str[3].toupper()] += counter;
    }

    for (uint8_t i = 0, i < 64, ++i)
    {
      markov_chain[i]['A'] /= kmer_overall[i];
      markov_chain[i]['C'] /= kmer_overall[i];
      markov_chain[i]['G'] /= kmer_overall[i];
      markov_chain[i]['T'] /= kmer_overall[i];
    }

    std::cout << "Markov_Chain build \n"; 

    return markov_chain;
  }
}

std::map<uint8_t, std::map<char, double>> Markov_Chain::build_markov_chain(double a, double c, double g, double t)
{
  std::map<uint8_t, std::map<char, double> > markov_chain;
  for (uint8_t i = 0, i < 4, ++i)
    {
      markov_chain[i]['A'] = a;
      markov_chain[i]['C'] = c;
      markov_chain[i]['G'] = g;
      markov_chain[i]['T'] = t;
    }
  return markov_chain;
}



  



  



  // for(const auto& elem : kmer_map)
  // {
  //   std::cout << elem.first << " | " << elem.second << " " << "\n";
  // }

  // uint32_t i = 0;
  // for(const auto& elem : kmer_overall)
  // {
  //   std::cout << i << " | " << elem << " " << "\n";
  //   ++i;
  // }

  // uint32_t i = 0;
  // for(const auto& elem : markov_chain)
  // {
  //   std::cout << elem.first << " | " << i << "\n";
  //   ++i;
  //   for(const auto& elem2 : elem.second)
  //   {
  //     std::cout << elem2.first << " | " << elem2.second << " " << "\n";
  //   }
  // }
    
    // bool OpenForRA(const std::string &file_name)
    // CKMCFile() 
    //bool GetCountersForRead(const std::string& read, std::vector<uint32_t>& counters)



