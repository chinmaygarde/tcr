#include "fixtures_location.h"
#include "gtest/gtest.h"
#include "playground.h"

namespace tcr {

using TCRTest = Playground;

TEST_F(TCRTest, CanOpenPlayground) {
  OpenPlaygroundHere([]() { return true; });
}

}  // namespace tcr
