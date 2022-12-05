//
// Created by Илья Рожнев on 05.12.2022.
//

#include "PngSave.hpp"
noise::PngSave::PngSave(std::string_view fileName, const imageBuf_t& buf)
  : file_(fileName, std::ios::binary)
  , buf_(buf)
{
  writeHeaderBmp();
  saveData();
}
int noise::PngSave::writeHeaderBmp()
{
  int start = static_cast<int>(file_.tellp());
  int fullSize = 54 + 4 * (buf_.size() * buf_.at(0).size());
  int wSize = buf_.at(0).size();
  int hSize = buf_.size() * -1;

  file_.write("BM", 2);
  file_.write(reinterpret_cast<char*>(&fullSize),         4);
  file_.write(reinterpret_cast<char*>(&bmp_.reserved),    4);
  file_.write(reinterpret_cast<char*>(&bmp_.offsetH),     4);
  file_.write(reinterpret_cast<char*>(&bmp_.sizeH),       4);
  file_.write(reinterpret_cast<char*>(&wSize),            4);
  file_.write(reinterpret_cast<char*>(&hSize),            4);
  file_.write(reinterpret_cast<char*>(&bmp_.plane),       2);
  file_.write(reinterpret_cast<char*>(&bmp_.colors),      2);
  file_.write(reinterpret_cast<char*>(&bmp_.compression), 4);
  file_.write(reinterpret_cast<char*>(&bmp_.rawSize),     4);
  file_.write(reinterpret_cast<char*>(&bmp_.hRes),        4);
  file_.write(reinterpret_cast<char*>(&bmp_.wRes),        4);
  file_.write(reinterpret_cast<char*>(&bmp_.colorEntries),4);
  file_.write(reinterpret_cast<char*>(&bmp_.mainColor),   4);

  return static_cast<int>(file_.tellp()) - start;
}
void noise::PngSave::saveData()
{

  for (const auto& row : buf_) {

    for (auto color : row) {
      file_.write(reinterpret_cast<char*>(&color), 4);
    }
  }
}