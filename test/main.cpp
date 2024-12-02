#include "main.hpp"





int main(int argc, char *argv[])
{
  gdg dna;
  for (uint8_t i = 1; i<argc; ++i)
  {
    swicht(argv[i])
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
  return;
}

// Markov_Chain_3 testchain;

  // std::string input_file_name = "/group/ag_abi/manuel/testdata/GCF_917046035.1_P2_DC1_genomic.fna";
  // KMC::InputFileType input_file_type = KMC::InputFileType::MULTILINE_FASTA;
  // std::string output_file_name = "4mers";
  // int threads = 16;

  // testchain.build_kmer_db(input_file_name, input_file_type, output_file_name, threads);

  // std::map<uint8_t, std::map<char, double> > markovchain;
  // markovchain = testchain.build_markov_chain(output_file_name, threads);


  // std::vector<char> testsequence = {'A', 'C', 'G', 'T'};
  // int length = 10000;


  // // std::cout << "Testsequence before " << '\n';
  // // for (auto& elem : testsequence)
  // // {
  // //     std::cout << elem;
  // // }

  // generate_sequence(markovchain, testsequence, length);

  // // std::cout << "Testsequence after " << '\n';
  // // for (auto& elem : testsequence)
  // // {
  // //     std::cout << elem;
  // // }

  // // std::cout << '\n' <<"Complete" << '\n';


  // std::string input_SNP_file = "/group/ag_abi/manuel/testdata/gruppe6chr1.vcf";

  // std::vector<SNP> testsnp = read_SNPs(input_SNP_file);

  // // for (auto& elem : testsnp)
  // // {
  // //     std::cout << elem.chr << '\t' << elem.pos << '\t' << elem.ref << '\t' << elem.alt << '\n';
  // // }

  // std::cout << '\n' <<"Complete2" << '\n';

  // // std::vector<std::vector<char>> test_kmer_subset; = 
  // // {
  // //   {'C', 'C', 'A', 'G', 'C', 'G', 'G', 'A', 'G', 'T', 'A', 'A', 'T'},
  // //   {'T', 'G', 'G', 'T'},
  // //   {'A', 'A', 'C', 'T', 'A', 'G', 'C'},
  // //   {'C', 'A', 'G', 'A'},
  // //   {'T', 'C', 'G', 'A', 'C', 'G', 'T', 'C', 'G', 'T'},
  // //   {'A', 'T', 'C', 'T'},
  // //   {'T', 'A', 'G', 'T', 'T', 'G', 'T', 'A', 'G', 'T', 'A', 'G', 'T', 'A', 'G', 'T'},
  // //   {'T', 'C', 'G', 'T', 'A', 'C', 'C', 'C', 'A', 'T'},
  // //   {'A', 'A', 'C', 'G', 'C', 'C', 'T', 'G', 'G', 'A', 'C', 'G', 'T'},
  // //   {'A', 'C', 'A', 'T', 'C', 'C', 'T'}
  // // };




  // // class Tile
  // // {
  // //   std::string name;
  // //   size_t size;
  // //   // border;
  // //   std::vector<std::vector<char>>kmer_subset;
  // //   std::string path_reference_sequence;
  // //   std::map<uint8_t, std::map<char, double> > markovchain;
  // //   // Polymorphisms SNPs, INDELs, CNVs;

    
  // }
  // std::map<char, std::map<char, double> > testmarkovchain
  // {
  //     {'A', {{'A', 0.1},{'C', 0.4}, {'G', 0.2}, {'T', 0.3} } },
  //     {'C', {{'A', 0.3},{'C', 0.2}, {'G', 0.3}, {'T', 0.2} } },
  //     {'G', {{'A', 0.7},{'C', 0.1}, {'G', 0.1}, {'T', 0.1} } },
  //     {'T', {{'A', 0.1},{'C', 0.2}, {'G', 0.6}, {'T', 0.1} } }
  // };






  



  
  // for (auto& elem : testsequence)
  // {
  //     std::cout << elem;
  // }


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
  // }

//https://stackoverflow.com/questions/167735/fast-pseudo-random-number-generator-for-procedural-content
// fast random number gen???
// v = 36969*(v & 65535) + (v >> 16);
// u = 18000*(u & 65535) + (u >> 16);
// return (v << 16) + (u & 65535);