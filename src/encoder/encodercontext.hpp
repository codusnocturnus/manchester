#ifndef ENCODERCONTEXT_H_
#define ENCODERCONTEXT_H_

#include <memory>
#include <string_view>

#include "quiescenthistate.hpp"

namespace manchester {

class EncoderContext {
public:
    EncoderContext(EncoderState* init = new QuiescentHiState()) : pstate_(std::unique_ptr<EncoderState>(init)) {}

    void clock_edge(void) { pstate_.reset(pstate_->clock_edge()); }
    void new_data(void) { pstate_.reset(pstate_->new_data()); }
    std::string_view statename(void) { return pstate_->name; }

private:
    std::unique_ptr<EncoderState> pstate_;
};

}  // namespace manchester

#endif  // ENCODERCONTEXT_H_
