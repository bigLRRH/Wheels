template <typename... Inputs>
class Gate
{
public:
    virtual bool operator()(Inputs... inputs) = 0;
};

template <typename... Inputs>
class AndGate : public Gate<Inputs...>
{
public:
    bool operator()(Inputs... inputs) override
    {
        return inputs && ...;
    }
};
template <typename... Inputs>
class OrGate : public Gate<Inputs...>
{
public:
    bool operator()(Inputs... inputs) override
    {
        return inputs || ...;
    }
};

template <typename Input>
class NotGate : public Gate<Input>
{
public:
    bool operator()(Input input) override
    {
        return !input;
    }
};

template <typename... Gates>
class GateChain
{
public:
    GateChain(Gates... gates) : gates(gates...) {}
    template <typename... Inputs>
    bool operator()(Inputs... inputs)
    {
        return call<0, Inputs...>(inputs...);
    }

private:
    template <size_t index, typename... Inputs>
    bool call(Inputs... inputs)
    {
        if constexpr (index == sizeof...(Gates))
        {
            return true;
        }
        else
        {
            auto &gate = std::get<index>(gates);
            auto output = gate(inputs);
            return output && call<index + 1>(inputs);
        }
    }

private:
    std::tuple<Gates...> gates;
};

int main()
{
    AndGate<bool, bool> a(true, true);
    return 0;
}