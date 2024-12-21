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
        class MoveCommand final
        {
        public:
            void DoOperate(ExecutorImpl& executor) const noexcept
            {
                executor.Move();
            }

        };  // namespace adas
        class TurnRightCommand final
        {
        public :
                void DoOperate(ExecutorImpl & executor) const noexcept
        {
                executor.TurnRight();
                
        }

        };  // namespace adas

        class TurnLeftCommand final
        {
        public :
                void DoOperate(ExecutorImpl & executor) const noexcept
        {
                executor.TurnLeft();

        }

        };  
};
}  // namespace adas 
