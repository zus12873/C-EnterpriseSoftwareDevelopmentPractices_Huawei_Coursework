#pragma once
#include "ActionGroup.hpp"
#include "PoseHandler.hpp"
namespace adas
{
/*class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperate(PoseHandler& poseHandler)const noexcept = 0;
};*/
class MoveCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto action =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        if (poseHandler.IsFast()) {
            if (poseHandler.vehicle == sport_car) {
                actionGroup.PushAction(action);
            }
            actionGroup.PushAction(action);
        }
        if (poseHandler.vehicle == sport_car) {
            actionGroup.PushAction(action);
        }
        actionGroup.PushAction(action);
        return actionGroup;
    }
};
class TurnLeftCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto moveone =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        if (poseHandler.vehicle == bus) {
            actionGroup.PushAction(moveone);
        }
        if (poseHandler.IsFast()) {
            auto action =
                poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
        }
        auto action = poseHandler.IsReverse() ? ActionType::REVERSE_TURNLEFT_ACTION : ActionType::TURNLEFT_ACTION;
        actionGroup.PushAction(action);
        if (poseHandler.vehicle == sport_car) {
            actionGroup.PushAction(moveone);
        }
        return actionGroup;
    }
};
class TurnRightCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto moveone =
            poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
        if (poseHandler.vehicle == bus) {
            actionGroup.PushAction(moveone);
        }
        if (poseHandler.IsFast()) {
            auto action =
                poseHandler.IsReverse() ? ActionType::BACKWARD_1_STEP_ACTION : ActionType::FORWARD_1_STEP_ACTION;
            actionGroup.PushAction(action);
        }
        auto action = poseHandler.IsReverse() ? ActionType::REVERSE_TURNRIGHT_ACTION : ActionType::TURNRIGHT_ACTION;
        actionGroup.PushAction(action);
        if (poseHandler.vehicle == sport_car) {
            actionGroup.PushAction(moveone);
        }
        return actionGroup;
    }
};
class FastCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto action = ActionType::BE_FAST_ACTION;
        actionGroup.PushAction(action);
        return actionGroup;
    }
};
class ReverseCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        ActionGroup actionGroup;
        const auto action = ActionType::BE_REVERSE_ACTION;
        actionGroup.PushAction(action);
        return actionGroup;
    }
};
class TurnRoundCommand final
{
public:
    ActionGroup operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsReverse())
            return ActionGroup();
        if (poseHandler.IsFast()) {
            return ActionGroup({ActionType::FORWARD_1_STEP_ACTION, ActionType::TURNLEFT_ACTION,
                                ActionType::FORWARD_1_STEP_ACTION, ActionType::TURNLEFT_ACTION});
        }
        return ActionGroup(
            {ActionType::TURNLEFT_ACTION, ActionType::FORWARD_1_STEP_ACTION, ActionType::TURNLEFT_ACTION});
    }
};
}  // namespace adas