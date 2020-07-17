#include "quiescenthistate.hpp"

#include "quiescentlostate.hpp"

namespace manchester {

[[nodiscard]] EncoderState* QuiescentHiState::clock_edge(void) const {
    return new QuiescentLoState();
}

[[nodiscard]] EncoderState* QuiescentHiState::new_data(void) const {
    /// TODO: this should be StartbitInitState
    return new QuiescentHiState();
}

}  // namespace manchester
