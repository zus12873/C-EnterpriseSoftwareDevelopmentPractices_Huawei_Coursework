#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>
#include "Command.hpp"

namespace adas
{
    
    Executor* Executor::NewExecutor(const Pose& pose) noexcept
    {
            return new (std::nothrow) ExecutorImpl(pose);
    }
    ExecutorImpl::ExecutorImpl(const Pose& pose) noexcept : 
    poseHandler(pose)
    {
    }

    void ExecutorImpl::Execute(const std::string& commands) 
    noexcept

    {
        std::unordered_map<char, std::function<void(PoseHandler & poseHandler)>> cmderMap;
         MoveCommand moveCommand;
         cmderMap.emplace('M', moveCommand.operate);
         TurnLeftCommand turnLeftCommand;
         cmderMap.emplace('L', turnLeftCommand.operate);
         TurnRightCommand turnRightCommand;
         cmderMap.emplace('R', turnRightCommand.operate);

         FastCommand fastCommand;
         cmderMap.emplace('F', fastCommand.operate);
         for (const auto cmd : commands)
        {
              const auto it = cmderMap.find(cmd);
              if (it != cmderMap.end())
            {
                   it->second(poseHandler);
                 
            }
            
        }

            // for (const auto cmd : commands){
            //     std::unique_ptr<ICommand> cmder;
           
            // if (cmd == 'M')
            // {
              
            //     cmder = std::make_unique<MoveCommand>();

            // } else if (cmd == 'L') {
             
            //     cmder = std::make_unique<TurnLeftCommand>();

            // } else if (cmd == 'R') {
              
            //     cmder = std::make_unique<TurnRightCommand>();

            // } else if (cmd == 'F') {
            //     cmder = std::make_unique<FastCommand>();
                 
            // }

            // if (cmder)
            // {
            //     cmder->DoOperate(poseHandler);
            //             }
            // }
    }

    Pose ExecutorImpl::Query() const noexcept
    {
        return poseHandler.Query();

    }  // namespace adas
}