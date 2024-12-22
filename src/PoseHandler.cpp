#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose, Vehicle _vehicle) noexcept
    : vehicle(_vehicle), head(pose.x, pose.y), tail(pose.x, pose.y), facing(&Direction::GetDirection(pose.heading))
{
    Settail();
}

void PoseHandler::TurnRight() noexcept
{
    facing = &(facing->RightOne());
    Settail();
}

void PoseHandler::TurnLeft() noexcept
{
    facing = &(facing->LeftOne());
    Settail();
}

void PoseHandler::Forward() noexcept
{
    head += facing->Move();
    Settail();
}

void PoseHandler::Backward() noexcept
{
    head -= facing->Move();
    Settail();
}

void PoseHandler::Fast() noexcept
{
    fast = !fast;
}

void PoseHandler::Reverse() noexcept
{
    reverse = !reverse;
}

void PoseHandler::Settail() noexcept
{
    if (vehicle == bus) {
        tail = head + facing->offset();
    } else {
        tail = head;
    }
}

bool PoseHandler::IsReverse() noexcept
{
    return reverse;
}

bool PoseHandler::IsFast() const noexcept
{
    return fast;
}

Pose PoseHandler::QueryHead(void) const noexcept
{
    return Pose(head.GetX(), head.GetY(), facing->GetHeading());
}

Pose PoseHandler::QueryTail(void) const noexcept
{
    return Pose(tail.GetX(), tail.GetY(), facing->GetHeading());
}
}  // namespace adas
