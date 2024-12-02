
#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../../../kmc/kmc/include/kmc_runner.h"
#include "../../../kmc/kmc/kmc_api/kmc_file.h"
// #include "seqan3/include/alphabet/nucleotide/dna4.hpp"
#include "DNA.hpp"

class Markov_Chain
{
  private:
    const std::map<char, uint32_t> translate = 
    {
      {'a', 0}, {'A', 0}, {'c', 1}, {'C', 1}, {'g', 2}, {'G', 2}, {'t', 3}, {'T', 3} 
    };
    
    std::map<uint16_t, std::string> kmer_map;

    uint32_t hash2(const std::string& kmer);

  public:
    void build_kmer_db(std::string & input_file_name, KMC::InputFileType &  input_file_type, std::string & output_file_name, int threads);
    std::map<uint8_t, std::map<char, double> > build_markov_chain(std::string & output_file_name, int threads);
    std::map<uint8_t, std::map<char, double> > build_markov_chain(double a, double c, double g, double t);


};