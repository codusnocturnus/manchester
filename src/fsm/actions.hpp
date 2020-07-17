#pragma once

#include <variant>

namespace fsm {

template <typename Action>
struct ByDefault {
    template <typename Event>
    Action handle(const Event&) const {
        return Action{};
    }
};

template <typename... Actions>
class OneOf {
public:
    template <typename T>
    OneOf(T&& arg) : options(std::forward<T>(arg)) {}

    template <typename Machine, typename State, typename Event>
    void execute(Machine& machine, State& state, const Event& event) {
        std::visit([&machine, &state, &event](auto& action) { action.execute(machine, state, event); }, options);
    }

private:
    std::variant<Actions...> options;
};

template <typename Action>
struct Maybe : public OneOf<Action, Nothing> {
    using OneOf<Action, Nothing>::OneOf;
};

struct Nothing {
    template <typename Machine, typename State, typename Event>
    void execute(Machine&, State&, const Event&) {}
};

template <typename Event, typename Action>
struct On {
    Action handle(const Event&) const { return {}; }
};

template <typename TargetState>
class TransitionTo {
public:
    template <typename Machine, typename State, typename Event>
    void execute(Machine& machine, State& prevState, const Event& event) {
        leave(prevState, event);
        TargetState& newState = machine.template transitionTo<TargetState>();
        enter(newState, event);
    }

private:
    void leave(...) {}

    template <typename State, typename Event>
    auto leave(State& state, const Event& event) -> decltype(state.onLeave(event)) {
        return state.onLeave(event);
    }

    void enter(...) {}

    template <typename State, typename Event>
    auto enter(State& state, const Event& event) -> decltype(state.onEnter(event)) {
        return state.onEnter(event);
    }
};

template <typename... Handlers>
struct Will : Handlers... {
    using Handlers::handle...;
};

}  // namespace fsm
