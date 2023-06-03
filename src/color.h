#pragma once

#include <cstdint>
#include <cstdlib>

#include "fml/macros.h"

namespace tcr {

struct Color {
  union {
    uint32_t value;
    struct {
      uint8_t blue;
      uint8_t green;
      uint8_t red;
      uint8_t alpha;
    };
  };

  constexpr Color() : Color(0u) {}

  constexpr Color(uint32_t p_value) : value(p_value) {}

  constexpr Color(uint8_t p_red,
                  uint8_t p_green,
                  uint8_t p_blue,
                  uint8_t p_alpha)
      : blue(p_blue), green(p_green), red(p_red), alpha(p_alpha) {}

  static Color Rand() {
    return Color{static_cast<uint8_t>(std::rand() % 255),
                 static_cast<uint8_t>(std::rand() % 255),
                 static_cast<uint8_t>(std::rand() % 255), 255};
  }

  constexpr bool operator==(const Color& o) const { return o.value == value; }
};

static_assert(sizeof(Color) == sizeof(uint32_t), "");

constexpr auto kColorAliceBlue = Color{0xFFF0F8FF};
constexpr auto kColorAntiqueWhite = Color{0xFFFAEBD7};
constexpr auto kColorAqua = Color{0xFF00FFFF};
constexpr auto kColorAquamarine = Color{0xFF7FFFD4};
constexpr auto kColorAzure = Color{0xFFF0FFFF};
constexpr auto kColorBeige = Color{0xFFF5F5DC};
constexpr auto kColorBisque = Color{0xFFFFE4C4};
constexpr auto kColorBlack = Color{0xFF000000};
constexpr auto kColorBlanchedAlmond = Color{0xFFFFEBCD};
constexpr auto kColorBlue = Color{0xFF0000FF};
constexpr auto kColorBlueViolet = Color{0xFF8A2BE2};
constexpr auto kColorBrown = Color{0xFFA52A2A};
constexpr auto kColorBurlyWood = Color{0xFFDEB887};
constexpr auto kColorCadetBlue = Color{0xFF5F9EA0};
constexpr auto kColorChartreuse = Color{0xFF7FFF00};
constexpr auto kColorChocolate = Color{0xFFD2691E};
constexpr auto kColorCoral = Color{0xFFFF7F50};
constexpr auto kColorCornflowerBlue = Color{0xFF6495ED};
constexpr auto kColorCornsilk = Color{0xFFFFF8DC};
constexpr auto kColorCrimson = Color{0xFFDC143C};
constexpr auto kColorCyan = Color{0xFF00FFFF};
constexpr auto kColorDarkBlue = Color{0xFF00008B};
constexpr auto kColorDarkCyan = Color{0xFF008B8B};
constexpr auto kColorDarkGoldenRod = Color{0xFFB8860B};
constexpr auto kColorDarkGray = Color{0xFFA9A9A9};
constexpr auto kColorDarkGrey = Color{0xFFA9A9A9};
constexpr auto kColorDarkGreen = Color{0xFF006400};
constexpr auto kColorDarkKhaki = Color{0xFFBDB76B};
constexpr auto kColorDarkMagenta = Color{0xFF8B008B};
constexpr auto kColorDarkOliveGreen = Color{0xFF556B2F};
constexpr auto kColorDarkorange = Color{0xFFFF8C00};
constexpr auto kColorDarkOrchid = Color{0xFF9932CC};
constexpr auto kColorDarkRed = Color{0xFF8B0000};
constexpr auto kColorDarkSalmon = Color{0xFFE9967A};
constexpr auto kColorDarkSeaGreen = Color{0xFF8FBC8F};
constexpr auto kColorDarkSlateBlue = Color{0xFF483D8B};
constexpr auto kColorDarkSlateGray = Color{0xFF2F4F4F};
constexpr auto kColorDarkSlateGrey = Color{0xFF2F4F4F};
constexpr auto kColorDarkTurquoise = Color{0xFF00CED1};
constexpr auto kColorDarkViolet = Color{0xFF9400D3};
constexpr auto kColorDeepPink = Color{0xFFFF1493};
constexpr auto kColorDeepSkyBlue = Color{0xFF00BFFF};
constexpr auto kColorDimGray = Color{0xFF696969};
constexpr auto kColorDimGrey = Color{0xFF696969};
constexpr auto kColorDodgerBlue = Color{0xFF1E90FF};
constexpr auto kColorFireBrick = Color{0xFFB22222};
constexpr auto kColorFloralWhite = Color{0xFFFFFAF0};
constexpr auto kColorForestGreen = Color{0xFF228B22};
constexpr auto kColorFuchsia = Color{0xFFFF00FF};
constexpr auto kColorGainsboro = Color{0xFFDCDCDC};
constexpr auto kColorGhostWhite = Color{0xFFF8F8FF};
constexpr auto kColorGold = Color{0xFFFFD700};
constexpr auto kColorGoldenRod = Color{0xFFDAA520};
constexpr auto kColorGray = Color{0xFF808080};
constexpr auto kColorGrey = Color{0xFF808080};
constexpr auto kColorGreen = Color{0xFF008000};
constexpr auto kColorGreenYellow = Color{0xFFADFF2F};
constexpr auto kColorHoneyDew = Color{0xFFF0FFF0};
constexpr auto kColorHotPink = Color{0xFFFF69B4};
constexpr auto kColorIndianRed = Color{0xFFCD5C5C};
constexpr auto kColorIndigo = Color{0xFF4B0082};
constexpr auto kColorIvory = Color{0xFFFFFFF0};
constexpr auto kColorKhaki = Color{0xFFF0E68C};
constexpr auto kColorLavender = Color{0xFFE6E6FA};
constexpr auto kColorLavenderBlush = Color{0xFFFFF0F5};
constexpr auto kColorLawnGreen = Color{0xFF7CFC00};
constexpr auto kColorLemonChiffon = Color{0xFFFFFACD};
constexpr auto kColorLightBlue = Color{0xFFADD8E6};
constexpr auto kColorLightCoral = Color{0xFFF08080};
constexpr auto kColorLightCyan = Color{0xFFE0FFFF};
constexpr auto kColorLightGoldenRodYellow = Color{0xFFFAFAD2};
constexpr auto kColorLightGray = Color{0xFFD3D3D3};
constexpr auto kColorLightGrey = Color{0xFFD3D3D3};
constexpr auto kColorLightGreen = Color{0xFF90EE90};
constexpr auto kColorLightPink = Color{0xFFFFB6C1};
constexpr auto kColorLightSalmon = Color{0xFFFFA07A};
constexpr auto kColorLightSeaGreen = Color{0xFF20B2AA};
constexpr auto kColorLightSkyBlue = Color{0xFF87CEFA};
constexpr auto kColorLightSlateGray = Color{0xFF778899};
constexpr auto kColorLightSlateGrey = Color{0xFF778899};
constexpr auto kColorLightSteelBlue = Color{0xFFB0C4DE};
constexpr auto kColorLightYellow = Color{0xFFFFFFE0};
constexpr auto kColorLime = Color{0xFF00FF00};
constexpr auto kColorLimeGreen = Color{0xFF32CD32};
constexpr auto kColorLinen = Color{0xFFFAF0E6};
constexpr auto kColorMagenta = Color{0xFFFF00FF};
constexpr auto kColorMaroon = Color{0xFF800000};
constexpr auto kColorMediumAquaMarine = Color{0xFF66CDAA};
constexpr auto kColorMediumBlue = Color{0xFF0000CD};
constexpr auto kColorMediumOrchid = Color{0xFFBA55D3};
constexpr auto kColorMediumPurple = Color{0xFF9370D8};
constexpr auto kColorMediumSeaGreen = Color{0xFF3CB371};
constexpr auto kColorMediumSlateBlue = Color{0xFF7B68EE};
constexpr auto kColorMediumSpringGreen = Color{0xFF00FA9A};
constexpr auto kColorMediumTurquoise = Color{0xFF48D1CC};
constexpr auto kColorMediumVioletRed = Color{0xFFC71585};
constexpr auto kColorMidnightBlue = Color{0xFF191970};
constexpr auto kColorMintCream = Color{0xFFF5FFFA};
constexpr auto kColorMistyRose = Color{0xFFFFE4E1};
constexpr auto kColorMoccasin = Color{0xFFFFE4B5};
constexpr auto kColorNavajoWhite = Color{0xFFFFDEAD};
constexpr auto kColorNavy = Color{0xFF000080};
constexpr auto kColorOldLace = Color{0xFFFDF5E6};
constexpr auto kColorOlive = Color{0xFF808000};
constexpr auto kColorOliveDrab = Color{0xFF6B8E23};
constexpr auto kColorOrange = Color{0xFFFFA500};
constexpr auto kColorOrangeRed = Color{0xFFFF4500};
constexpr auto kColorOrchid = Color{0xFFDA70D6};
constexpr auto kColorPaleGoldenRod = Color{0xFFEEE8AA};
constexpr auto kColorPaleGreen = Color{0xFF98FB98};
constexpr auto kColorPaleTurquoise = Color{0xFFAFEEEE};
constexpr auto kColorPaleVioletRed = Color{0xFFD87093};
constexpr auto kColorPapayaWhip = Color{0xFFFFEFD5};
constexpr auto kColorPeachPuff = Color{0xFFFFDAB9};
constexpr auto kColorPeru = Color{0xFFCD853F};
constexpr auto kColorPink = Color{0xFFFFC0CB};
constexpr auto kColorPlum = Color{0xFFDDA0DD};
constexpr auto kColorPowderBlue = Color{0xFFB0E0E6};
constexpr auto kColorPurple = Color{0xFF800080};
constexpr auto kColorRed = Color{0xFFFF0000};
constexpr auto kColorRosyBrown = Color{0xFFBC8F8F};
constexpr auto kColorRoyalBlue = Color{0xFF4169E1};
constexpr auto kColorSaddleBrown = Color{0xFF8B4513};
constexpr auto kColorSalmon = Color{0xFFFA8072};
constexpr auto kColorSandyBrown = Color{0xFFF4A460};
constexpr auto kColorSeaGreen = Color{0xFF2E8B57};
constexpr auto kColorSeaShell = Color{0xFFFFF5EE};
constexpr auto kColorSienna = Color{0xFFA0522D};
constexpr auto kColorSilver = Color{0xFFC0C0C0};
constexpr auto kColorSkyBlue = Color{0xFF87CEEB};
constexpr auto kColorSlateBlue = Color{0xFF6A5ACD};
constexpr auto kColorSlateGray = Color{0xFF708090};
constexpr auto kColorSlateGrey = Color{0xFF708090};
constexpr auto kColorSnow = Color{0xFFFFFAFA};
constexpr auto kColorSpringGreen = Color{0xFF00FF7F};
constexpr auto kColorSteelBlue = Color{0xFF4682B4};
constexpr auto kColorTan = Color{0xFFD2B48C};
constexpr auto kColorTeal = Color{0xFF008080};
constexpr auto kColorThistle = Color{0xFFD8BFD8};
constexpr auto kColorTomato = Color{0xFFFF6347};
constexpr auto kColorTurquoise = Color{0xFF40E0D0};
constexpr auto kColorViolet = Color{0xFFEE82EE};
constexpr auto kColorWheat = Color{0xFFF5DEB3};
constexpr auto kColorWhite = Color{0xFFFFFFFF};
constexpr auto kColorWhiteSmoke = Color{0xFFF5F5F5};
constexpr auto kColorYellow = Color{0xFFFFFF00};
constexpr auto kColorYellowGreen = Color{0xFF9ACD32};

}  // namespace tcr
