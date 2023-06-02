#pragma once

#include <functional>

#include "fml/macros.h"
#include "gtest/gtest.h"

namespace tcr {

class Playground : public ::testing::Test {
 public:
  Playground();

  ~Playground();

  bool OpenPlaygroundHere(std::function<bool()> callback);

 private:
  FML_DISALLOW_COPY_AND_ASSIGN(Playground);
};

}  // namespace tcr
