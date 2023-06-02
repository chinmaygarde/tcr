#include "texture.h"

#include <cstring>

namespace tcr {

Texture::Texture(glm::ivec2 size) : size_(size) {
  is_valid_ = allocation_.Truncate(size_.x * size_.y);
}

Texture::~Texture() = default;

bool Texture::IsValid() const {
  return is_valid_;
}

bool Texture::Fill(Color color) {
  if (!IsValid()) {
    return false;
  }
  Color* buffer = allocation_.At();
  for (int i = 0; i < size_.x * size_.y; i++) {
    std::memcpy(buffer + i, &color, sizeof(color));
  }
  return true;
}

}  // namespace tcr
