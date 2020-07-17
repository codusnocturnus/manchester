#ifndef QUIESCENTLOSTATE_H_
#define QUIESCENTLOSTATE_H_

#include "encoderstate.hpp"

namespace manchester {

class QuiescentLoState : public EncoderState {
public:
    QuiescentLoState(void) : EncoderState(OutputState::LO, "QUIESCENT (LO)") {}
    virtual ~QuiescentLoState(void) {}

    [[nodiscard]] EncoderState* clock_edge(void) const override;
    [[nodiscard]] EncoderState* new_data(void) const override;
};

}  // namespace manchester

#endif  // QUIESCENTLOSTATE_H_
