#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

#include "fml/macros.h"

namespace tcr {

using Scalar = float;
using Point = glm::vec3;
using Direction = glm::vec3;

struct Ray {
  Point origin;
  Direction direction;
};

struct Sphere {
  Point center;
  Scalar radius;

  bool Intersects(const Ray& ray) const {
    glm::vec3::value_type interection_distance;
    return glm::intersectRaySphere(ray.origin,                     //
                                   glm::normalize(ray.direction),  //
                                   center,                         //
                                   radius * radius,                //
                                   interection_distance            //
    );
  }
};

}  // namespace tcr
