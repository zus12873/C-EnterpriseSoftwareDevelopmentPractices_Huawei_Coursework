#include "ActionGroup.hpp"

#include <algorithm>
#include <functional>
#include <vector>
namespace adas
{
class ForwardAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Forward();
    }
};
class BackwardAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Backward();
    }
};
class TurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};
class TurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};
class Reverse_TurnLeftAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnRight();
    }
};
class Reverse_TurnRightAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.TurnLeft();
    }
};
class Be_FastAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Fast();
    }
};
class Be_ReverseAction final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.Reverse();
    }
};
ActionGroup::ActionGroup(const std::list<ActionType>& actions) noexcept : actions(actions)
{
}
void ActionGroup::PushAction(const ActionType ActionType) noexcept
{
    actions.push_back(ActionType);
}
void ActionGroup::DoOperate(PoseHandler& poseHandler) const noexcept
{
    static const std::vector<std::function<void(PoseHandler&)>> actionVec = {
        ForwardAction(),   BackwardAction(),          TurnLeftAction(), Reverse_TurnLeftAction(),
        TurnRightAction(), Reverse_TurnRightAction(), Be_FastAction(),  Be_ReverseAction()};
    std::for_each(actions.begin(), actions.end(), [&poseHandler](const ActionType actionType) mutable noexcept {
        actionVec[static_cast<uint16_t>(actionType)](poseHandler);
    });
}
}  // namespace adas