#include <fmt/core.h>

#include <array>

#include "fsm/actions.hpp"
#include "fsm/statemachine.hpp"

const int bits_per_word = 16;

struct ClockEvent {};
struct NewDataEvent {
    std::array<bool, bits_per_word> data;
};

class QuiescentLo;
class QuiescentHi;
class DataReadyHi;
class DataReadyLo;
class BeginStartbit;
class MidStartbit;
class MidWord;
class EndWord;
class BeginBit;
class MidBit;

class QuiescentLo : public fsm::Will<fsm::On<ClockEvent, fsm::TransitionTo<QuiescentHi>>,
                                     fsm::On<NewDataEvent, fsm::TransitionTo<DataReadyLo>>> {};

class QuiescentHi : public fsm::Will<fsm::On<ClockEvent, fsm::TransitionTo<QuiescentLo>>,
                                     fsm::On<NewDataEvent, fsm::TransitionTo<DataReadyHi>>> {};

class DataReadyHi
: public fsm::Will<fsm::ByDefault<fsm::Nothing>, fsm::On<ClockEvent, fsm::TransitionTo<DataReadyLo>>> {};

class DataReadyLo
: public fsm::Will<fsm::ByDefault<fsm::Nothing>, fsm::On<ClockEvent, fsm::TransitionTo<BeginStartbit>>> {};

class BeginStartbit
: public fsm::Will<fsm::ByDefault<fsm::Nothing>, fsm::On<ClockEvent, fsm::TransitionTo<MidStartbit>>> {};

class MidStartbit : public fsm::Will<fsm::ByDefault<fsm::Nothing>, fsm::On<ClockEvent, fsm::TransitionTo<BeginBit>>> {};

class BeginBit : public fsm::Will<fsm::ByDefault<fsm::Nothing>, fsm::On<ClockEvent, fsm::TransitionTo<MidBit>>> {};

int main(int argc, char* argv[]) {
    return 0;
}
