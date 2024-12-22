#pragma once
#include "Direction.hpp"
#include "Executor.hpp"
#include "Point.hpp"

namespace adas
{
class PoseHandler final
{
public:
    PoseHandler(const Pose& pose, Vehicle vehicle) noexcept;
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;

public:
    void Forward() noexcept;
    void Backward() noexcept;
    void TurnRight() noexcept;
    void TurnLeft() noexcept;
    void Fast() noexcept;
    void Reverse() noexcept;
    bool IsReverse() noexcept;
    bool IsFast() const noexcept;
    void Settail() noexcept;
    Pose QueryHead(void) const noexcept;
    Pose QueryTail(void) const noexcept;

public:
    Vehicle vehicle;  // vehicle should be initialized first

private:
    Point head;
    Point tail;
    const Direction* facing;  // facing is const and can be initialized properly
    bool fast{false};
    bool reverse{false};
};
}  // namespace adas
