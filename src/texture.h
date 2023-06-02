#pragma once

#include <glm/glm.hpp>

#include "allocation.h"
#include "color.h"
#include "fml/macros.h"

namespace tcr {

class Texture {
 public:
  Texture();

  ~Texture();

  [[nodiscard]] bool Resize(glm::ivec2 size);

  void Fill(Color color);

  Color* At(size_t x, size_t y) const {
    return allocation_.At((y * size_.x) + x);
  }

 private:
  glm::ivec2 size_ = {};
  Allocation<Color> allocation_;

  FML_DISALLOW_COPY_AND_ASSIGN(Texture);
};

}  // namespace tcr
