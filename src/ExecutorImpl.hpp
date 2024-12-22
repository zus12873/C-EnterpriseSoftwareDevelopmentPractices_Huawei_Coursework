#pragma once
#include "Executor.hpp"
#include "PoseHandler.hpp"
namespace adas
{
class Executorlmpl final : public Executor
{
public:
    explicit Executorlmpl(const Pose& pose, const Vehicle vehicle) noexcept;
    ~Executorlmpl() noexcept = default;
    Executorlmpl(const Executorlmpl&) = delete;
    Executorlmpl& operator=(const Executorlmpl&) = delete;

public:
    void Execute(const std::string& command) noexcept override;
    Pose QueryHead(void) const noexcept override;
    Pose QueryTail(void) const noexcept override;

private:
    PoseHandler poseHandler;
};
}  // namespace adas