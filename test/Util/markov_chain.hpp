
#pragmaonce
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../include/kmc/include/kmc_runner.h"
#include "../include/kmc/kmc_api/kmc_file.h"
// #include "seqan3/include/alphabet/nucleotide/dna4.hpp"


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
    void build_kmer_db(input_file_name, input_file_type, output_file_name, threads);
    std::map<uint8_t, std::map<char, double> > build_markov_chain(output_file_name, threads);
    std::map<uint8_t, std::map<char, double> > build_markov_chain(double a, double c, double g, double t);


};