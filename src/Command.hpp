#pragma once
#include <functional>
#include "PoseHandler.hpp"

namespace adas{
class MoveCommand final 
//: public ICommand
{
public:
     void operator()(PoseHandler& poseHandler) const noexcept
    {
          if (poseHandler.IsFast())
        {
               poseHandler.Move();  
        }
          poseHandler.Move();
    }
};


  // namespace adas
class TurnRightCommand final 
//: public ICommand
{
public:
public:
     void operator()(PoseHandler& poseHandler) const noexcept

    {
          if (poseHandler.IsFast())
        {
               poseHandler.Move();  
        }
          poseHandler.TurnRight();  
    }

};  // namespace adas

class TurnLeftCommand final //: public ICommand
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.IsFast()) {
            poseHandler.Move();
        }
        poseHandler.TurnLeft();
    }
};
class FastCommand final //: public ICommand
{
public:

    void operator()(PoseHandler& poseHandler) const noexcept

    {
        poseHandler.Fast();
        
    }
};
};