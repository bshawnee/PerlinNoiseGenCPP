//
// Created by Илья Рожнев on 05.12.2022.
//

#ifndef PERLINNOISE__PNGSAVE_HPP_
#define PERLINNOISE__PNGSAVE_HPP_
#include <vector>
#include <string_view>
#include <fstream>

namespace noise
{

using imageBuf_t = std::vector<std::vector<int>>;

class PngSave
{
   public:
      PngSave(std::string_view fileName, const imageBuf_t& buf);
      ~PngSave() = default;
   private:

    struct bmp
    {
      unsigned  reserved = 0;
      unsigned  offsetH = 54;
      unsigned  sizeH = 40;
      short     plane = 1;
      short     colors = 32;
      unsigned  compression = 0;
      unsigned  rawSize = 0;
      int       hRes = 3780;
      int       wRes = 3780;
      unsigned  colorEntries = 0;
      unsigned  mainColor = 0;
    };

    int   writeHeaderBmp();
    void  saveData();

    bmp               bmp_;
    std::ofstream     file_;
    const imageBuf_t& buf_;
  };
}


#endif //PERLINNOISE__PNGSAVE_HPP_