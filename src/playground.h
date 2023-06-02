#pragma once

#include <functional>

#include "fml/macros.h"
#include "gtest/gtest.h"
#include "texture.h"

namespace tcr {

class Playground : public ::testing::Test {
 public:
  Playground();

  ~Playground();

  using PlaygroundCallback = std::function<bool(Texture&)>;
  bool OpenPlaygroundHere(PlaygroundCallback callback);

 private:
  FML_DISALLOW_COPY_AND_ASSIGN(Playground);
};

}  // namespace tcr
