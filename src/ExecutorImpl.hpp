#pragma once 
#include "Executor.hpp"
namespace adas
{
class ExecutorImpl final : public Executor
{
public:
        explicit ExecutorImpl(const Pose& pose) noexcept;
        ~ExecutorImpl() noexcept = default;
        ExecutorImpl(const ExecutorImpl&) = delete;
        ExecutorImpl& operator=(const ExecutorImpl&) = delete;
        void Execute(const std::string& command) noexcept override;
        Pose Query(void) const noexcept override;

private:
        Pose pose;
        void Move(void) noexcept;
        void TurnLeft(void) noexcept;
        void TurnRight(void) noexcept;
        class ICommand

        {
        public :
                virtual ~ICommand() = default;
                virtual void DoOperate(ExecutorImpl & executor) const noexcept = 0;
            
        };

        class MoveCommand final : public ICommand
        {
        public:
            void DoOperate(ExecutorImpl& executor) const noexcept override
            {
                executor.Move();
            }

        };  // namespace adas
        class TurnRightCommand final : public ICommand
        {
        public :
                void DoOperate(ExecutorImpl & executor) const noexcept override
        {
                executor.TurnRight();
                
                
        }

        };  // namespace adas

        class TurnLeftCommand final : public ICommand
        {
        public :
                void DoOperate(ExecutorImpl & executor) const noexcept override
        {
                executor.TurnLeft();

        }

        };  
};
}  // namespace adas 
