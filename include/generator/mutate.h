#ifndef MUTATE_H
#define MUTATE_H

#include <compound_stmts.h>
#include <variable.h>

class Mutation_rule {
    public:
        Mutation_rule(){}

        virtual bool match(const std::shared_ptr<Node> stmts) = 0;

        virtual void apply(std::shared_ptr<Node>& stmts) = 0;

    private:
};

class X_HSSH : public Mutation_rule {
    public:
        X_HSSH():
            Mutation_rule()
        {}

        bool match(const std::shared_ptr<Node> stmts){
            return stmts->find(X) != nullptr;
        }

        void apply(std::shared_ptr<Node>& stmts){
            stmts->add_child(std::make_shared<Variable>("hello child!"));
        }

    private:

};

#endif
