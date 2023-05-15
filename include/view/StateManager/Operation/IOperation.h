#pragma once
class IOperation {
    public:
        virtual ~IOperation() = default;
        virtual void execute() = 0;
        virtual void undo() = 0;
};
