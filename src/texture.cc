#include "texture.h"

#include <cstring>

namespace tcr {

Texture::Texture() = default;

Texture::~Texture() = default;

bool Texture::Resize(glm::ivec2 size) {
  if (allocation_.Truncate(size.x * size.y)) {
    size_ = size;
    return true;
  }
  return false;
}

void Texture::Fill(Color color) {
  Color* buffer = allocation_.At();
  for (int i = 0; i < size_.x * size_.y; i++) {
    std::memcpy(buffer + i, &color, sizeof(color));
  }
}

}  // namespace tcr
