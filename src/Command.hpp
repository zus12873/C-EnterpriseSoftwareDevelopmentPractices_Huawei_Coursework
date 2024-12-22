#pragma once
#include <functional>
#include "PoseHandler.hpp"

namespace adas{

// class ICommand

// {
// public:
//     virtual ~ICommand() = default;
//     virtual void DoOperate(PoseHandler& poseHandler) const noexcept = 0;
// };

class MoveCommand final 
//: public ICommand
{
public:
//     void DoOperate(PoseHandler& poseHandler) const noexcept override
//     {
//         if (poseHandler.IsFast()) {
//             poseHandler.Move();
//         }
//         poseHandler.Move();
//     }
 const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
      if (poseHandler.IsFast())
    {
           poseHandler.Move();
         
    }
      poseHandler.Move();
    
};


};  // namespace adas
class TurnRightCommand final 
//: public ICommand
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.TurnRight();
    // }
     const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
          if (poseHandler.IsFast())
        {
               poseHandler.Move();
             
        }
          poseHandler.TurnRight();
        
    };

};  // namespace adas

class TurnLeftCommand final //: public ICommand
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override
    // {
    //     if (poseHandler.IsFast()) {
    //         poseHandler.Move();
    //     }
    //     poseHandler.TurnLeft();
    // }
     const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
          if (poseHandler.IsFast())
        {
               poseHandler.Move();
             
        }
          poseHandler.TurnLeft();
        
    };
};
class FastCommand final //: public ICommand
{
public:
    // void DoOperate(PoseHandler& poseHandler) const noexcept override

    // {
    //     poseHandler.Fast();
    // }
     const std::function<void(PoseHandler& poseHandler)> operate = [](PoseHandler& poseHandler) noexcept {
          poseHandler.Fast();
        
    };
};
};