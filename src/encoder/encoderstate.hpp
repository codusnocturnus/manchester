#ifndef ENCODERSTATE_H_
#define ENCODERSTATE_H_

#include <memory>
#include <string>

namespace manchester {

enum class OutputState { NONE, LO, HI };

class EncoderState {
public:
    virtual ~EncoderState(void) = default;

    // public interface
    [[nodiscard]] virtual EncoderState* clock_edge(void) const = 0;
    [[nodiscard]] virtual EncoderState* new_data(void) const = 0;

    const OutputState output;
    const std::string name;

protected:
    EncoderState(const OutputState out, const std::string myname) : output(out), name(myname){};
};

}  // namespace manchester

#endif  // ENCODERSTATE_H_
