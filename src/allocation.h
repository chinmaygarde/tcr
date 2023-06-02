#pragma once

#include <cstdint>
#include <cstdlib>
#include <type_traits>

#include "fml/macros.h"

namespace tcr {

template <class T, class = std::enable_if_t<std::is_trivially_copyable_v<T>>>
class Allocation {
 public:
  Allocation() {}

  ~Allocation() { [[maybe_unused]] auto result = Truncate(0); }

  [[nodiscard]] bool Truncate(size_t count) {
    if (count_ == count) {
      return true;
    }

    if (count == 0u) {
      std::free(allocation_);
      allocation_ = nullptr;
      count_ = 0u;
      return true;
    }

    auto new_allocation = std::realloc(allocation_, count * sizeof(T));
    if (new_allocation == nullptr) {
      return false;
    }
    allocation_ = new_allocation;
    count_ = count;
    return true;
  }

  constexpr T* At(size_t offset = 0) const {
    return reinterpret_cast<T*>(allocation_) + offset;
  }

  constexpr size_t GetCount() const { return count_; }

  constexpr size_t GetByteSize() const { return GetCount() * sizeof(T); }

 private:
  void* allocation_ = nullptr;
  size_t count_ = 0u;

  FML_DISALLOW_COPY_AND_ASSIGN(Allocation);
};

}  // namespace tcr
