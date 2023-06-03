#include "allocation.h"
#include "color.h"
#include "fixtures_location.h"
#include "gtest/gtest.h"
#include "playground.h"
#include "texture.h"

namespace tcr {

using TCRTest = Playground;

TEST_F(TCRTest, CanOpenPlayground) {
  OpenPlaygroundHere([](Texture& texture) {
    texture.Fill(kColorSlateGray);
    return true;
  });
}

TEST_F(TCRTest, CanCreateColors) {
  auto color = kColorRed;
  color.red = 255;
  ASSERT_EQ(color.red, 255);
  ASSERT_EQ(color.green, 0);
  ASSERT_EQ(color.blue, 0);
  ASSERT_EQ(color.alpha, 255);
  ASSERT_EQ(color.value, 0b1111'1111'1111'1111'0000'0000'0000'0000);
}

TEST_F(TCRTest, CanCreateAllocations) {
  Allocation<Color> allocation;
  ASSERT_TRUE(allocation.Truncate(4));
  ASSERT_EQ(allocation.GetCount(), 4u);
  ASSERT_EQ(allocation.GetByteSize(), 16u);
  *allocation.At(0) = kColorRed;
  *allocation.At(1) = kColorGreen;
  *allocation.At(2) = kColorBlue;
  *allocation.At(3) = kColorPink;
  ASSERT_EQ(*allocation.At(0), kColorRed);
  ASSERT_EQ(*allocation.At(1), kColorGreen);
  ASSERT_EQ(*allocation.At(2), kColorBlue);
  ASSERT_EQ(*allocation.At(3), kColorPink);
}

TEST_F(TCRTest, CanCreateTexture) {
  Texture tex;
  ASSERT_TRUE(tex.Resize({2, 2}));
  tex.Fill(kColorRed);
  ASSERT_EQ(*tex.At(0, 0), kColorRed);
  ASSERT_EQ(*tex.At(0, 1), kColorRed);
  ASSERT_EQ(*tex.At(1, 0), kColorRed);
  ASSERT_EQ(*tex.At(1, 1), kColorRed);
}

}  // namespace tcr
