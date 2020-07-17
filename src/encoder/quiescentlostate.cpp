#include "quiescentlostate.hpp"

#include "quiescenthistate.hpp"

namespace manchester {

[[nodiscard]] EncoderState* QuiescentLoState::clock_edge(void) const {
    return new QuiescentHiState();
}

[[nodiscard]] EncoderState* QuiescentLoState::new_data(void) const {
    return new QuiescentLoState();
}

}  // namespace manchester
