#ifndef QUIESCENTHISTATE_H_
#define QUIESCENTHISTATE_H_

#include "encoderstate.hpp"

namespace manchester {

class QuiescentHiState : public EncoderState {
public:
    QuiescentHiState(void) : EncoderState(OutputState::HI, "QUIESCENT (HI)") {}
    virtual ~QuiescentHiState(void) {}

    [[nodiscard]] virtual EncoderState* clock_edge(void) const override;
    [[nodiscard]] virtual EncoderState* new_data(void) const override;
};

}  // namespace manchester

#endif  // QUIESCENTHISTATE_H_
